/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:33:15 by tmann             #+#    #+#             */
/*   Updated: 2019/03/28 18:33:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		ft_operations_pa(t_swap *po, int i)
{
	if (po->sizeb == 0)
		return ;
	if (po->sizea >= 0)
	{
		i = po->sizea;
		while (i >= 0)
		{
			po->arra[i] = po->arra[i - 1];
			i--;
		}
		ft_swap(&po->arra[0], &po->arrb[0]);
		po->sizeb--;
		po->sizea++;
		if (po->arrb[1] != 0)
		{
			i = 0;
			while (i < po->sizeb)
			{
				po->arrb[i] = po->arrb[i + 1];
				i++;
			}
		}
	}
	ft_printf("pa\n");
}

void		ft_operations_pb(t_swap *po)
{
	int i;

	i = 0;
	if (po->sizea == 0)
		return ;
	if (po->sizeb == 0)
	{
		ft_swap(&po->arra[0], &po->arrb[0]);
		po->sizea--;
		while (i < po->sizea)
		{
			po->arra[i] = po->arra[i + 1];
			i++;
		}
	}
	if (po->sizeb > 0)
	{
		ft_operations_pb_hp(po);
	}
	po->sizeb++;
	ft_printf("pb\n");
}

void		ft_operations_pb_hp(t_swap *po)
{
	int i;

	i = po->sizeb;
	while (i > 0)
	{
		po->arrb[i] = po->arrb[i - 1];
		i--;
	}
	ft_swap(&po->arra[0], &po->arrb[0]);
	i = 0;
	while (i < po->sizea)
	{
		po->arra[i] = po->arra[i + 1];
		i++;
	}
	po->sizea--;
}