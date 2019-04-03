/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:55:31 by tmann             #+#    #+#             */
/*   Updated: 2019/04/03 17:36:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/libft.h"

typedef struct		s_swap
{
	int				*arra;
	int 			*arrb;
	int				sizearr;
	int				sizea;
	int 			sizeb;
	int				flag;
}					t_swap;

int					main (int argc, char **argv);
t_swap				*scan_argv(t_swap *po, int argc, char **argv);
void				val_param(int argc, char **argv, int i, int j);
void				val_numb(char **str);
void				creat_one_str(t_swap *po, int argc, char **argv);
void				creat_struct_arr(t_swap *po, char *str, int i, int j);
void				print_swap(t_swap *po);
void				ft_operations_sa(t_swap *po);
void				ft_operations_sb(t_swap *po);
void				ft_operations_ss(t_swap *po);
void				ft_operations_pa(t_swap *po, int i);
void				ft_operations_pb(t_swap *po);
void				ft_operations_pb_hp(t_swap *po);
void				ft_operations_ra(t_swap *po);
void				ft_operations_rb(t_swap *po);
void				ft_operations_rra(t_swap *po);
void				ft_operations_rrb(t_swap *po);
void				ft_operations_rrr(t_swap *po);
void				ft_operations_rr(t_swap *po);
void				ft_sort(t_swap *po);
int					checksort(t_swap *po);

#endif
