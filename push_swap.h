/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/01/30 17:26:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

void	ft_error();
char	**ft_divide_argv(int argc, char **argv);
int		*ft_check_args(char **char_args);
int		*ft_char_to_int(char **char_args, int i);
void	*ft_init_stack(int *int_args, int	size, t_list **stack_a);
int		ft_find_median(int *int_args, int args_size);
#endif
