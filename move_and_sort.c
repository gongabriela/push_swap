/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:23:57 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/21 21:23:57 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_top_a(t_list **head_a, t_list **head_b, t_list *best_node)
{
	int	counter;

	if (best_node->position == 1)
		return(ft_pa_pb(head_a, head_b, 1));
	else
	{
		counter = best_node->position - 2;
		while (counter-- > 0)
			ft_ra_rb(head_a, 0);
		ft_sa_sb(head_a, 0);
		ft_pa_pb(head_a, head_b, 1);
		/*counter = best_node->position - 2;
		while (counter-- > 0)
			ft_rra_rrb(head_a, 0);*/
	}
}

void	ft_move_bottom_a(t_list **head_a, t_list **head_b, t_list *best_node)
{
	int	counter;

	if (best_node->position == 1)
		return(ft_rra_rrb(head_a, 0), ft_pa_pb(head_a, head_b, 1));
	else
	{
		counter = best_node->position;
		while (counter-- > 0)
			ft_rra_rrb(head_a, 0);
		ft_pa_pb(head_a, head_b, 1);
		/*counter = best_node->position - 1;
		while (counter-- > 0)
			ft_ra_rb(head_a, 0);*/
	}
}

void	ft_sort_top_b(t_list **head_b, t_list *node_b)
{
	int	counter;

	if (ft_lstsize(*head_b) == 2 || node_b->position == 1)
	{
		if (node_b->number > (*head_b)->number)
			return (ft_rra_rrb(head_b, 1));
		return ;
	}
	else
	{
		counter = node_b->position - 2;
		while (counter-- > 0)
		{
			ft_sa_sb(head_b, 1);
			ft_ra_rb(head_b, 1);
		}
		ft_sa_sb(head_b, 1);
		counter = node_b->position - 2;
		while (counter-- > 0)
			ft_rra_rrb(head_b, 1);
	}
}

//parece que nao ta performando os movimentos...
void	ft_sort_bottom_b(t_list **head_b, t_list *node_b)
{
	int	counter;

	if (ft_lstsize(*head_b) == 2 || node_b->position == 1)
	{
		if (node_b->number > (*head_b)->number)
			return (ft_ra_rb(head_b, 1));
	}
	if (ft_lstsize(*head_b) == 2)
		return ;
	else
	{
		counter = node_b->position;
		while (counter-- > 0)
		{
			ft_rra_rrb(head_b, 1);
			ft_sa_sb(head_b, 1);
		}
		counter = node_b->position + 1;
		while (counter-- > 0)
			ft_ra_rb(head_b, 1);
	}
}
t_list	*ft_lstlast(t_list **head_a)
{
	t_list *tail_a;

	tail_a = *head_a;
	while(tail_a->next != NULL)
		tail_a = tail_a->next;
	return (tail_a);
}
void	ft_move_and_sort(t_list **head_a, t_list **head_b, t_list **tail_a, t_list *best_node)
{
	t_list	*node_b;

	if (best_node->direction == 't')
		ft_move_top_a(head_a, head_b, best_node);
	else
		ft_move_bottom_a(head_a, head_b, best_node);
	if (ft_lstsize(*head_b) == 1)
		return ;
	*tail_a = ft_lstlast(head_a);
	node_b = *head_b;
	while (best_node->number <= node_b->number && node_b->next != NULL)
		node_b = node_b->next;
	if (node_b->direction == 't')
		ft_sort_top_b(head_b, node_b);
	else
		ft_sort_bottom_b(head_b, node_b);
}
