/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:43:20 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/03/10 14:43:20 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return ;
	ft_rra_rrb(stack_a, -1);
	ft_rra_rrb(stack_b, -1);
	if (flag > 0)
		write(1, "rrr\n", 4);
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int flag)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return ;
	ft_ra_rb(stack_a, -1);
	ft_ra_rb(stack_b, -1);
	if (flag > 0)
		write(1, "rr\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_ra_rb(stack_a, -1);
	ft_ra_rb(stack_b, -1);
}
