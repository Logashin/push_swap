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

int 		checkrotet(t_swap *po)
{
	int i;
	int mid;
//	int *arr;
//
//	arr = malloc(po->sizea);
//	arr = po->arra;
	i = 0;
	mid = (po->sizea - 1) / 2;
	while (i < po->sizeb)
	{
		if ((po->arra[i] < po->arrb[0] && po->arra[i + 1] > po->arrb[0]) || (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0]))
			break ;
			i++;
	}
	if (i >= mid)
		return (1);
	return (0);
}

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
			if ((po->arra[i] == max && po->arra[i + 1] == min) || (po->arra[i] == min && po->arra[i + 1] == max) || (po->arra[i + 2] == min || po->arra[i + 2] == max))
				while (po->sizea != 3)
				{
					if (po->arra[i] != min && po->arra[i] != max)
					{
						ft_operations_pb(po);
						i--;
					}
					else {
						ft_operations_rra(po);
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
	while (po->sizeb != 0)
	{
		if (po->arra[0] == max && po->arra[2] == min)
		{
			ft_operations_sa(po);
//			print_swap(po);
		}
		if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
		{
			ft_operations_pa(po, 0);
//			print_swap(po);
		}
		else
		{
//			if (checkr(po, max) == 1)
			if (checkrotet(po) == 1)
			{
				while (po->sizeb != 0)
				{
					ft_operations_rra(po);
					if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0])
					{
						if (po->arra[0] == max && po->arra[2] == min)
						{
							ft_operations_sa(po);
							break ;
//			print_swap(po);
						}
						if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
						{
							ft_operations_pa(po, 0);
//						print_swap(po);
						break ;
						}
					}
				}
			}
//			else if (po->arrb[0] > po->arrb[1] && po->arra[0] < po->arra[1] && po->sizeb > 1)
//				ft_operations_sb(po);
			else
				while (po->sizeb != 0)
				{
					if (po->arra[0] > po->arrb[0] && po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
					{
						ft_operations_pa(po, 0);
						break ;
//			print_swap(po);
					}
					ft_operations_ra(po);
				}
//			print_swap(po);
		}
	}
	i = 0;
	while (i < po->sizea)
	{
		if (po->arra[0] == min)
		{
//		print_swap(po);
			break ;
		}
		else
		{
//			if (checkr(po, min) == 0)
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