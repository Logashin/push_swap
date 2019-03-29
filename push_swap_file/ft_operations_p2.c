/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:20:56 by tmann             #+#    #+#             */
/*   Updated: 2019/03/29 19:21:03 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		ft_operations_rra(t_swap *po)
{
	int tmp;
	int i;

	tmp = po->arra[po->sizea - 1];
	i = po->sizea;
	while (i > 0)
	{
		po->arra[i] = po->arra[i - 1];
		i--;
	}
	po->arra[i] = tmp;
	ft_printf("ra\n");
}

void		ft_operations_rrb(t_swap *po)
{
	int tmp;
	int i;

	tmp = po->arrb[po->sizeb - 1];
	i = po->sizeb;
	while (i > 0)
	{
		po->arrb[i] = po->arrb[i - 1];
		i--;
	}
	po->arrb[i] = tmp;
	ft_printf("rb\n");
}

void		ft_operations_ra(t_swap *po)
{
	int tmp;
	int i;

	tmp = po->arra[0];
	i = 0;
	while (i < po->sizea - 1)
	{
		po->arra[i] = po->arra[i + 1];
		i++;
	}
	po->arra[i] = tmp;
	ft_printf("ra\n");
}

void		ft_operations_rb(t_swap *po)
{
	int tmp;
	int i;

	tmp = po->arrb[0];
	i = 0;
	while (i < po->sizeb - 1)
	{
		po->arrb[i] = po->arrb[i + 1];
		i++;
	}
	po->arrb[i] = tmp;
	ft_printf("rb\n");
}
