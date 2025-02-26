/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/26 16:40:34 by ggoncalv         ###   ########.fr       */
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
	//int				position;
	int				number;
	//char			direction;
	//int				cost;
	//int				total_cost;
	struct s_list	*next;
}					t_list;

//free and error ft utils
void	ft_error(void);
void	ft_free_lst(t_list **head);
void	ft_free_args(char **args);
void	ft_error_init_stack(t_list **stack_a, char **args);

//PARTE I - funcoes de iniciar a stack:
//void	ft_init_node_a_bottom(t_list *new_node, int i);
//void	ft_init_node_a(t_list *new_node, int size);
void	ft_init_stack(int argc, char **argv, t_list **stack_a);
char	**ft_divide_args(int argc, char **argv);
int		ft_check_args(char *char_args);
int		ft_check_duplicates(t_list **stack_a);
int		ft_check_if_sorted(t_list **stack_a);
t_list	*ft_new_node(char	*args);
void	ft_lstadd_back(t_list **stack_a, t_list *new_node);
void	ft_lstprint(t_list *head);
int		ft_lstsize(t_list *head);

//utils da median
int		ft_int_check_if_sorted(int *int_args, int args_size);
int		*init_int_args(t_list *stack_a, int size);
int		*get_chunks(int *args, int size);
int		*get_median(t_list *head_a);

//move_and_sort utils:
/*void	ft_move_top_a(t_list **head_a, t_list **head_b, t_list *best_node);
void	ft_move_bottom_a(t_list **head_a, t_list **head_b, t_list *best_node);
void	ft_sort_top_b(t_list **head_b, t_list *node_b);
void	ft_sort_bottom_b(t_list **head_b, t_list *node_b);
t_list	*ft_lstlast(t_list **head_a);
void	ft_move_and_sort(t_list **head_a, t_list **head_b, t_list **tail_a, t_list *best_node);*/

//movements:
void	ft_print_mov(int index, char *mov);
void	ft_sa_sb(t_list **head, int flag);
void 	ft_pa_pb(t_list **stack_a, t_list **stack_b, int flag);
void	ft_ra_rb(t_list **stack, int flag);
void	ft_rra_rrb(t_list **stack, int flag);
void	ft_pb(t_list **stack_a, t_list **stack_b, int flag);
//PARTE II - algoritmo:
void	sorting_algorithm(t_list **stack_a)
;
/*int		check_trio(t_list **head_a, t_list **tail_a, t_list **head_b, int median);
void	check_duo(t_list **head_a, t_list **tail_a, t_list **head_b, int median);
void	check_best_node(t_list **head_a, t_list **tail_a, t_list **head_b, int median);
t_list	*ft_chosen_node(t_list *node_1, t_list *node_2);
void	ft_check_cost(t_list *node_a, t_list *head_b, int median);
void	ft_init_node_b_bottom(t_list *stack_b, int i);
void	ft_init_node_b(t_list *stack_b, int size);
void	ft_sort_a(t_list **head_a, t_list **tail_a);
int		get_numbers_bellow_median(t_list *stack_a, int median);*/

#endif
