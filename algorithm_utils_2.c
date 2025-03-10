/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:15:18 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/06 12:15:18 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_value(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack != NULL)
	{
		if (stack->number > max->number)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*min_value(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack != NULL)
	{
		if (stack->number < min->number)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*find_cheaper_node(t_list *stack_a)
{
	t_list	*temp_a;
	t_list	*node;

	temp_a = stack_a;
	node = stack_a;
	while (temp_a != NULL)
	{
		if (temp_a->cost < node->cost)
			node = temp_a;
		temp_a = temp_a->next;
	}
	return (node);
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
		update_cost_rr_rrr(stack_a, target);
		stack_a->target_node = target;
		stack_a = stack_a->next;
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
		update_cost_rr_rrr(stack_b, target);
		stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}
