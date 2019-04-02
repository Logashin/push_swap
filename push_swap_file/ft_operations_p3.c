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

void		ft_operations_rr1(t_swap *po)
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
}

void		ft_operations_rr2(t_swap *po)
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
}

void		ft_operations_rr(t_swap *po)
{
	ft_operations_rr1(po);
	ft_operations_rr2(po);
	ft_printf("rr\n");
}
