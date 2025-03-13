/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:17:10 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/13 17:17:10 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list **head)
{
	t_list	*node;
	t_list	*temp;

	if (head == NULL || *head == NULL)
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

void	ft_free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_init_stack(t_list **stack_a, char **args)
{
	if (stack_a)
		ft_free_lst(stack_a);
	if (args)
		ft_free_args(args);
	ft_error();
}
