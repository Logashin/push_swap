/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_min_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:40:05 by tmann             #+#    #+#             */
/*   Updated: 2019/04/08 22:24:57 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

t_count		*count_command(t_swap *po, int i, int b)
{
	t_count		*co;
	int			check;

	check = 2147483647;
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

void		search_min_max(t_swap *po)
{
	int i;

	i = 0;
	po->min = po->arra[0];
	po->max = po->arra[0];
	while (i < po->sizea)
	{
		if (po->min > po->arra[i])
			po->min = po->arra[i];
		i++;
	}
	i = 0;
	while (i < po->sizea)
	{
		if (po->max < po->arra[i])
			po->max = po->arra[i];
		i++;
	}
}
