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

void		ft_operations_arr(t_swap *po, int *arr)
{
	int tmp;
	int i;

	tmp = arr[0];
	i = 0;
	while (i < po->sizeb - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = tmp;
}

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

int 		checkrotet(t_swap *po)
{
	int i;
	int mid;


	i = 0;
	mid = (po->sizea - 1) / 2;
	while (i < po->sizea)
	{
//		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
//		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[i]) || (po->arra[po->sizea - 1] > po->arrb[0] && po->arra[i] < po->arrb[0]))
		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
			break ;
		i++;
	}
	if (i >= mid)
		return (1);
	return (0);
}

int 		checkrotet_b(t_swap *po)
{
	int i;
	int mid;


	i = 0;
	mid = (po->sizea - 1) / 2;
	while (i < po->sizea)
	{
//		if ((po->arra[0] < po->arrb[i] && po->arra[0] > po->arrb[i + 1]) || (po->arra[0] > po->arrb[i] && po->arra[po->sizea - 1] < po->arrb[0]))
//		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[i]) || (po->arra[po->sizea - 1] > po->arrb[0] && po->arra[i] < po->arrb[0]))
		if ((po->arra[0] < po->arrb[i] && po->arra[0] > po->arrb[i + 1]) || (po->arra[0] > po->arrb[i] && po->arra[po->sizea - 1] < po->arrb[0]))
			break ;
		i++;
	}
	if (i >= mid)
		return (1);
	return (0);
}

/////////////////////////////////////////test
void 		checkrotetb(t_swap *po)
{
	int i;
	int j;
	int try;
	int *arr;
	int a;
	int b;
	int k;

	k = 0;
	arr = (int*)malloc(sizeof(int) * po->sizeb);
	i = 0;
	try = 0;
	j = 0;
	a = 0;
	b = 0;
//	while (i < po->sizea)
//	{
//		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
//			break ;
//		i++;
//	}
//	a = i;
//	i = 0;
//	while (i < po->sizeb)
//	{
////		if ((po->arrb[i] > po->arra[0] && po->arrb[i + 1] < po->arra[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
//		if (po->arra[0] > po->arrb[i] && po->arra[po->sizea - 1] < po->arrb[i] && po->sizeb > 0)
//		{
//			try = 1;
//			break;
//		}
//		i++;
//	}
//	b = i;
	while (i < po->sizeb - 1)
	{
		while (j < po->sizea - 1)
		{
			if ((po->arra[j] < po->arrb[i] && po->arra[j + 1] > po->arrb[i])  || (po->arra[po->sizea - 1] > po->arrb[i] && po->arra[0] < po->arrb[i]))
			{
				if (i < po->sizeb / 2 && j < po->sizea && po->sizeb >= 2)
				{
					arr[i] = j + i;
					break ;
				}
				else if (po->sizeb / 2 <= i) //(po->sizeb > i)
				{
					arr[i] = po->sizeb - i;
					break ;
				}
				else {
					arr[i] = j + i;
					break;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	a = arr[0];
	b = 0;
	while (k < po->sizeb)
	{
		if (arr[k] + k <  a + b)
		{
			a = arr[k];
			b = k;
		}
			k++;
	}
	if (b <= a)
	{
		if ((j <= po->sizeb / 2)) //(j < po->sizeb / 2)
		{
			while (b != 0) {
				if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
					ft_operations_pa(po, 0);
					return;
//			print_swap(po);
				}
				if (a != 0 && b != 0)
				{
					ft_operations_rr(po);
					b--;
					a--;
				}
				else
					{
					ft_operations_rb(po);
					b--;
				}
//				a--;
			}
			if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
				ft_operations_pa(po, 0);
				return;
			}
		}
		else
		{
			while (b != 0) {
				if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
					ft_operations_pa(po, 0);
					return;
//			print_swap(po);
				}
				if (a != 0 && b != 0) {
					ft_operations_rrr(po);
					b--;
					a--;
				} else {
					ft_operations_rrb(po);
					b--;
				}
//				a--;
			}
			if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
				ft_operations_pa(po, 0);
				return;
			}
		}
	}
		if (checkrotet(po) == 1)
		{
			while (po->sizeb != 0)
			{
				if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
					ft_operations_pa(po, 0);
					return;
//			print_swap(po);
				}
				ft_operations_rra(po);
			}
		} else {
			while (po->sizeb != 0)
			{
				if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0) {
					ft_operations_pa(po, 0);
					return;
//			print_swap(po);
				}
				ft_operations_ra(po);
			}

		}
//	}
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
	if (checksort(po) == 0)
		return ;
	while (po->sizea != 3)
	{
		if (po->arra[i] != min && po->arra[i] != max)
		{
			ft_operations_pb(po);
//			print_swap(po);
			i--;
		}
		else
		{
//			if ((po->arra[i] != max && po->arra[i + 1] != min) || (po->arra[i] != min && po->arra[i + 1] != max) || (po->arra[i + 2] != min || po->arra[i + 2] != max) || (po->arra[i + 1] != min || po->arra[i + 1] != max))
			if ((po->arra[i] != min || po->arra[i] != max) && (po->arra[i + 1] != min || po->arra[i + 1] != max) && (po->arra[i + 3] != min || po->arra[i + 3] != max))
				while (po->sizea != 3)
				{
					if (po->arra[i] != min && po->arra[i] != max)
					{
						ft_operations_pb(po);
						i--;
					}
					else {
						ft_operations_ra(po);
						i--;
					}
					i++;
				}
			else
				ft_operations_ra(po);
			i--;
		}
		i++;
	}
	i = 0;
	if (po->arra[0] == min && po->arra[1] == max)
		ft_operations_sa(po);
	if (po->arra[0] == max && po->arra[2] == min)
	{
		ft_operations_sa(po);
	}
	if (po->arra[1] == min && po->arra[2] == max)
		ft_operations_sa(po);
	while (po->sizeb != 0) {
//		if (po->arra[0] == max && po->arra[2] == min) {
//			ft_operations_sa(po);
////			print_swap(po);
//		}
		if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
		{
			ft_operations_pa(po, 0);
//			print_swap(po);
		}
			else
			checkrotetb(po);
	}
	while (po->arra[0] != min)
	{
		if (po->arra[0] == min)
		{
//		print_swap(po);
			break ;
		}
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
//			print_swap(po);
		}
		i++;
	}
}