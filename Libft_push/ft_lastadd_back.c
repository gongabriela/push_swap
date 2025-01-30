/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:49:34 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/01/25 14:49:47 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
	{
		return ;
	}
	if (*lst != NULL)
	{
		ft_lstlast(*lst)->next = new;
	}
	else
	{
		*lst = new;
	}
}
