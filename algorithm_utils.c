/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/04 16:57:10 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//update cost of sending the node to the top of the stack
//does not count pb so that we can use this function for boths stacks
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
t_list	*find_cheaper_node(t_list *stack_a)
{
	t_list *temp_a;
	t_list *node;

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


void	node_to_top_b(t_list **stack_b, t_list *node, int flag)
{
	int		counter;

	if (flag == 1)
		node = node->target_node;

	if (node->direction == 't')
	{
		if (node->index == 1 || ft_lstsize(*stack_b) == 1) //problema quando o node ja e 1
			return ;
		counter = node->index - 2;
		while (counter-- > 0)
			ft_ra_rb(stack_b, 1);
		ft_sa_sb(stack_b, 1);
	}
	else
	{
		if (node->index == 1)
			return(ft_rra_rrb(stack_b, 1));
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
		counter = node->index - 2;
		while (counter-- > 0)
			ft_ra_rb(stack_a, 0);
		ft_sa_sb(stack_a, 0);
	}
	else
	{
		if (node->index == 1)
			return(ft_rra_rrb(stack_a, 0));
		counter = node->index;
		while (counter-- > 0)
			ft_rra_rrb(stack_a, 0);
	}
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
			target = min_value(stack_b);
		stack_b->cost = stack_b->cost + target->cost;
		stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	sort_3(t_list **stack_a) //Define a function that handles when stack `a` has three nodes, and sorts it
{
	t_list	*max; //To store a pointer to the biggest node in stack `a`

	max = max_value(*stack_a);
	if (max == *stack_a) //Check if the current node is the biggest
		ft_ra_rb(stack_a, 0); //If so, rotate the top node to the bottom of the stack
	else if ((*stack_a)->next == max) //Check if the second node is the biggest
		ft_rra_rrb(stack_a, 0); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*stack_a)->number > (*stack_a)->next->number) //Check if the bottom node is the biggest, but the top node is higher than the second node
		ft_sa_sb(stack_a, 0); //If so, simply swap the top and second nodes
}

