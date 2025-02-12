/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:27:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/11 14:27:26 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_median(t_list *head_a)
{
	int	*args;
	int	size;
	int	i;
	int	temp;

	size = ft_lstsize(head_a);
	args  = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		args[i] = head_a->number;
		head_a = head_a->next;
		i++;
	}
	i = 0;
	while (ft_check_if_sorted(args, size))
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
	i = size / 2;
	if (size % 2 == 1)
		return (args[i]);
	return (free(args), args[i - 1]);
}
int	ft_check_3(t_list ***head_a, t_list **head_b, int median)
{
	/*t_list	*first_node;
	t_list	*second_node;
	t_list	*last_node;

	first_node = head_a;
	second_node = head_a->next;
	last_node = ft_lstlast(head_a);*/ //tem que add essa funcao ou encontrar outra solucao
	int	first_node;
	int	second_node;
	int	last_node;

	first_node = ft_check_node(head_a, head_b, median);
	second_node = ft_check_node(head_a->next, head_b, median);
	last_node = ft_check_node(ft_lstlast(head_a), head_b, median);

}
void	ft_sorting(t_list **head_a)
{
	t_list	*head_b;
	int		median;

	head_b = NULL;
	while(ft_lstsize(*head_a) != 3)
	{
		median = ft_get_median(*head_a);
		if(ft_check_3(&head_a, &head_b, median))
			ft_check_2(&head_a, &head_b, median);
	}
	ft_sort_3(&head_a);
	ft_b_to_a(&head_a, &head_b);
	if(ft_is_stack_sorted(&head_a) && head_b == NULL)
		ft_free_lst(*stack_a);
	else
		ft_error();
}
