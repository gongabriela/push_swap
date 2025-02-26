/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:52:45 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:45 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(int argc, char **argv, t_list **stack_a, t_list **tail_a)
{
	t_list	*new_node;
	char	**args;
	int		i;

	args = ft_divide_args(argc, argv);
	i = 0;
	while (args[i])
	{
		if (ft_check_args(args[i]))
			ft_error_init_stack(stack_a, args);
		else
		{
			new_node = ft_new_node(args[i]);
			*tail_a = new_node;
			if (new_node == NULL)
				ft_error_init_stack(stack_a, args);
			ft_lstadd_back(stack_a, new_node);
		}
		i++;
	}
	if (ft_lstsize(*stack_a) == 1 || ft_check_if_sorted(stack_a) || ft_check_duplicates(stack_a))
		ft_error_init_stack(stack_a, args);
	ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
	ft_free_args(args);
}
//versao meio turk/ meio mediana
/*void	sorting_algorithm(t_list **stack_a, t_list **tail_a)
{
	int		median;
	t_list *stack_b;

	stack_b = NULL;
	while(ft_lstsize(*stack_a) != 3)
	{
		median = get_median(*stack_a); //talvez tambem dividir a mediana em 2 ou 3 ou 4 partes? para passar os numeros mais proximos... nao sei. pq ja vimos que custa menos rodar a stack_a do que organizar na st
		while (ft_lstsize(*stack_a) > current_size)
		{
			//printf("median: %d\n", median);
			if (check_trio(stack_a, tail_a, &stack_b, median))
				check_duo(stack_a, tail_a, &stack_b, median);
			//check_best_node(stack_a, tail_a, &stack_b, median);
			ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
			ft_init_node_b(stack_b, ft_lstsize(stack_b));
			//ft_lstprint(*stack_a);
			//ft_lstprint(stack_b);
			//printf("\n\n");
		}
	}
	ft_sort_a(stack_a, tail_a);
	//ft_lstprint(*stack_a);
	//ft_lstprint(stack_b);
	//printf("\n\n");
	while (ft_lstsize(stack_b) > 0)
		ft_pb(stack_a, &stack_b, 1);
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);
}*/

//versao bubble sort
void sorting_algorithm(t_list **stack_a, t_list **tail_a)
{
	t_list *stack_b;
	int *chunk;
	int i;

	stack_b = NULL;
	i = 0;
	chunk = get_median(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		while (get_numbers_bellow_median(*stack_a, chunk[i]) > 0 && ft_lstsize(*stack_a) > 3)
		{
			//printf("chunk: %d\n", chunk[i]);
			if (check_trio(stack_a, tail_a, &stack_b, chunk[i]))
				check_duo(stack_a, tail_a, &stack_b, chunk[i]);
			ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
			ft_init_node_b(stack_b, ft_lstsize(stack_b));
			//ft_lstprint(*stack_a);
			//ft_lstprint(stack_b);
			//printf("\n\n");
		}
		i++;
	}
	ft_sort_a(stack_a, tail_a);
	while (ft_lstsize(stack_b) > 0)
		ft_pb(stack_a, &stack_b, 1);
	//ft_lstprint(*stack_a);
	//ft_lstprint(stack_b);
	free(chunk);
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tail_a;

	stack_a = NULL;
	ft_init_stack(argc, argv, &stack_a, &tail_a);
	sorting_algorithm(&stack_a, &tail_a);
	ft_free_lst(&stack_a);
	return (0);
}
