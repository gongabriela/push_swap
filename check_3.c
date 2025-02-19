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
		while (node_a->number < head_b->number && head_b->next != NULL)
			head_b = head_b->next;
		node_a->total_cost = node_a->cost + head_b->cost;
	}
	else
		node_a->total_cost = -1;
}
/*t_list	*ft_chosen_node_3(t_list *node_1, t_list *node_2, t_list *last_node)
{
	t_list *best_node;
	printf("got inside chossen node ft\n");
	if (node_1->total_cost == -1 && node_2->total_cost == -1 && last_node->total_cost == -1)
		return (NULL);
	if ((node_1->total_cost == node_2->total_cost && node_1->number < node_2->number) || (node_1->total_cost < node_2->total_cost))
		best_node = node_1;
	else
		best_node = node_2;
	if ((best_node->total_cost == last_node->total_cost && best_node->number > last_node ->number) || (best_node->total_cost > last_node->total_cost))
		best_node = last_node;
	return (best_node);
}*/

t_list	*ft_chosen_node(t_list *node_1, t_list *node_2)
{
	printf("got inside chossen node ft\n");
	if (!node_1 && node_2->total_cost == -1)
		return (NULL);
	else if (!node_1 && node_2->total_cost > -1)
		return (node_2);
	if (node_1->total_cost == -1 && node_2->total_cost == -1)
		return (NULL);
	if (node_1->total_cost == -1)
		return (node_2);
	else if (node_2->total_cost == -1)
		return (node_1);
	if ((node_1->total_cost == node_2->total_cost && node_1->number < node_2->number) || (node_1->total_cost < node_2->total_cost))
		return (node_1);
	return(node_2);
}

int	ft_check_3(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;

	ft_check_cost(*head_a, *head_b, median);
	printf("node_1 cost: %d\n", (*head_a)->number);
	ft_check_cost((*head_a)->next, *head_b, median);
	printf("node_2 cost: %d\n", (*head_a)->next->cost);
	ft_check_cost(*tail_a, *head_b, median);
	printf("last_node cost: %d\n", (*tail_a)->cost);
	best_node = ft_chosen_node(*head_a, (*head_a)->next);
	best_node = ft_chosen_node(best_node, *tail_a);
	if (!best_node)
		return (1);
	printf("number: %d and cost: %d\n", best_node->number, best_node->cost);
	//t_list *node_b = ft_get_best_friend(best_node, head_b);
	//ft_move_and_sort(&best_node, &node_b); //usar a position que ta guardada no node!! quase esqueci disso kkkkk
	return (0);
}
