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
	node->previous = NULL;
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
		new_node->previous = tail_a;
		tail_a->next = new_node;
		tail_a = tail_a->next;
	}
}

int	ft_lstsize(t_list *head)
{
	t_list	*temp;
	int		i;

	temp = head;
	if (!temp)
		return (0);
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
