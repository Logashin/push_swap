/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:33:15 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 21:28:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_checker.h"

void		ft_operations_pa(t_swap *po, int i)
{
	if (po->sizeb == 0)
		return ;
	if (po->sizea >= 0)
	{
		i = po->sizea;
		while (i > 0)
		{
			po->arra[i] = po->arra[i - 1];
			i--;
		}
		ft_swap(&po->arra[0], &po->arrb[0]);
		po->sizeb--;
		po->sizea++;
		if (po->sizeb > 0)
		{
			i = 0;
			while (i < po->sizeb)
			{
				po->arrb[i] = po->arrb[i + 1];
				i++;
			}
		}
	}
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

void		ft_operations_sa(t_swap *po)
{
	if (po->sizea <= 1)
		return ;
	ft_swap(&po->arra[0], &po->arra[1]);
}

void		ft_operations_sb(t_swap *po)
{
	if (po->sizeb <= 1)
		return ;
	ft_swap(&po->arrb[0], &po->arrb[1]);
}
