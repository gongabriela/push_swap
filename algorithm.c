/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:02 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/10 11:29:31 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//algoritmo se tamanho for <= 5

//algoritmo se tamanho for > 5

/*
//maiores numeros na stack A, em ordem ascendente
//menores numeros na stack B, em ordem descendente
e preciso de 3 ponteiros em cada stack;
	o primeiro numero TOP;
	o segundo numero  2TOP;
	o ultimo numero BOTTOM.
//comparacoes:
	topA >= mediana?
		sim: (aqui voce ja vai gastar no minimo 2 operacoes, entao verificar o que custa menos)
			2A >= mediana?
				nao: passar logo pro bottom
				sim: ver o valor do bottom e se ele for sim, comparar para ver o que custa menos
		BOTTOMA >= mediana?
			nao: se o 2A e sim, fazer sa. se ele for nao, fazer rra.
					depois de fazer rra, verificar se e bom fazer logo um sa.
					continuar fazendo rra/sa ate haver um numero para passar para o B
			sim:
				ver o valor do 2A e ver o que custa menos.
				ver o que custaria menos nesse caso seria: se eu tiver um 5 no 2A, e um 8 no BOTTOMA, compensa mais emviar o 2A e depois o BOTTOM, porque ai nao precisa fazer um sb para reordenar!
		nao:
			pb ()
			-> depois de passar o numero pro b, organizar ele la dentro

se tiver que fazer sa ou sb, verificar se beneficiaria um ss. mesma coisa com rr e rrr
se nao tiver o numero valido entre os dois primeiros ou os dois ultimos, tem que ver o que faz menos movimento, rra ou ra*/

#include "push_swap.h"

char	**small_sorting(t_list **head_a, t_list **tail_a)
{
	t_list	*stack_b;

	stack_b = NULL;
}
int	ft_is_stack_sorted(t_list *stack)
{
	t_list	*temp;
	t_list	*next;

	temp = stack;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->number > next->number)
			return (0);
		temp = next;
	}
	return (1);
}
int	ft_get_median(t_list *head_a)
{
	int	*args;
	int	size;
	int	i;
	int	temp;

	size = ft_lstsize(head_a);
	args  = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		args[i] = head_a->number;
		head_a = head_a->next;
		i++;
	}
	i = 0;
	while (ft_check_if_sorted(args, size))
	{
		i = 0;
		while (i < size - 1) //pq tem que ser args_size - 1? por causa do int_args[i + 1]!
		{
			if (args[i] > args[i + 1])
			{
				temp = args[i];
				args[i] = args[i + 1];
				args[i + 1] = temp;
			}
			i++;
		}
	}
	i = size / 2;
	if (size % 2 == 1)
		return (args[i]);
	return (free(args), args[i - 1]);
}
void	ft_from_a_to_b(t_list **head_a, t_list **head_b, int median)
{
	int		nbr_a;

	while ()
	{
		nbr_a = (*head_a)->number;
		if(nbr_a <= median)
		{
			ft_pa_pb(&head_a, &head_b, 1); //eu acho que a funcao tem que ser *** porque eu ja to passando pra essa funcao como **
			break ;
		}
		else
			ft_ra_rb(&head_a, 0);
	}
}
void	ft_sort_b(t_list **head_b)
{
	t_list	*top;
	t_list	*current;
	t_list	*bestie;

	top = *head_b;
	current = (*head_b)->next;
	bestie = (*head_b)->next;
	while (current != NULL)
	{
		if (top->number < current->number)
		{
			if (bestie->number > current->number)
				bestie = current;
			current = current->next;
		}
	}
	while (bestie->next != top)
	{
		//se o top esta embaixo do bestie
		//se o bestie na no bottom
		//se o bestie ta no bottom2
	}
	 //os numeros aqui tem que estar do maior para o menor
	//diminuir o numero do topo por todos os numeros da b para encontrar o seu "melhor amigo": ele tem que ser maior que o numero do topo, mas com a menor diferenca possivel
	//colocar o numero do topo diretamente embaixo desse melhor amigo!
}
void	ft_sort_3_numbers(t_list **stack_a)
{

}

void	ft_from_b_to_a(t_list **stack_a, t_list **stack_b)
{

}
void	big_sorting(t_list **head_a, t_list **tail_a)
{
	t_list	*head_b;
	int		median;
	head_b = NULL;
	//passar um numero para a stack_b para ter um ponteiro para o tail_b (?)
	while(ft_is_stack_sorted(head_a))
	{
		median = ft_get_median(head_a); //pegar a mediana. funcao esta muito grande!
		ft_from_a_to_b(&head_a, &head_b, median); //achar o melhor numero da a e passar pra b
		ft_sort_b(&head_b); //organizar a lista b depois de passar um novo numero
		if (ft_lstsize(head_a) == 3)
			ft_sort_3_numbers(&head_a);
	}
	ft_from_b_to_a(&head_a, &head_b); //pass all numbers from b to a. here all elements in a are sorted already.
	//checar mais uma vez se a stack_a esta organizada
	free(head_b); //nao sei se ta certo aqui.
	//dar free na stack_a tambem?
}
//se a stack a esta organizada ou se a stack a tem 3 numeros
	//se a stack b nao esta vazia, devolver numeros para a stack a
	//break ;
//atualizar a mediana
//passar o numero para b
//organizar a lista b
//se a stack a tem 3 numeros, organizar

