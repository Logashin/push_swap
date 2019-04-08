/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:55:31 by tmann             #+#    #+#             */
/*   Updated: 2019/04/08 22:23:57 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/libft.h"

typedef struct		s_swap
{
	int				*arra;
	int				*arrb;
	int				sizearr;
	int				sizea;
	int				sizeb;
	int				flag;
	int				min;
	int				max;

}					t_swap;

typedef struct		s_count
{
	int				a;
	int				b;
	int				wa;
	int				wb;
	int				res;

}					t_count;

int					main (int argc, char **argv);
t_swap				*scan_argv(t_swap *po, int argc, char **argv);
void				val_param(int argc, char **argv, int i, int j);
void				val_numb(char **str);
void				creat_one_str(t_swap *po, int argc, char **argv);
void				creat_struct_arr(t_swap *po, char *str, int i, int j);
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
void				ft_zerostruct(t_count *co);
void				ft_sort(t_swap *po);
int					checksort(t_swap *po);
void				rotet_b_rr(t_swap *po);
t_count				*count_command(t_swap *po, int i, int b);
void				ft_count_b(t_count *co, t_swap *po, int i);
int					top_res(int res, t_count *co);
void				ft_index(t_swap *po, int b, t_count *co);
int					checkr(t_swap *po, int min);
int					checksort(t_swap *po);
void				search_min_max(t_swap *po);
void				ft_rot_for_rr(t_swap *po, t_count *co);
void				ft_rot_for_rrr(t_swap *po, t_count *co);
int					ft_rot_for_rb(t_swap *po, t_count *co);
void				ft_rot_for_a(t_swap *po, t_count *co);
void				final_sort(t_swap *po);

#endif
