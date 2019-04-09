cmake_minimum_required(VERSION 3.13)

project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Werror -Wextra")

file(GLOB LIBFT libft/*.c libft/*.h libft/ft_printf/*.c libft/ft_printf/*.h)

set(SOURCES push_swap_file/search_and_min_max.c push_swap_file/rotet_b_rr.c push_swap_file/func_help_for_sort.c push_swap_file/main.c push_swap_file/header/push_swap.h push_swap_file/scan_argv.c push_swap_file/ft_operations.c push_swap_file/ft_operations_p2.c push_swap_file/ft_operations_p3.c push_swap_file/ft_sort.c push_swap_file/ft_operations_p4.c)

add_executable(push_swap ${SOURCES} ${LIBFT})

#checker_file/main.c checker_file/header/ft_checker.h