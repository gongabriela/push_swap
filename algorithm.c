/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:02 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/06 16:49:15 by ggoncalv         ###   ########.fr       */
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
void	ft_pass_to_pb(t_list **head_a, t_list **head_b)
{
	t_list	*stack_a;
	int		top_a;

	stack_a = *head_a;
	top_a = stack_a->number;


}

void	ft_sort_pb(t_list **head_b)
{
	//depois de receber um numero da stack_a, verificar a posicao coreta dele
}
void	ft_sort_3_numbers(t_list **stack_a)
{

}
void	ft_from_b_to_a(t_list **head_a, t_list **head_b)
{

}
char	**big_sorting(t_list **head_a, t_list **tail_a)
{
	t_list	*head_b;

	head_b = NULL;
	//passar um numero para a stack_b para ter um ponteiro para o tail_b (?)
	while(ft_is_stack_sorted(head_a))
	{
		while (ft_lstsize(head_a) != 3)
		{
			ft_pass_to_b(&head_a, &head_b);
			ft_sort_b(&head_b);
		}
		ft_sort_3_numbers(&head_a);
		ft_from_b_to_a(&head_a, &head_b); //fazer uma funcao de um movimento so? p usar essa funcao outras vezes. aqui a gnt escreve um while
	}
}
