/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:40:02 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/06 15:04:38 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_list **head, int flag)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *head;
	second_node = (*head)->next;
	if (ft_lstsize(*head) >= 2)
	{
		first_node->next = second_node->next;
		second_node->next = first_node;
		*head = second_node;
	}
	ft_print_mov(flag, "s");
}

ft_ss(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_sa_sb(&stack_a, -1);
	ft_sa_sb(&stack_b, -1);
	ft_print_mov(flag, "s");
}
void	ft_pa_pb(t_list **stack_1, t_list **stack_2, int flag)
{
	t_list	*first_node_1;

	first_node_1 = *stack_1;
	*stack_1 = first_node_1->next;

	first_node_1->next = *stack_2;
	*stack_2 = first_node_1;
	ft_print_mov(flag, "p");
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
	last->next = first;
	first->next = NULL;
	ft_check_flag(flag, "r");
}
ft_rr(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_ra_rb(&stack_a, -1);
	ft_ra_rb(&stack_b, -1);
	ft_print_mov(flag, "r");
}
void	ft_rra_rrb(t_list **stack, int flag)
{
	t_list	*second_last;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack);
	second_last = *stack;
	while (size > 2)
	{
		second_last = second_last->next;
		size--;
	}
	last = second_last->next;
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
	ft_print_mov(flag, "rr");
}
ft_rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_rra_rrb(stack_a, -1);
	ft_rra_rrb(stack_b, -1);
	ft_print_mov(flag, "rr");
}
//0 = a | 1 = b | 2 = r | 3 = s | -1 = dont print anything
void	ft_print_mov(int index, char *mov)
{
	char	*str = "abrs";
	int i;

	i = 0;
	if (index >= 0 && index <= 3 && !mov)
	{
		while(mov[i])
			write(1, &mov[i++], 1);
		write(1, &str[index], 1);
	}
}
