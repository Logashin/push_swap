NAME = push_swap

NAMEC = checker

SRCCH = main.c \
		scan_argv.c \
		ft_operations.c \
		ft_operations_p2.c \
		ft_operations_p3.c \
		ft_operations_p4.c \
		usecommand.c \

SRCPS = main.c \
		scan_argv.c \
		ft_operations.c \
		ft_operations_p2.c \
		ft_operations_p3.c \
		ft_operations_p4.c \
		ft_sort.c \
		func_help_for_sort.c \
		rotet_b_rr.c \
		search_and_min_max.c \

DIRCHECK = checker_file

DIRSWAP = push_swap_file

FCC = $(addprefix $(DIRCHECK)/, $(SRCCH))

FCPS = $(addprefix $(DIRSWAP)/, $(SRCPS))

INCLUDES = libft/libft.a

all: $(NAME) $(NAMEC)

$(NAMEC): $(FCC)
		gcc -Wall -Werror -Wextra $(FCC) $(INCLUDES) -o $(NAMEC)

$(NAME): $(FCPS)
		make -C libft
		gcc -Wall -Werror -Wextra $(FCPS) $(INCLUDES) -o $(NAME)

clean: 
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME)
		rm -f $(NAMEC)

re: fclean all
