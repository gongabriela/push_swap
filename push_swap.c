/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:52:45 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:45 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(int argc, char **argv, t_list **stack_a)
{
	t_list	*new_node;
	char	**args;
	int		i;

	args = ft_divide_args(argc, argv);
	i = 0;
	while (args[i])
	{
		if (ft_check_args(args[i]))
			ft_error_init_stack(stack_a, args);
		else
		{
			new_node = ft_new_node(args[i]);
			if (new_node == NULL)
				ft_error_init_stack(stack_a, args);
			ft_lstadd_back(stack_a, new_node);
		}
		i++;
	}
	if (ft_lstsize(*stack_a) == 1 || ft_check_if_sorted(stack_a) || ft_check_duplicates(stack_a))
		ft_error_init_stack(stack_a, args);
	ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
	ft_free_args(args);
}

void	ft_first_split(t_list **stack_a, t_list **stack_b)
{
	ft_init_ranges(*stack_a);
	while (check_if_divided(*stack_a))
	{
		if (check_range("min"))
			ft_bottom_a(stack_a);
		else if (check_range("mid"))
			ft_bottom_b(stack_a);
		else
			ft_top_b(stack_a);
	}
}

void	ft_split_max(t_list **stack_a, t_list **stack_b)
{
	ft_re_init_ranges(*stack_a); //fazer essa funcao ser comum aos casos mid e min tb?

	while (check_if_divided(*stack_a))
	{
		if (check_range("min"))
			ft_bottom_b(stack_a);
		else if (check_range("mid"))
			ft_top_b(stack_a);
		else
			ft_bottom_a(stack_a);
	}
	if (!check_if_divided(*stack_a))
		ft_split_max(stack_a, stack_b);

	if (ft_lstsize(*stack_a) > 2)
		return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argc, argv, &stack_a);

	ft_first_split(&stack_a, &stack_b);

	ft_split_max(&stack_a, &stack_b);
	ft_split_mid(&stack_a, &stack_b);
	ft_split_min(&stack_a, &stack_b);
	ft_free_lst(&stack_a);
	return (0);
}
