/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:22:40 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/03 14:10:28 by ggoncalv         ###   ########.fr       */
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
		char_args = ft_calloc(argc, sizeof(char));
		if (char_args == NULL)
			ft_error();
		while (i < argc)
		{
			char_args[i] = argv[i + 1];
		}
	}
	return(char_args);
}
//funcao para verificar se os args sao ints
int	ft_check_args(char **char_args)
{
	int	nbr;
	int	i;
	int	j;

	i = 1;
	while (char_args[i])
	{
		j = 0;
		if (char_args[i][j] == '-')
			j++;
		while (char_args[i][j])
		{	if (!ft_isdigit(char_args[i][j]))
				return(free(char_args), ft_error(), -1);
			j++;
		}
		nbr = ft_atol(char_args[i]);
		if (nbr > -2147483648 && nbr < 2147483647)
			i++;
		else
			return(free(char_args), ft_error(), -1);
	}
	return (i);
}
//funcao para transformar os args em ints
int	*ft_char_to_int(char **char_args, int i) //i = args_size
{
	int	*int_args;

	int_args = ft_calloc(i, sizeof(int));
	if (int_args == NULL)
		return (free(char_args), ft_error(), NULL);
	i = 0;
	while(char_args[i + 1])
	{
		int_args[i] = ft_atol(char_args[i + 1]);
		i++;
	}
	return(free(char_args), int_args);
}
void del(void *content)
{
    // If the content is a dynamically allocated integer, free it
    free(content);
}
//funcao para inicializar a stack_a
void	*ft_init_stack(int *int_args, int	size, t_list **stack_a)
{
	t_list	*new;
	void	*bottom_a_pointer;
	int		i;

	i = 0;
	while(size > i)
	{
		new = ft_lstnew(int_args[i]);
		if (new == NULL)
			return(free(int_args), ft_free_lst(stack_a), NULL); //achar funcao de dar free na list, acho que tem no libft
		if (i == size - 1)
			bottom_a_pointer = new;
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return(bottom_a_pointer);
}
//funcao para encontrar a mediana
int	ft_find_median(int *int_args, int args_size)
{
	//utilizar o quicksort
	int	median;

	return(free(int_args), median);
}
int	main(int argc, char **argv)
{
	//devo usar o read para receber os argumentos????????? nao sei fazer isso socorro
	char	**char_args;
	int		*int_args;
	int		args_size;
	t_list	*stack_a; //nao lembro se e * ou ** ou se depende de como vc ta modificando? verificar dps
	void	*bottom_a_pointer; //int mesmo ou void ou t_list? nao sei.
	int		median;
	//funcao que separa os args e guarda num array de char
	char_args = ft_divide_argv(argc, argv);
	//funcao que verifica se os elementos do array de char sao validos para se tranformar em int, e retorna a qtd de args
	args_size = ft_check_args(char_args);
	//funcao que cria o array de int
	int_args = ft_char_to_int(char_args, args_size);
	//funcao que cria a stack a
	bottom_a_pointer = ft_init_stack(int_args, args_size, &stack_a); //ver forma correta de passar a stack como parametro
	//funcao que encontra a mediana
	median = ft_find_median(int_args, args_size);
	if (args_size <= 5)
		ft_small_algorithm(stack_a, median); //novamente, ver a maneira correta de passar o ponteiro da stack...
	else
		ft_algorithm(stack_a, median);
	return (0);
}
