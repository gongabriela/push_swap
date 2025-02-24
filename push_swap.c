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
	t_list *stack_b;

	stack_b = NULL;
	/*median = get_median(*stack_a);
	if (check_trio(stack_a, tail_a, &stack_b, median))
		check_duo(stack_a, tail_a, &stack_b, median);
	ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
	ft_init_node_b(stack_b, ft_lstsize(stack_b));
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);*/

	//printf("median: %d\n", median);
	while(ft_lstsize(*stack_a) != 2)
	{
		median = get_median(*stack_a);
		//printf("median: %d\n", median);
		if (check_trio(stack_a, tail_a, &stack_b, median))
			check_duo(stack_a, tail_a, &stack_b, median);
		ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
		ft_init_node_b(stack_b, ft_lstsize(stack_b));
		//ft_lstprint(*stack_a);
		//ft_lstprint(stack_b);
		/*t_list *temp = stack_b;
		while (temp != NULL)
		{
			if (temp->previous != NULL)
				printf("previous: %d\n", temp->previous->number);
			printf("position: %d\n", temp->position);
			printf("number: %d\n", temp->number);
			printf("direction: %c\n", temp->direction);
			printf("cost: %d\n", temp->cost);
			printf("total cost: %d\n", temp->total_cost);
			if (temp->next != NULL)
				printf("next: %d\n\n", temp->next->number);
			temp = temp->next;
		}
		printf("\n\n");*/
	}
	//ft_sort_a(stack_a, &stack_b, tail_a);
	//ft_back_to_a(stack_a, &stack_b);
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*tail_a;

	stack_a = NULL;
	ft_init_stack(argc, argv, &stack_a, &tail_a);
	sorting_algorithm(&stack_a, &tail_a);
	//ft_lstprint(stack_a);
	/*t_list *temp = stack_a;
	while (temp != NULL)
	{
		if (temp->previous != NULL)
			printf("previous: %d\n", temp->previous->number);
		printf("position: %d\n", temp->position);
		printf("number: %d\n", temp->number);
		printf("direction: %c\n", temp->direction);
		printf("cost: %d\n", temp->cost);
		printf("total cost: %d\n", temp->total_cost);
		if (temp->next != NULL)
			printf("next: %d\n\n", temp->next->number);
		temp = temp->next;
	}*/
	ft_free_lst(&stack_a);
	return (0);
}
