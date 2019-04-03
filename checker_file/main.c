/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:27:28 by tmann             #+#    #+#             */
/*   Updated: 2019/04/03 18:39:08 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_checker.h"

void		check_flag(char *str, t_swap *po, int argc)
{
	if (str[0] == '-' && str[1] == 'v')
		po->flag = 2;
	else
		po->flag = 1;
	if (argc < 3)
	{
		ft_printf("ERROR: need_command\n");
		exit(0);
	}
}

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
	char		**com;

	po = NULL;
	if (argc > 1)
	{
		po = ccheck_argv(po, argc, argv);
		com = readcom(0, NULL);
		use_command(po, com, -1);
		scan_sort(po);
		free(po->arra);
		free(po->arrb);
		ft_free_two_arr(com);
		free(po);
	}
	return (0);
}
