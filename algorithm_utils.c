/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/11 19:09:55 by ggoncalv         ###   ########.fr       */
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

void	update_cost_rr_rrr(t_list *node, t_list *target)
{
	int	counter;
	int	i;

	if ((node->direction == 't' && target->direction == 't'
			&& node->index != 1 && target->index != 1)
		|| (node->direction == 'b' && target->direction == 'b'))
	{
		if (node->index <= target->index)
		{
			counter = node->index;
			i = target->index - node->index;
		}
		else
		{
			counter = target->index;
			i = node->index - target->index;
		}
		if (node->direction == 't' && target->direction == 't'
			&& node->index != 1 && target->index != 1)
			counter = counter - 1;
		node->cost = counter + i;
	}
	else
		node->cost = node->cost + target->cost;
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

void	node_to_top(t_list **stack_a, t_list **stack_b, t_list *node, int flag)
{
	int	counter;

	if (node->index <= node->target_node->index)
		counter = node->index;
	else
		counter = node->target_node->index;
	if (node->direction == 't' && node->target_node->direction == 't'
		&& node->index != 1 && node->target_node->index != 1)
	{
		counter = counter - 1;
		while (counter-- > 0)
			ft_rr(stack_a, stack_b, 1);
	}
	else if (node->direction == 'b' && node->target_node->direction == 'b')
		while (counter-- > 0)
			ft_rrr(stack_a, stack_b, 1);
	update_cost(*stack_a, ft_lstsize(*stack_a));
	update_cost(*stack_b, ft_lstsize(*stack_b));
	if (flag == 0)
		counter = 1;
	else
		counter = 0;
	node_to_top_a(stack_a, node, flag);
	node_to_top_b(stack_b, node, counter);
}
