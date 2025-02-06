/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:40:17 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/06 15:13:21 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	ft_putendl_fd("Error", 2);
	exit(0);
}
t_list	*ft_new_node(int	number)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}
void ft_lstprint(t_list *head)
{
	int	value;

	while (head != NULL)
	{
		value = head->number;
        ft_printf("%d ", value);
        head = head->next;
    }
}
void	ft_free_lst(t_list **head)
{
	t_list	*node;
	t_list	*temp;

	if (*head == NULL)
		return ;
	node = *head;
	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*head = NULL;
}
int	ft_lstsize(t_list *head) //igual lstsize da libft
{
	int	i;

	i = 0;
	while(head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}
