/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:55:04 by tmann             #+#    #+#             */
/*   Updated: 2019/04/08 20:59:32 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include "../../push_swap_file/header/push_swap.h"
# define BF 1000

t_swap				*ccheck_argv(t_swap *po,
						int argc, char **argv);
void				cval_param(int argc, char **argv, int i, int j);
void				cval_numb(char **str);
void				ccreat_struct_arr(t_swap *po, char *str, int i, int j);
void				ccreat_one_str(t_swap *po, int argc, char **argv);
void				check_flag(char *str, t_swap *po, int argc);
char				**readcom(int nb, char *tmp);
void				val_command_read(char *str);
void				val_command(char **str);
void				use_command(t_swap *po, char **str, int j);
void				hp_use_command(t_swap *po, char **str, int j);
void				ft_operations_sa(t_swap *po);
void				print_swap(t_swap *po);
void				scan_sort(t_swap *po);

#endif
