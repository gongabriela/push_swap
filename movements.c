/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:42:06 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/21 19:42:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_mov(int index, char *mov)
{
	char	*str;
	int		i;

	str = "abrs";
	i = 0;
	if (index >= 0 && index <= 3 && mov[0] != '\0')
	{
		while (mov[i])
		{
			write(1, &mov[i], 1);
			i++;
		}
		write(1, &str[index], 1);
		write(1, "\n", 1);
	}
}

void	ft_pa_pb(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*node_a;

	if (!(*stack_a))
		return ;
	node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	if (!(*stack_b))
	{
		*stack_b = node_a;
		node_a->next = NULL;
		node_a->previous = NULL;
	}
	else
	{
		node_a->next = *stack_b;
		(*stack_b)->previous = node_a;
		*stack_b = node_a;
	}
	ft_print_mov(flag, "p");
}

void	ft_sa_sb(t_list **head, int flag)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;

	node_3 = NULL;
	node_1 = *head;
	node_2 = (*head)->next;
	if (ft_lstsize(*head) > 2)
		node_3 = node_2->next;
	*head = (*head)->next;
	node_2->previous = NULL;
	node_2->next = node_1;
	node_1->previous = node_2;
	if (node_3 != NULL)
	{
		node_1->next = node_3;
		node_3->previous = node_1;
	}
	else
		node_1->next = NULL;
	ft_print_mov(flag, "s");
}

void	ft_ra_rb(t_list **stack, int flag)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	ft_print_mov(flag, "r");
}

void	ft_rra_rrb(t_list **stack, int flag)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	new_last = last->previous;
	*stack = last;
	first->previous = last;
	last->previous = NULL;
	last->next = first;
	new_last->next = NULL;
	ft_print_mov(flag, "rr");
}
