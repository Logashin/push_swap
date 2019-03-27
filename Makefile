NAME = push_swap

SRCPS = main.c \
		scan_argv.c \

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
