/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:35:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/05 12:29:27 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

void	ft_error();
int		ft_isspace(int c);
long			ft_atol(const char *str);
void	ft_free_char_args(char **char_args);
char	**ft_divide_argv(int argc, char **argv);
int	ft_check_args(char **char_args);
int	ft_check_duplicates(int	*int_args, int size);
int	*ft_char_to_int(char **char_args, int i);
t_list	*ft_new_node(int	number);
void ft_lstprint(t_list *head);
void	ft_free_lst(t_list **head);
void	ft_init_stack(t_list **stack_a, t_list **tail, int *int_args, int size);
int	ft_check_if_sorted(int *int_args, int args_size);
int	ft_find_median(int *int_args, int args_size);

#endif
