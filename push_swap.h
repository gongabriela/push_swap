/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/19 16:27:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //nao esquecer de tirar
# include "Libft/libft.h"

typedef struct s_list
{
	struct s_list	*previous;
	int				position;
	int				number;
	char			*direction;
	int				cost;
	int				total_cost;
	struct s_list	*next;
}					t_list;

//atol
int		ft_isspace(int c);
long	ft_atol(const char *str);

//free and error ft utils
void	ft_error(void);
void	ft_free_lst(t_list **head);
void	ft_free_args(char **args);
void	ft_error_init_stack(t_list **stack_a, char **args);

//PARTE I - funcoes de iniciar a stack:
void	ft_init_stack(int argc, char **argv, t_list **stack_a);
t_list	*ft_lastnode(t_list *stack_a);
char	**ft_divide_args(int argc, char **argv);
int		ft_check_args(char *char_args);
int		ft_check_duplicates(t_list **stack_a);
int		ft_check_if_sorted(t_list **stack_a);
t_list	*ft_new_node(char	*args);
void	ft_init_node(t_list *new_node, int size);
void	ft_lstadd_back(t_list **stack_a, t_list *new_node);
void	ft_lstprint(t_list *head);
int		ft_lstsize(t_list *head);

//PARTE II - algoritmo:
void	sorting_algorithm(t_list **stack_a, t_list **tail_a);
int	ft_check_3(t_list **head_a, t_list **tail_a, t_list **head_b, int median);

//check 3 utils
void	ft_check_cost(t_list *node_a, t_list *head_b, int median);
t_list	*ft_chosen_node(t_list *node_1, t_list *node_2);
//utils da median
int		ft_int_check_if_sorted(int *int_args, int args_size);
int		*init_int_args(t_list **stack_a, int size);
int		ft_get_median(t_list **head_a);

#endif
