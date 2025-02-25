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

void	sorting_algorithm(t_list **stack_a, t_list **tail_a)
{
	int		median;
	int		current_size;
	t_list *stack_b;

	stack_b = NULL;
	while(ft_lstsize(*stack_a) != 3)
	{
		current_size = ft_lstsize(*stack_a) / 3;
		median = get_median(*stack_a);
		while (ft_lstsize(*stack_a) > current_size)
		{
			//printf("median: %d\n", median);
			if (check_trio(stack_a, tail_a, &stack_b, median))
				check_duo(stack_a, tail_a, &stack_b, median);
			//check_best_node(stack_a, tail_a, &stack_b, median);
			ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
			ft_init_node_b(stack_b, ft_lstsize(stack_b));
			//printf("\n\n");
		}
	}
	ft_sort_a(stack_a, tail_a);
	//ft_lstprint(*stack_a);
	//ft_lstprint(stack_b);
	//printf("\n\n");
	while (ft_lstsize(stack_b) > 0)
		ft_pb(stack_a, &stack_b, 1);
	//ft_lstprint(*stack_a);
	//ft_lstprint(stack_b);
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
