/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_p4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:49:17 by tmann             #+#    #+#             */
/*   Updated: 2019/04/03 17:18:03 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_checker.h"

void		ft_operations_rrr1(t_swap *po)
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
}

void		ft_operations_rrr2(t_swap *po)
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
}

void		ft_operations_rrr(t_swap *po)
{
	ft_operations_rrr1(po);
	ft_operations_rrr2(po);
}
