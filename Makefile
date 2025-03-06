# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:14:30 by ggoncalv          #+#    #+#              #
#    Updated: 2025/03/06 12:17:33 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_free_error.c ft_check_args.c init_stack.c movements.c algorithm_utils_2.c algorithm_utils.c push_swap.c

OBJ = $(SRC:.c=.o)

LIBFT = ./Libft/libft.a

all: $(NAME)

#linkar os objs do push_swap com o .a do libft e criar o ./push_swap (?)
$(NAME): $(OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) -g $(OBJ) $(LIBFT) -o $(NAME)

debug:
	make -C ./Libft
	cc -g ft_free_error.c ft_check_args.c init_stack.c movements.c algorithm_utils_2.c algorithm_utils.c push_swap.c ./Libft/libft.a -o push_swap
clean:
	make -C ./Libft fclean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
