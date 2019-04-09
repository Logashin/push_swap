/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotet_b_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:22:10 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 20:22:30 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void			rotet_b_rr(t_swap *po)
{
	t_count *co;

	co = count_command(po, 0, 0);
	ft_rot_for_rr(po, co);
	ft_rot_for_rrr(po, co);
	if (ft_rot_for_rb(po, co) == 1)
		return ;
	if (co->b > 0 && co->wb == 2)
	{
		while (co->b != 0)
		{
			ft_operations_rrb(po);
			co->b--;
			if (po->arra[0] > po->arrb[0] &&
				po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return ;
			}
		}
	}
	ft_rot_for_a(po, co);
	free(co);
}

void			ft_rot_for_a(t_swap *po, t_count *co)
{
	if (co->wa == 2)
	{
		while (po->sizeb != 0)
		{
			if (po->arra[0] > po->arrb[0] &&
				po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return ;
			}
			ft_operations_rra(po);
		}
	}
	else
		while (po->sizeb != 0)
		{
			if (po->arra[0] > po->arrb[0] &&
				po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return ;
			}
			ft_operations_ra(po);
		}
}

void			ft_rot_for_rr(t_swap *po, t_count *co)
{
	if (co->wa == 1 && co->wb == 1 && co->a > 0 && co->b > 0)
	{
		while (co->a != 0 && co->b != 0)
		{
			if (po->arra[0] > po->arrb[0]
				&& po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return ;
			}
			else if (co->a != 0 && co->b != 0)
			{
				ft_operations_rr(po);
				co->b--;
				co->a--;
			}
			else
				break ;
		}
	}
}

void			ft_rot_for_rrr(t_swap *po, t_count *co)
{
	if (co->wa == 2 && co->wb == 2 && co->a > 0 && co->b > 0)
	{
		while (co->a != 0 && co->b != 0)
		{
			if (co->a != 0 && co->b != 0)
			{
				ft_operations_rrr(po);
				co->b--;
				co->a--;
			}
			else if (po->arra[0] > po->arrb[0] &&
				po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return ;
			}
			else
				break ;
		}
	}
}

int				ft_rot_for_rb(t_swap *po, t_count *co)
{
	if (co->b > 0 && co->wb == 1)
	{
		while (co->b != 0)
		{
			ft_operations_rb(po);
			co->b--;
			if (po->arra[0] > po->arrb[0] &&
				po->arra[po->sizea - 1] < po->arrb[0] && po->sizeb > 0)
			{
				ft_operations_pa(po, 0);
				return (1);
			}
		}
	}
	return (0);
}
