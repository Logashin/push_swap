/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:20:38 by tmann             #+#    #+#             */
/*   Updated: 2019/03/27 21:03:06 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void		val_param(int argc, char **argv, int i)
{
	int j;

	j = 1;
	while (argv[j][i] == ' ')
        i++;
	while (j < argc)
	{
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] == '-' && ft_isdigit(argv[j][i + 1]) && argv[j][i - 1] == ' ') || (argv[j][0] == '-' && ft_isdigit(argv[j][i + 1])))
				i++;
			else if (argv[j][i] >= '0' && argv[j][i] <= '9')
				i++;
			else if (argv[j][i] == ' ')
				i++;
			else
			{
				ft_printf("ERROR: letters_in_the_parameters");
				exit(0);
			}
		}
		j++;
		i = 0;
	}
}

void		val_numb(char **str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 1;
	if (str[j] == NULL || str[i] == NULL)
		return ;
	while (str[j] != NULL)
	{
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) != ft_atoi(str[j]))
				j++;
			else
			{
				ft_printf("ERROR: identical_numbers");
				exit(0);
			}
		}
		i++;
		j = i + 1;
	}
}

void		creat_struct_arr(t_swap *po, char *str)
{
	char		**arr;
    int			i;
    int			j;

	i = 0;
	j = 0;
	arr = ft_strsplit(str, ' ');
	free(str);
	while(arr[j] != NULL)
		j++;
	po->sizearr = j;
	j = 0;
	val_numb(arr);
	po->arr = (int*)malloc(sizeof(int) * po->sizearr);
	while (arr[j] != NULL)
	{
		po->arr[i] = ft_atoi(arr[j]);
		free(arr[j]);
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
	creat_struct_arr(po, str);
}

t_swap		*scan_argv(t_swap *po, int argc, char **argv)
{
	po = (t_swap*)malloc(sizeof(t_swap));
	po->sizearr = 0;
	val_param(argc, argv, 0);
	creat_one_str(po, argc, argv);
	return (po);
}
