/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:20:38 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 21:57:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		val_param(int argc, char **argv, int i, int j)
{
	while (argv[j][i] == ' ')
		i++;
	while (j < argc)
	{
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] == '-' && ft_isdigit(argv[j][i + 1]) &&
				argv[j][i - 1] == ' ') || (argv[j][0] == '-' &&
				ft_isdigit(argv[j][i + 1]) && i == 0))
				i++;
			else if (argv[j][i] >= '0' && argv[j][i] <= '9')
				i++;
			else if (argv[j][i] == ' ')
				i++;
			else
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		j++;
		i = 0;
	}
}

void		val_numb(char **str, size_t i, size_t j)
{
	while (str[j] != NULL)
	{
		while (str[j] != NULL)
		{
			if (ft_swap_atoi(str[i]) != ft_swap_atoi(str[j]))
				j++;
			else
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		if (ft_swap_atoi(str[i]) > 2147483647 ||
				ft_swap_atoi(str[i]) < -2147483648)
			ft_error_ps();
		i++;
		j = i + 1;
	}
	if (ft_swap_atoi(str[i]) > 2147483647 || ft_swap_atoi(str[i]) < -2147483648)
		ft_error_ps();
}

void		creat_struct_arr(t_swap *po, char *str, int i, int j)
{
	char		**arr;

	arr = ft_strsplit(str, ' ');
	free(str);
	while (arr[j] != NULL)
		j++;
	po->sizearr = j;
	if (po->sizearr == 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	j = 0;
	val_numb(arr, 0, 1);
	po->arra = (int*)malloc(sizeof(int) * po->sizearr);
	po->arrb = (int*)malloc(sizeof(int) * po->sizearr);
	while (arr[j] != NULL)
	{
		po->arra[i] = ft_atoi(arr[j]);
		po->arrb[i] = 0;
		free(arr[i]);
		i++;
		j++;
	}
	free(arr);
}

void		creat_one_str(t_swap *po, int argc, char **argv)
{
	char		*str;
	int			j;

	j = 1;
	str = ft_strdup(argv[j]);
	j++;
	while (j < argc)
	{
		str = ft_strjoin_free(str, " ", 1, 0);
		str = ft_strjoin_free(str, argv[j], 1, 0);
		j++;
	}
	creat_struct_arr(po, str, 0, 0);
}

t_swap		*scan_argv(t_swap *po, int argc, char **argv)
{
	po = (t_swap*)malloc(sizeof(t_swap));
	po->sizearr = 0;
	po->sizea = 0;
	po->sizeb = 0;
	val_param(argc, argv, 0, 1);
	creat_one_str(po, argc, argv);
	po->sizea = po->sizearr;
	return (po);
}
