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
	if (ft_lstsize(*stack_a) == 1 || ft_check_if_sorted(stack_a) || ft_check_duplicates(stack_a))
		ft_error_init_stack(stack_a, args);
	ft_init_node(*stack_a, ft_lstsize(*stack_a));
	ft_free_args(args);
}

t_list	*ft_lastnode(t_list *stack_a)
{
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tail_a;

	stack_a = NULL;
	ft_init_stack(argc, argv, &stack_a);
	sorting_algorithm(&stack_a, &tail_a);
	ft_free_lst(&stack_a);
	return (0);
}

/* testing variables of the nodes
while (stack_a != NULL)
	{
		printf("element: %d\n", stack_a->number);
		printf("direction: %s\n", stack_a->direction);
		printf("position: %d\n", stack_a->position);
		printf("cost: %d\n\n", stack_a->cost);
        stack_a = stack_a->next;
    }*/
