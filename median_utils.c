/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:29:49 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/19 10:29:49 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_check_if_sorted(int *int_args, int args_size)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 0;
	while (i < args_size - 1)
	{
		if (int_args[i] > int_args[i + 1])
		{
			sorted = 1;
			break;
		}
		i++;
	}
	return(sorted);
}

int	*init_int_args(t_list *stack_a, int size)
{
	t_list	*head_a;
	int		*args;
	int		i;

	head_a = stack_a;
	args = ft_calloc(size, sizeof(int));
	i = 0;
	while (head_a != NULL)
	{
		args[i] = head_a->number;
		head_a = head_a->next;
		i++;
	}
	return (args);
}

int	*get_chunks(int *args, int size)
{
	int	*chunks;
	int	i;
	int div;

	chunks = malloc(5 * sizeof(int));
	div = size / 5;
	i = 0;
	while (i < 5)
	{
		chunks[i] = args[div * (i + 1)];
		i++;
	}
	chunks[i] = args[size - 1];
	return (chunks);
}

int	*get_median(t_list *stack_a)
{
	int	*args;
	int	*chunks;
	int	size;
	int	i;
	int	temp;

	size = ft_lstsize(stack_a);
	args  = init_int_args(stack_a, size);
	while (ft_int_check_if_sorted(args, size))
	{
		i = 0;
		while (i < size - 1) //pq tem que ser args_size - 1? por causa do int_args[i + 1]!
		{
			if (args[i] > args[i + 1])
			{
				temp = args[i];
				args[i] = args[i + 1];
				args[i + 1] = temp;
			}
			i++;
		}
	}
	chunks = get_chunks(args, size);
	return (free(args), chunks);
}

