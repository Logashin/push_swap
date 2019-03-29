/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:34:35 by tmann             #+#    #+#             */
/*   Updated: 2019/03/29 21:34:43 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		ft_operations_sa(t_swap *po)
{
	if (po->sizea < 1)
		return ;
	ft_swap(&po->arra[0], &po->arra[1]);
	ft_printf("sa\n");
}

void		ft_operations_sb(t_swap *po)
{
	if (po->sizeb < 1)
		return ;
	ft_swap(&po->arrb[0], &po->arrb[1]);
	ft_printf("sb\n");
}

void		ft_operations_ss(t_swap *po)
{
	if (po->sizea > 1)
		return ;
	if (po->sizeb > 1)
		return ;
	ft_swap(&po->arra[0], &po->arra[1]);
	ft_swap(&po->arrb[0], &po->arrb[1]);
	ft_printf("ss\n");
}

void		ft_operations_rrr(t_swap *po)
{
	ft_operations_rra(po);
	ft_operations_rrb(po);
}

void		ft_operations_rr(t_swap *po)
{
	ft_operations_ra(po);
	ft_operations_rb(po);
}
