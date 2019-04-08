/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_help_for_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:13:14 by tmann             #+#    #+#             */
/*   Updated: 2019/04/08 22:23:07 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int				checksort(t_swap *po)
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

int				checkr(t_swap *po, int min)
{
	int i;

	i = 0;
	while (i <= po->sizea / 2)
	{
		if (po->arra[i] == min)
			return (0);
		i++;
	}
	return (1);
}

void			ft_index(t_swap *po, int b, t_count *co)
{
	int i;

	i = 0;
	while (po->sizea > i)
	{
		if ((po->arra[i] < po->arrb[b] && po->arra[i + 1] > po->arrb[b]))
		{
			if (po->arra[0] > po->arrb[b] &&
				po->arra[po->sizea - 1] < po->arrb[b])
				co->a = 0;
			else if ((po->sizea - 1) / 2 >= i + 1)
			{
				co->wa = 1;
				co->a = i + 1;
			}
			else
			{
				co->wa = 2;
				co->a = (po->sizea - 1) - i;
			}
			break ;
		}
		i++;
	}
}

int				top_res(int res, t_count *co)
{
	int save;

	save = 0;
	if (co->a > 0 && co->b > 0)
	{
		save = (co->a < co->b) ? co->b - co->a : co->a - co->b;
		if (co->a > co->b)
			res = save + co->b;
		else if (co->a < co->b)
			res = save + co->a;
		else
			res = co->a;
	}
	else
	{
		res = co->a + co->b;
	}
	return (res);
}

void			ft_count_b(t_count *co, t_swap *po, int i)
{
	if (po->sizeb / 2 >= i)
	{
		co->wb = 1;
		co->b = i;
	}
	else
	{
		co->wb = 2;
		co->b = po->sizeb - i;
	}
}
