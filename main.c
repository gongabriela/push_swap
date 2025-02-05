/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:22:40 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/05 12:54:28 by ggoncalv         ###   ########.fr       */
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
int	*ft_char_to_int(char **char_args, int i) //i = args_size
{
	int	*int_args;

	int_args = ft_calloc(i, sizeof(int));
	if (int_args == NULL)
		return (ft_free_char_args(char_args), ft_error(), NULL); //nao e free(char_args), tem q ser outra coisa
	i = 0;
	while(char_args[i])
	{
		int_args[i] = ft_atol(char_args[i]);
		i++;
	}
	/*if (ft_check_duplicates(int_args, i))
		return(free(int_args), free(char_args), ft_error(), NULL);*/ //novamente nao e free(char_args)
	return(int_args);
}

void	ft_init_stack(t_list **stack_a, t_list **tail, int *int_args, int size)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_new_node(int_args[i]);
		if (new_node == NULL)
		{
			//ft_free_lst(*stack_a); //nao sei passar essa porra
			free(int_args); //o chat fala que nao da free mas da sim ne?
			ft_error();
		}
		if (*stack_a == NULL)
			*stack_a = new_node;
		else
			(*tail)->next = new_node;
		*tail = new_node;
		i++;
	}
}
int	ft_find_median(int *int_args, int args_size)
{
	int	i;
	int	temp;
	int	median_index;

	while (ft_check_if_sorted(int_args, args_size))
	{
		i = 0;
		while (i < args_size - 1) //pq tem que ser args_size - 1? por causa do int_args[i + 1]!
		{
			if (int_args[i] > int_args[i + 1])
			{
				temp = int_args[i];
				int_args[i] = int_args[i + 1];
				int_args[i + 1] = temp;
			}
			i++;
		}
	}
	median_index = args_size / 2;
	if (args_size % 2 == 1)
		return (int_args[median_index]);
	return (int_args[median_index - 1]);
}
int	main(int argc, char **argv)
{
	char	**char_args;
	int		*int_args;
	t_list	*stack_a;
	t_list	*tail;
	int		i;

	char_args = ft_divide_argv(argc, argv);
	i = ft_check_args(char_args);
	int_args = ft_char_to_int(char_args, i);
	ft_free_char_args(char_args);
	if (!ft_check_if_sorted(int_args, i))
		free(int_args), ft_error();
	stack_a = NULL;
	ft_init_stack(&stack_a, &tail, int_args, i);
	i = ft_find_median(int_args, i);
	free(int_args);

	return (0);
}
