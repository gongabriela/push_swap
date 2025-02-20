/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:46:53 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/14 16:46:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(char	*args)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = ft_atol(args);
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **stack_a, t_list *new_node)
{
	static t_list	*tail_a;

	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		tail_a = new_node;
	}
	else
	{
		tail_a->next = new_node;
		tail_a = tail_a->next;
	}
}

int	ft_lstsize(t_list *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

//FUNCAO COM MAIS DE 25 LINHAS DEIXA DE PREGUICA E VAI DIVIDIR
void	ft_init_node(t_list *new_node, int size)
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
