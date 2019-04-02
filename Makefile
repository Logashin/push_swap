NAME = push_swap

SRCPS = main.c \
		scan_argv.c \
		ft_operations.c \
		ft_operations_p2.c \
		ft_operations_p3.c \
		ft_operations_p4.c \
		ft_sort.c \

DIRSWAP = push_swap_file

FCPS = $(addprefix $(DIRSWAP)/, $(SRCPS))

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(FCPS)
		make -C libft
		gcc -g -Wall -Werror -Wextra $(FCPS) $(INCLUDES) -o $(NAME)

clean: 
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all
