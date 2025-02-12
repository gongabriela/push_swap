/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/12 15:53:45 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_list
{
	struct s_list	*previous;
	int				position;
	int				number;
	char			*direction;
	int				cost;
	struct s_list	*next;
}					t_list;

void	ft_sa_sb(t_list **head, int flag);
void	ft_ss(t_list **stack_a, t_list **stack_b, int flag);
void	ft_pa_pb(t_list **stack_1, t_list **stack_2, int flag);
void	ft_ra_rb(t_list **stack, int flag);
void	ft_rr(t_list **stack_a, t_list **stack_b, int flag);
void	ft_rra_rrb(t_list **stack, int flag);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int flag);
void	ft_print_mov(int index, char *mov);

#endif
