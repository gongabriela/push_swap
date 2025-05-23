/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:12:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/14 17:12:12 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_empty_string(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] == ' ')
		i++;
	if (argv[1][i] == '\0')
		ft_error();
}

char	**ft_divide_args(int argc, char **argv)
{
	char	**char_args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		check_empty_string(argv);
		char_args = ft_split(argv[1], ' ');
		if (char_args == NULL)
			ft_error();
	}
	else
	{
		char_args = ft_calloc(argc, sizeof(char *));
		if (char_args == NULL)
			ft_error();
		while (i < argc - 1)
		{
			char_args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
	}
	return (char_args);
}

int	ft_check_args(char *char_args)
{
	int		i;

	i = 0;
	if (char_args[i] == '-' || char_args[i] == '+')
		i++;
	if (i == 1 && char_args[i] == '\0')
		return (-1);
	while (char_args[i])
	{
		if (!ft_isdigit(char_args[i]))
			return (-1);
		i++;
	}
	if (ft_strlen(char_args) > 11)
		return (-1);
	if (ft_atol(char_args) >= -2147483648 && ft_atol(char_args) <= 2147483647)
		i++;
	else
		return (1);
	return (0);
}

int	ft_check_duplicates(t_list **stack_a)
{
	t_list	*nbr;
	t_list	*temp;

	nbr = *stack_a;
	while (nbr != NULL)
	{
		temp = *stack_a;
		while (temp != NULL)
		{
			if (nbr != temp && nbr->number == temp->number)
				return (1);
			temp = temp->next;
		}
		nbr = nbr->next;
	}
	return (0);
}

int	ft_check_if_sorted(t_list *stack_a)
{
	t_list	*next;
	t_list	*temp;

	next = stack_a->next;
	temp = stack_a;
	while (next != NULL)
	{
		if (next->number < temp->number)
			return (0);
		temp = temp->next;
		next = next->next;
	}
	return (1);
}
