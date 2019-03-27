/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:27:46 by tmann             #+#    #+#             */
/*   Updated: 2019/03/27 20:56:32 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int			main (int argc, char **argv)
{
	t_swap		*po;

	po = NULL;
	if (argc > 1)
	{
		po = scan_argv(po, argc, argv);
	}
	else
		return 0;
	int i = 0;
	while (i < po->sizearr)
	{
		ft_printf("%d\n", po->arr[i]);
		i++;
	}
	free(po->arr);
	free(po);
	return (0);
}
