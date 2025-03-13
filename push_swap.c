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

void	ft_init_stack(int argc, char **argv, t_list **stack_a)
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
			if (new_node == NULL)
				ft_error_init_stack(stack_a, args);
			ft_lstadd_back(stack_a, new_node);
		}
		i++;
	}
	if (ft_check_duplicates(stack_a))
		ft_error_init_stack(stack_a, args);
	ft_free_args(args);
}

void	sort_3(t_list **stack_a)
{
	t_list	*max;

	max = max_value(*stack_a);
	if (max == *stack_a)
		ft_ra_rb(stack_a, 0);
	else if ((*stack_a)->next == max)
		ft_rra_rrb(stack_a, 0);
	if ((*stack_a)->number > (*stack_a)->next->number)
		ft_sa_sb(stack_a, 0);
}

void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	while (ft_lstsize(*stack_a) > 3)
	{
		update_cost(*stack_a, ft_lstsize(*stack_a));
		update_cost(*stack_b, ft_lstsize(*stack_b));
		update_targets_of_stack_a(*stack_a, *stack_b);
		node = find_cheaper_node(*stack_a);
		node_to_top(stack_a, stack_b, node, 0);
		ft_pa_pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		update_cost(*stack_a, ft_lstsize(*stack_a));
		update_cost(*stack_b, ft_lstsize(*stack_b));
		update_targets_of_stack_b(*stack_a, *stack_b);
		node = find_cheaper_node(*stack_b);
		node_to_top(stack_a, stack_b, node, 1);
		ft_pa_pb(stack_b, stack_a, 0);
	}
	update_cost(*stack_a, ft_lstsize(*stack_a));
	node_to_top_a(stack_a, min_value(*stack_a), 0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_init_stack(argc, argv, &stack_a);
	if (ft_lstsize(stack_a) == 2 && !ft_check_if_sorted(stack_a))
		ft_sa_sb(&stack_a, 0);
	else if (ft_lstsize(stack_a) == 3 && !ft_check_if_sorted(stack_a))
		sort_3(&stack_a);
	else if (!ft_check_if_sorted(stack_a))
	{
		ft_pa_pb(&stack_a, &stack_b, 1);
		if (ft_lstsize(stack_a) > 3)
			ft_pa_pb(&stack_a, &stack_b, 1);
		sorting_algorithm(&stack_a, &stack_b);
	}
	ft_free_lst(&stack_a);
	return (0);
}

//algoritmo antigo
