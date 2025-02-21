/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:50:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/21 15:50:12 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_node_a_bottom(t_list *new_node, int i)
{
	while (i > 0)
	{
		new_node->position = i;
		new_node->direction = 'b';
		new_node->total_cost = -2;
		new_node->cost = i + 1 + (i - 1);
		new_node = new_node->next;
		i--;
	}
}

//FUNCAO COM MAIS DE 25 LINHAS DEIXA DE PREGUICA E VAI DIVIDIR
void	ft_init_node_a(t_list *new_node, int size)
{
	int	i;

	i = 1;
	while (i <= (size + 1) / 2)
	{
		new_node->position = i;
		new_node->direction = 't';
		new_node->total_cost = -2;
		if (i == 1)
			new_node->cost = 1;
		else
			new_node->cost = i + (i - 2);
		i++;
		new_node = new_node->next;
	}
	if (size % 2 == 0)
		i = i - 1;
	else
		i = i - 2;
	ft_init_node_a_bottom(new_node, i);
}
void	ft_init_node_b_bottom(t_list *stack_b, int i)
{
	while (i > 0)
	{
		stack_b->position = i;
		stack_b->direction = 'b';
		stack_b->total_cost = -2;
		stack_b->cost = (i * 2) + (i + 1);
		stack_b = stack_b->next;
		i--;
	}
}
void	ft_init_node_b(t_list *stack_b, int size)
{
	int	i;

	i = 1;
	while (i <= (size + 1) / 2)
	{
		stack_b->position = i;
		stack_b->direction = 't';
		stack_b->total_cost = -2;
		if (i == 1)
			stack_b->cost = 0;
		else
			stack_b->cost = ((i - 2) * 2) + 1 + (i - 2);
		i++;
		stack_b = stack_b->next;
	}
	if (size % 2 == 0)
		i = i - 1;
	else
		i = i - 2;
	ft_init_node_b_bottom(stack_b, i);
}
