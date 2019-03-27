#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/libft.h"

typedef struct		s_swap
{
	int				sizearr;
	int				*arr;
}					t_swap;

int					main (int argc, char **argv);
t_swap				*scan_argv(t_swap *po, int argc, char **argv);
void				val_param(int argc, char **argv, int i);
void				val_numb(char **str);
void				creat_one_str(t_swap *po, int argc, char **argv);
void				creat_struct_arr(t_swap *po, char *str);

#endif
