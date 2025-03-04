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
	if (ft_lstsize(*stack_a) == 1 || ft_check_if_sorted(stack_a) || ft_check_duplicates(stack_a)) //sera que o check_duplicates tem que estar primeiro? para retornar erro...
		ft_error_init_stack(stack_a, args);
	ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
	ft_free_args(args);
}
//find the targets of the nodes of stack_a
//update total cost
//pay attention to the rrr
void	update_targets_of_stack_a(t_list *stack, t_list *target_stack)
{
	t_list	*temp;
	t_list	*target;

	while (stack != NULL)
	{
		temp = target_stack;
		target = NULL;
		while (temp != NULL)
		{
			if (temp->number < stack->number)
			{
				if (target == NULL)
					target = temp;
				else if (target->number < temp->number)
					target = temp;
			}
			temp = temp->next;
		}
		if (target == NULL)
			stack->target_node = NULL;
		else
			stack->cost = stack->cost + target->cost;
			stack->target_node = target;
		stack = stack->next;
	}
}
//update cost of sending the node to the top of the stack
void	update_cost(t_list *stack, int size)
{
	int	i;

	i = 0;
	while (++i <= (size + 1) / 2)
	{
		stack->index = i;
		stack->direction = 't';
		if (i == 1)
			stack->cost = 1;
		else
			stack->cost = i + (i - 2);
		stack = stack->next;
	}
	if (size % 2 != 0)
		i = i - 1;
	while (--i > 0)
	{
		stack->index = i;
		stack->direction = 'b';
		stack->cost = i + 1 + (i - 1);
		stack = stack->next;
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

void	push_and_sort_node(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int	counter;

	if (!(*stack_b))
	{
		ft_pb(stack_a, stack_b, 1);
		if (ft_lstsize(*stack_a) > 3)
			ft_pb(stack_a, stack_b, 1);
		return;
	}
}

void	sort_node_in_b(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) == 2)
		return ;
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
	}
	//sort_3();
	while (ft_lstsize(*stack_b) > 0)
	{
		update_cost(*stack_a, ft_lstsize(*stack_a));
		update_cost(*stack_b, ft_lstsize(*stack_b));
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	ft_init_stack(argc, argv, &stack_a);

	//if (ft_lstsize == 2)
		//sort_2();
	//else if (ft_lstsize == 3)
		//sort_3();
	//else
	sorting_algorithm(&stack_a, &stack_b);

	ft_free_lst(&stack_a);

	return (0);
}

//algoritmo antigo
