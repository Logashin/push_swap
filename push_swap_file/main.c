/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:27:46 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 17:31:02 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		ft_zerostruct(t_count *co)
{
	co->a = 0;
	co->b = 0;
	co->wa = 0;
	co->wb = 0;
}

int			main(int argc, char **argv)
{
	t_swap		*po;

	po = NULL;
	if (argc > 1)
	{
		po = scan_argv(po, argc, argv);
		ft_sort(po);
		free(po->arra);
		free(po->arrb);
		free(po);
	}
	return (0);
}
