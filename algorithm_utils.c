/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost(t_list *stack, int size)
{
	int	i;

	i = 0;
	while (++i <= (size + 1) / 2)
	{
		stack->index = i;
		stack->direction = 't';
		stack->cost = i - 1;
		stack = stack->next;
	}
	if (size % 2 != 0)
		i = i - 1;
	while (--i > 0)
	{
		stack->index = i;
		stack->direction = 'b';
		stack->cost = i;
		stack = stack->next;
	}
}

void	update_targets_of_stack_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	t_list	*target;

	while (stack_a != NULL)
	{
		temp = stack_b;
		target = NULL;
		while (temp != NULL)
		{
			if (temp->number < stack_a->number)
			{
				if (target == NULL)
					target = temp;
				else if (target->number < temp->number)
					target = temp;
			}
			temp = temp->next;
		}
		if (target == NULL)
			target = max_value(stack_b);
		stack_a->cost = stack_a->cost + target->cost;
		stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void	node_to_top_b(t_list **stack_b, t_list *node, int flag)
{
	int		counter;

	if (flag == 1)
		node = node->target_node;
	if (node->direction == 't')
	{
		if (node->index == 1 || ft_lstsize(*stack_b) == 1)
			return ;
		counter = node->index - 1;
		while (counter-- > 0)
			ft_ra_rb(stack_b, 1);
	}
	else
	{
		if (node->index == 1)
			return (ft_rra_rrb(stack_b, 1));
		counter = node->index;
		while (counter-- > 0)
			ft_rra_rrb(stack_b, 1);
	}
}

void	node_to_top_a(t_list **stack_a, t_list *node, int flag)
{
	int		counter;

	if (flag == 1)
		node = node->target_node;
	if (node->direction == 't')
	{
		if (node->index == 1)
			return ;
		counter = node->index - 1;
		while (counter-- > 0)
			ft_ra_rb(stack_a, 0);
	}
	else
	{
		if (node->index == 1)
			return (ft_rra_rrb(stack_a, 0));
		counter = node->index;
		while (counter-- > 0)
			ft_rra_rrb(stack_a, 0);
	}
}

void	update_targets_of_stack_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	t_list	*target;

	while (stack_b != NULL)
	{
		temp = stack_a;
		target = NULL;
		while (temp != NULL)
		{
			if (temp->number > stack_b->number)
			{
				if (target == NULL)
					target = temp;
				else if (target->number > temp->number)
					target = temp;
			}
			temp = temp->next;
		}
		if (target == NULL)
			target = min_value(stack_a);
		stack_b->cost = stack_b->cost + target->cost;
		stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}
