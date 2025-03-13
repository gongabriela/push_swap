/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:06 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/11 18:54:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (ft_check_duplicates(stack_a))
		ft_error_init_stack(stack_a, args);
	ft_free_args(args);
}

int	perform_movements(t_list **stack_a, t_list **stack_b, char *mov)
{
	if (!ft_strncmp("pa\n", mov, ft_strlen(mov)))
		ft_pa_pb(stack_b, stack_a, -1);
	else if (!ft_strncmp("pb\n", mov, ft_strlen(mov)))
		ft_pa_pb(stack_a, stack_b, -1);
	else if (!ft_strncmp("ra\n", mov, ft_strlen(mov)))
		ft_ra_rb(stack_a, -1);
	else if (!ft_strncmp("rb\n", mov, ft_strlen(mov)))
		ft_ra_rb(stack_b, -1);
	else if (!ft_strncmp("rr\n", mov, ft_strlen(mov)))
		ft_rr(stack_a, stack_b, -1);
	else if (!ft_strncmp("rra\n", mov, ft_strlen(mov)))
		ft_rra_rrb(stack_a, -1);
	else if (!ft_strncmp("rrb\n", mov, ft_strlen(mov)))
		ft_rra_rrb(stack_b, -1);
	else if (!ft_strncmp("rrr\n", mov, ft_strlen(mov)))
		ft_rrr(stack_a, stack_b, -1);
	else if (!ft_strncmp("sa\n", mov, ft_strlen(mov)))
		ft_sa_sb(stack_a, -1);
	else if (!ft_strncmp("sb\n", mov, ft_strlen(mov)))
		ft_sa_sb(stack_b, -1);
	else if (!ft_strncmp("ss\n", mov, ft_strlen(mov)))
		ft_ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*mov;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_init_stack(argc, argv, &stack_a);
	if (ft_check_if_sorted(stack_a))
		return (ft_free_lst(&stack_a), write(1, "OK\n", 3));
	mov = get_next_line(0);
	while (mov != NULL)
	{
		if (!perform_movements(&stack_a, &stack_b, mov))
			return (free(mov), ft_free_lst(&stack_a), ft_free_lst(&stack_b),
				write(2, "Error\n", 6));
		free(mov);
		mov = get_next_line(0);
	}
	if (ft_check_if_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		return (free(mov), ft_free_lst(&stack_a), write(1, "OK\n", 3));
	return (free(mov), ft_free_lst(&stack_a), ft_free_lst(&stack_b),
		write(1, "KO\n", 3));
}
