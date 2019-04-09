/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:15:14 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 18:23:18 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		ft_sort(t_swap *po)
{
	search_min_max(po);
	if (checksort(po) == 0)
		return ;
	while (po->sizea != 3 && po->sizea > 3)
	{
		if (po->arra[0] != po->min && po->arra[0] != po->max)
			ft_operations_pb(po);
		else
			ft_operations_ra(po);
	}
	if (po->arra[0] == po->min && po->arra[1] == po->max)
		ft_operations_sa(po);
	if (po->arra[0] == po->max && po->arra[2] == po->min)
		ft_operations_sa(po);
	if (po->arra[1] == po->min && po->arra[2] == po->max)
		ft_operations_sa(po);
	while (po->sizeb != 0)
	{
		if (po->arra[0] > po->arrb[0] &&
			po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			ft_operations_pa(po, 0);
		else
			rotet_b_rr(po);
	}
	final_sort(po);
}

void		final_sort(t_swap *po)
{
	while (po->arra[0] != po->min)
	{
		if (po->arra[0] == po->min)
			break ;
		else
		{
			if (checkr(po, po->min) == 0)
			{
				while (po->arra[0] != po->min)
					ft_operations_ra(po);
			}
			else
			{
				while (po->arra[0] != po->min)
				{
					ft_operations_rra(po);
				}
			}
		}
	}
}
