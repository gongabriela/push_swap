/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:36:17 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/12 20:10:15 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_divide_argv(int argc, char **argv)
{
	char	**char_args;
	int		i;

	i = 0;
	if (argc < 2)
		ft_error();
	if (argc == 2)
	{
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
	return(char_args);
}
void	ft_error_init_stack(t_list **stack_a, char **args)
{
	ft_free_lst(stack_a);
	ft_free_char_args(args);
	ft_error();
}
t_list	*ft_new_node(int	number)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = ft_atol(number);
	node->next = NULL;
	return (node);
}
void	ft_init_vars_a(t_list **node, int size)
{
	int	i;
	t_list	*temp;

	i = 1; //ou entao i = a posicao do no que ele enviou??? mas nao funcionaria para a primeria chamada...
	temp = *node;
	//position & direction & cost;
	while (i <= size/2)
	{
		temp->position = i;
		temp->direction = "top";
		if (i == 1)
			temp->cost = 1;
		else
			temp->cost = i + (i - 2);
		temp = temp->next;
		i++;
	}
	i = i - 2;
	while (i > 0)
	{
		temp->position = i;
		temp->direction = "bottom";
		temp->cost = i + 1 + (i - 1);
		temp = temp->next;
		i--;
	}
}
void	ft_init_stack(int argc, char **argv, t_list **stack_a)
{
	char	**args;
	t_list	*new_node;
	int		size;
	int		i;

	args = ft_divide_args(argc, argv);
	size = ft_strlen(args);
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
			ft_init_vars_a(new_node, size);
			ft_addlstback(new_node, stack_a);
		}
	}
	ft_free_char_args(args);
	if (ft_check_duplicates() || ft_check_if_sorted())
		ft_error_init_stack(stack_a, args);
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;

	ft_init_stack(argc, argv, &stack_a);

	return (0);
}
