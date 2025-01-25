/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:37:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/01/25 17:29:02 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//funcao de verificar argumento
int	ft_check_arg(char **args)
{
	//if (args == NULL)

	//if (nao for numero)
		//return(free(args), ft_error());
	//while(verificar se tem numero repetido)

}
//funcao de dar free
void	ft_free() //fazer variadica para conseguir dar free em quantos precisar?
{

}
//funcao de inicializar a lista
void	ft_init_stack(t_list **stack_a, char **args)
{
	char	*temp;
	int 	i;
	int 	v;

	i = 0;
	while (args[i])
	{
		temp = ft_lstnew(ft_atoi(args[i]));
		v = ft_check_arg(temp);
		if (v > 0)
		{
			ft_lstclear(stack_a, ft_lstdelone);
			ft_error();
		}
		ft_lstadd_back(stack_a, temp);
		free(temp);
		i++;
	}
}
//funcao de criar a lista
	//while (argc > 0)
	//{
		//verificar se o arg e valido.
			//se sim, adiciona node com funcao do libft
			//se nao, retorna funcao de erro
		//agrc--;
    //}

//funcao de verificar se ja esta na ordem

//funcao de dar free

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int	**args;
	int	i;

	i = 0;
	if (argc > 2)
		ft_error();
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	args = malloc((argc + 1) * sizeof(int));
		while(argc > 0)
		{
			args[i] = argv[i + 1];
			i++;
		}
	ft_check_arg(args);
	ft_init_stack(stack_a, args);
	//verificar se argumentos sao validos
		//argumentos nao sao integers, sao maiores que um integer, sao duplicados

	//criar stack a e stack b com a lista linkada

	//verificar se a lista ja esta organizada:

	//organizar argv e encontrar a mediana

	//se numero de elementos for <= 5, usa um algoritmo;

	//se for mais que 5, utiliza o outro algoritmo.

	//dar free nas stacks

	//return ????;
}
