# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: openelop <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/31 13:23:41 by openelop          #+#    #+#              #
#    Updated: 2020/02/08 14:20:50 by lvania           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap
NAME_CHECKER = checker

SRC = command_push.c command_rotate.c command_swap.c list_command.c median_sort_additional.c median_sort_cicle.c sort_five.c to_sort.c free.c no_name.c parser.c additional_function.c
SRC_PUSH = push_swap.c
SRC_CHECKER = checker.c

OBJ = $(SRC:.c=.o)
OBJ_PUSH = $(SRC_PUSH:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

HEADER = push_swap.h
LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror
LIB_FLAG = libft/libft.a
NAME_LIB = libft.a

all: $(NAME_LIB) $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_LIB):
	@make -C libft/

$(NAME_PUSH): $(OBJ) $(OBJ_PUSH) $(NAME_LIB) $(HEADER)
# 	@make -C libft/
	@gcc $(FLAGS) $(SRC) $(SRC_PUSH) -o $(NAME_PUSH) $(LIB)

$(NAME_CHECKER): $(OBJ) $(OBJ_CHECKER) $(NAME_LIB) $(HEADER)
# 	@make -C libft/
	@gcc $(FLAGS) $(SRC) $(SRC_CHECKER) -o $(NAME_CHECKER) $(LIB)

%.o:%.c $(HEADER) $(LIB)
	@gcc $(FLAGS) -I . -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_PUSH) $(OBJ_CHECKER)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME_PUSH) $(NAME_CHECKER)
	@make -C libft/ fclean


re: fclean all

.PHONY: clean fclean all re
