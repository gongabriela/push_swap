# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:14:30 by ggoncalv          #+#    #+#              #
#    Updated: 2025/03/12 14:51:22 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_free_error.c ft_check_args.c init_stack.c movements.c movements_2.c algorithm_utils_2.c algorithm_utils.c push_swap.c
OBJ = $(SRC:.c=.o)

LIBFT = ./Libft/libft.a

SRC_CHECKER = ft_free_error.c ft_check_args.c init_stack.c movements.c movements_2.c checker.c
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) -g $(OBJ) $(LIBFT) -o $(NAME)

debug:
	make -C ./Libft
	cc -g ft_free_error.c ft_check_args.c init_stack.c movements.c movements_2.c algorithm_utils_2.c algorithm_utils.c push_swap.c ./Libft/libft.a -o push_swap

clean:
	make -C ./Libft fclean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJ_CHECKER)
	make -C ./Libft
	$(CC) $(CFLAGS) -g $(OBJ_CHECKER) $(LIBFT) -o checker

bfclean:
	rm -rf $(OBJ_CHECKER)
	rm -rf checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
