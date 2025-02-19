/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:37 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/18 17:17:37 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sorting_algorithm(t_list **stack_a, t_list **tail_a)
{
	t_list *stack_b;
	int		median;

	stack_b = NULL;
	while (ft_lstsize(stack_a) != 3)
	{
		median = ft_get_median(stack_a);
		if(ft_check_3(stack_a, tail_a, stack_b))
			ft_check_2(stack_a, tail_a, stack_b);
		ft_update_nodes(stack_a, stack_b);
	}
	ft_sort_last_3(stack_a);
	ft_b_to_a(stack_a, stack_b);
}*/
//para teste:
void	sorting_algorithm(t_list **stack_a, t_list **tail_a)
{
	int		median;
	t_list *node_b;

	node_b =  ft_new_node("4");
	node_b->cost = 0;
	node_b->next = NULL;
	printf("init node b nbr: %d\n", node_b->number);
	median = ft_get_median(stack_a);
	printf("median: %d\n", median);
	ft_check_3(stack_a, tail_a, &node_b, median);
}
