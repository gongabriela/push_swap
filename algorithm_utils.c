/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:45:22 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/21 19:45:22 by ggoncalv         ###   ########.fr       */
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
		if (head_b->next == NULL && head_b->number > node_a->number)
			node_a->total_cost = node_a->cost + 1; //vai so fazer rrb e por no fim
		else
			node_a->total_cost = node_a->cost + head_b->cost;
	}
	else
		node_a->total_cost = -1;
}

t_list	*ft_chosen_node(t_list *node_1, t_list *node_2)
{
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
int	check_trio(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;

	ft_check_cost(*head_a, *head_b, median);
	ft_check_cost((*head_a)->next, *head_b, median);
	ft_check_cost(*tail_a, *head_b, median);
	best_node = ft_chosen_node(*head_a, (*head_a)->next);
	best_node = ft_chosen_node(best_node, *tail_a);
	if (!best_node)
		return (1);
	ft_move_and_sort(head_a, head_b, tail_a, best_node);

	return (0);
}
void	check_duo(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;
	t_list	*temp_head;
	t_list	*temp_tail;

	temp_head = (*head_a)->next;
	temp_tail = *tail_a;
	while (temp_head->total_cost == -1 && temp_tail->total_cost == -1)
	{
		temp_head = temp_head->next;
		temp_tail = temp_tail->previous;
		ft_check_cost(temp_head, *head_b, median);
		ft_check_cost(temp_tail, *head_b, median);
	}
	best_node = ft_chosen_node(temp_head, temp_tail);
	ft_move_and_sort(head_a, head_b, tail_a, best_node);
}

void	ft_sort_a(t_list **head_a, t_list **tail_a)
{
	while (!ft_check_if_sorted(head_a))
	{
		if ((*head_a)->number > (*head_a)->next->number)
			ft_sa_sb(head_a, 0);
		if ((*head_a)->number > (*tail_a)->number)
			ft_ra_rb(head_a, 0);
		if ((*head_a)->next->number > (*tail_a)->number)
		{
			ft_rra_rrb(head_a, 0);
			ft_sa_sb(head_a, 0);
		}
	}
}
