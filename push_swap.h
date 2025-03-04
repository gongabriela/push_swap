/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/04 16:33:01 by ggoncalv         ###   ########.fr       */
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
	int				index;
	char			direction;
	int				number;
	int				cost;
	struct s_list	*target_node;
	struct s_list	*next;
}					t_list;

//free and error ft utils
void	ft_error(void);
void	ft_free_lst(t_list **head);
void	ft_free_args(char **args);
void	ft_error_init_stack(t_list **stack_a, char **args);

//PARTE I - funcoes de iniciar a stack:
void	ft_init_stack(int argc, char **argv, t_list **stack_a);
char	**ft_divide_args(int argc, char **argv);
int		ft_check_args(char *char_args);
int		ft_check_duplicates(t_list **stack_a);
int		ft_check_if_sorted(t_list **stack_a);
t_list	*ft_new_node(char	*args);
void	ft_lstadd_back(t_list **stack_a, t_list *new_node);
void	ft_lstprint(t_list *head);
int		ft_lstsize(t_list *head);

//movements:
void	ft_print_mov(int index, char *mov);
void	ft_sa_sb(t_list **head, int flag);
void 	ft_pa_pb(t_list **stack_a, t_list **stack_b, int flag);
void	ft_ra_rb(t_list **stack, int flag);
void	ft_rra_rrb(t_list **stack, int flag);

//PARTE II - algoritmo para stack > 3:
void	sorting_algorithm(t_list **stack_a, t_list **stack_b);
void	update_cost(t_list *stack, int size);
t_list	*max_value(t_list *stack);
void	update_targets_of_stack_a(t_list *stack_a, t_list *stack_b);
t_list	*find_cheaper_node(t_list *stack_a);
void	node_to_top_b(t_list **stack_b, t_list *node, int flag);
void	node_to_top_a(t_list **stack_a, t_list *node, int flag);
t_list	*min_value(t_list *stack);
void	update_targets_of_stack_b(t_list *stack_a, t_list *stack_b);
void	sort_3(t_list **head_a);

#endif
