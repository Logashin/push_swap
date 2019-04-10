/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usecommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:51:38 by tmann             #+#    #+#             */
/*   Updated: 2019/04/09 22:04:25 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_checker.h"

char			**readcom(int nb, char *tmp)
{
	char	strbuf[BF + 1];
	char	*strmap;
	char	**twoarr;

	strmap = ft_strnew(0);
	while ((nb = read(0, strbuf, BF)) > 0)
	{
		strbuf[nb] = '\0';
		tmp = strmap;
		strmap = ft_strjoin(strmap, strbuf);
		val_command_read(strmap);
		free(tmp);
	}
	twoarr = ft_strsplit(strmap, '\n');
	free(strmap);
	val_command(twoarr);
	return (twoarr);
}

void			val_command(char **str)
{
	int j;

	j = 0;
	while (str[j] != NULL)
	{
		if ((str[j][0] == 's' && str[j][1] == 'a') ||
		(str[j][0] == 's' && str[j][1] == 'b') ||
		(str[j][0] == 's' && str[j][1] == 's') ||
		(str[j][0] == 'p' && str[j][1] == 'a') ||
		(str[j][0] == 'p' && str[j][1] == 'b') ||
		(str[j][0] == 'r' && str[j][1] == 'a') ||
		(str[j][0] == 'r' && str[j][1] == 'b') ||
		(str[j][0] == 'r' && str[j][1] == 'r') ||
		(str[j][0] == 'r' && str[j][1] == 'r' &&
		str[j][2] == 'a') || (str[j][0] == 'r' &&
		str[j][1] == 'r' && str[j][2] == 'b') ||
		(str[j][0] == 'r' &&
		str[j][1] == 'r' && str[j][2] == 'r'))
			j++;
		else
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
}

void			use_command(t_swap *po, char **str, int j)
{
	while (str[++j])
	{
		if ((ft_strcmp(str[j], "sa") == 0))
			ft_operations_sa(po);
		if ((ft_strcmp(str[j], "sb") == 0))
			ft_operations_sb(po);
		if ((ft_strcmp(str[j], "ss") == 0))
			ft_operations_ss(po);
		if ((ft_strcmp(str[j], "pa") == 0))
			ft_operations_pa(po, 0);
		if ((ft_strcmp(str[j], "pb") == 0))
			ft_operations_pb(po);
		hp_use_command(po, str, j);
		if (po->flag == 2)
		{
			ft_printf("<%s>\n", str[j]);
			print_swap(po);
		}
	}
}

void			hp_use_command(t_swap *po, char **str, int j)
{
	if ((ft_strcmp(str[j], "ra") == 0))
		ft_operations_ra(po);
	if ((ft_strcmp(str[j], "rb") == 0))
		ft_operations_rb(po);
	if ((ft_strcmp(str[j], "rr") == 0))
		ft_operations_rr(po);
	if ((ft_strcmp(str[j], "rra") == 0))
		ft_operations_rra(po);
	if ((ft_strcmp(str[j], "rrb") == 0))
		ft_operations_rrb(po);
	if ((ft_strcmp(str[j], "rrr") == 0))
		ft_operations_rrr(po);
}

void			scan_sort(t_swap *po)
{
	int i;

	i = 0;
	while (i < po->sizea - 1)
	{
		if (po->arra[i] > po->arra[i + 1])
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	if (po->sizeb == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
