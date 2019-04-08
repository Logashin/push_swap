/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:15:14 by tmann             #+#    #+#             */
/*   Updated: 2019/04/01 13:15:20 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int			ft_max(t_swap *po, int stop)
{
	int i;
	int max;

	max = po->arra[0];
	i = 0;
	while (i < po->sizea)
	{
		if (max < po->arra[i] && po->arra[i] != stop)
			max = po->arra[i];
		i++;
	}
	return (max);
}

int			checksort(t_swap *po)
{
	int i;

	i = 0;
	while (i < po->sizea - 1)
	{
		if (po->arra[i] > po->arra[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int			checkr(t_swap *po, int min)
{
	int i;

	i = 0;
	while (i <= (po->sizea - 1) / 2)
	{
		if (po->arra[i] == min)
			return (0);
		i++;
	}
	return (1);
}

//int 		checkrotet(t_swap *po)
//{
//	int i;
//	int mid;
//
//
//	i = 0;
//	mid = (po->sizea) / 2;
//	while (i < po->sizea - 1)
//	{
////		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
////		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[i]) || (po->arra[po->sizea - 1] > po->arrb[0] && po->arra[i] < po->arrb[0]))
//		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
//			break ;
//		i++;
//	}
//	if (i >= mid)
//		return (1);
//	return (0);
//}

//int 		checkrotet_b(t_swap *po)
//{
//	int i;
//	int mid;
//
//
//	i = 0;
//	mid = (po->sizea - 1) / 2;
//	while (i < po->sizea - 1)
//	{
////		if ((po->arra[0] < po->arrb[i] && po->arra[0] > po->arrb[i + 1]) || (po->arra[0] > po->arrb[i] && po->arra[po->sizea - 1] < po->arrb[0]))
////		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[i]) || (po->arra[po->sizea - 1] > po->arrb[0] && po->arra[i] < po->arrb[0]))
//		if ((po->arra[0] < po->arrb[i] && po->arra[0] > po->arrb[i + 1]) || (po->arra[0] > po->arrb[i] && po->arra[po->sizea - 1] < po->arrb[0]))
//			break ;
//		i++;
//	}
//	if (i >= mid)
//		return (1);
//	return (0);
//}

void	ft_zerostruct(t_count *co)
{
	co->a = 0;
	co->b = 0;
	//co->res = 999999;
	co->wa = 0;
	co->wb = 0;
}

void 	ft_index(t_swap *po, int b, t_count *co)
{
	int i;

	i = 0;
	while (po->sizea > i)
	{
		if ((po->arra[i] < po->arrb[b] && po->arra[i + 1] > po->arrb[b]))
		{
			if (po->arra[0] > po->arrb[b] && po->arra[po->sizea - 1] < po->arrb[b])
				co->a = 0;
			else if ((po->sizea - 1) / 2 >= i + 1)
			{
				co->wa = 1;
				co->a = i + 1;
			}
			else
			{
				co->wa = 2;
				co->a = (po->sizea - 1) - i;
			}
			break ;
		}
		i++;
	}
}

int		top_res(int res, t_count *co)
{
	int save;

	save = 0;
	if (co->a > 0 && co->b > 0)
	{
		save = (co->a < co->b) ? co->b - co->a : co->a - co->b;
		if (co->a > co->b)
			res = save + co->b;
		else if (co->a < co->b)
			res = save + co->a;
		else
			res = co->a;
	}
	else
	{
			res = co->a + co->b;
	}
	return (res);
}

void		ft_count_b(t_count *co, t_swap *po, int i)
{
	if (po->sizeb / 2 >= i)
	{
		co->wb = 1;
		co->b = i;
	}
	else
	{
		co->wb = 2;
		co->b = po->sizeb - i;
	}
}

t_count		*count_command(t_swap *po)
{
	t_count *co;
	int i;
	int check;
	int b;

	i = 0;
	b = 0;
	check = 999999;
	co = (t_count*)malloc(sizeof(t_count));
	while (po->sizeb > i)
	{
		ft_zerostruct(co);
		ft_index(po, i, co);
		ft_count_b(co, po, i);
		co->res = top_res(co->res, co);
		if (check > co->res)
		{
			check = co->res;
			b = i;
		}
		i++;
	}
	ft_zerostruct(co);
	ft_index(po, b, co);
	ft_count_b(co, po, b);
	return (co);
}

/////////////////////////////////////////test
void 		checkrotetb(t_swap *po)
{
	t_count *co;
	co = count_command(po);
	if (co->wa == 1 && co->wb == 1 && co->a > 0 && co->b > 0)
	{
		while (co->a != 0 && co->b != 0)
		{
			if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return;
			}
			else if (co->a != 0 || co->b != 0)
			{
				ft_operations_rr(po);
				co->b--;
				co->a--;
			}
			else
				break ;
		}
		if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
		{
			ft_operations_pa(po, 0);
			return;
		}

	}
	if (co->wa == 2 && co->wb == 2 && co->a > 0 && co->b > 0)
	{
		while (co->a != 0 && co->b != 0)
		{

			if (co->a != 0 || co->b != 0)
			{
				ft_operations_rrr(po);
				co->b--;
				co->a--;
			}
			else if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return;
			}
			else
				break ;
		}
	}
	if (co->b > 0 && co->wb == 1)
	{
		while (co->b != 0)
		{
			ft_operations_rb(po);
			co->b--;
			if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return;
			}
		}
	}
	if (co->b > 0 && co->wb == 2)
	{
		while (co->b != 0)
		{
			ft_operations_rrb(po);
			co->b--;
			if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {

				ft_operations_pa(po, 0);
				return;

			}
		}
		if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
			ft_operations_pa(po, 0);
			return;
		}
	}
		if (co->wa == 2)
		{
			while (po->sizeb != 0)
			{
				if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
				{
					ft_operations_pa(po, 0);
					return;
				}
				ft_operations_rra(po);
			}
		}
		else
			{
				while (po->sizeb != 0)
				{
					if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
					{
						ft_operations_pa(po, 0);
						return;
					}
					ft_operations_ra(po);
				}
			}
}
//////////////////////////////////////////////////////ALG
void		ft_sort(t_swap *po)
{
	int i;
	int min;
	int max;

	i = 0;
	min = po->arra[0];
	max = po->arra[0];
	while (i < po->sizea)
	{
		if (min > po->arra[i])
			min = po->arra[i];
		i++;
	}
//	ft_printf("min: %d\n", min);
	i = 0;
	while (i < po->sizea)
	{
		if (max < po->arra[i])
			max = po->arra[i];
		i++;
	}
	i = 0;
	po->max = max;
	po->min = min;
	if (checksort(po) == 0)
		return ;
	while (po->sizea != 3)
	{
		if (po->arra[0] != min && po->arra[0] != max)
		{
			ft_operations_pb(po);
//			print_swap(po);
			i--;
		}
//		else
//		{
////			if ((po->arra[i] != max && po->arra[i + 1] != min) || (po->arra[i] != min && po->arra[i + 1] != max) || (po->arra[i + 2] != min || po->arra[i + 2] != max) || (po->arra[i + 1] != min || po->arra[i + 1] != max))
//			if ((po->arra[0] != min || po->arra[0] != max) && (po->arra[0 + 1] != min || po->arra[0 + 1] != max) && (po->arra[0 + 2] != min || po->arra[0 + 2] != max))
//				while (po->sizea != 3)
//				{
//					if (po->arra[0] != min && po->arra[0] != max)
//					{
//						ft_operations_pb(po);
//					}
//					else {
//						ft_operations_rra(po);
//					}
//				}
			else
				ft_operations_ra(po);
//		}
	}
	i = 0;
	if (po->arra[0] == min && po->arra[1] == max)
		ft_operations_sa(po);
	if (po->arra[0] == max && po->arra[2] == min)
		ft_operations_sa(po);
	if (po->arra[1] == min && po->arra[2] == max)
		ft_operations_sa(po);
	while (po->sizeb != 0)
	{
		if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			ft_operations_pa(po, 0);
		else
			checkrotetb(po);
	}
	while (po->arra[0] != min)
	{
		if (po->arra[0] == min)
			break ;
		else
		{
			if (checkr(po, min) == 0)
			{
				while (po->arra[0] != min)
				{
					ft_operations_ra(po);
				}
			}
			else
			{
				while (po->arra[0] != min)
				{
					ft_operations_rra(po);
				}
			}
		}
	}
}