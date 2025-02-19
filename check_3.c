/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:50:04 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/19 11:50:04 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_cost(t_list *node_a, t_list *head_b, int median)
{
	if (node_a->number <= median)
	{
		if (!head_b)
		{
			node_a->total_cost = node_a->cost;
			return ;
		}
		while (node_a->number < head_b->number)
			head_b = head_b->next;
		node_a->total_cost = node_a->cost + head_b->cost;
	}
	else
		node_a->total_cost = -1;
}

int	ft_check_3(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	ft_check_cost(*head_a, *head_b, median);
	ft_check_cost((*head_a)->next, *head_b, median);
	ft_check_cost(*tail_a, *head_b, median);
	printf("%d\n", (*head_a)->cost);
	return (0);
	//t_list *best_node = ft_get_best_candidate(head_a, head_a->next, tail_a);
	//t_list *node_b = ft_get_best_friend(best_node, head_b);
	//ft_move_and_sort(&best_node, &node_b);
}
