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

void		print_swap(t_swap *po)
{
	int i;
	int stop;

	i = 0;
	if (po->sizea >= po->sizeb)
		stop = po->sizea;
	else
		stop = po->sizeb;
	ft_printf("<************************>\n");
	while (i < stop)
	{
		if (po->sizea <= i)
			ft_printf("           |");
		else
			ft_printf("%11d|", po->arra[i]);
		if (po->sizeb <= i)
			ft_printf("   | \n");
		else
			ft_printf("   |%d\n", po->arrb[i]);
		i++;
	}
	ft_printf("          _     _\n");
	ft_printf("          a <*> b\n");
	ft_printf("<************************>\n");
}

int			main(int argc, char **argv)
{
	t_swap		*po;

	po = NULL;
	if (argc > 1)
	{
		po = scan_argv(po, argc, argv);
		ft_sort(po);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
//	free(po->arra);
//	free(po);
	return (0);
}
