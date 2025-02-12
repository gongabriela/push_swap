/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:36:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/12 21:37:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_list *head_a)
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
void	ft_info_stack_b(t_list **stack_b) //verificar se a matematica do i ta correta
{
	int	i;
	t_list	*temp;

	i = 0; //ou entao i = a posicao do no que ele enviou??? mas nao funcionaria para a primeria chamada...
	temp = *stack_b;
	//position & direction & cost;
	while (i <= ft_lstsize(stack_b)/2)
	{
		temp->position = i;
		temp->direction = "top";
		if (i == 0)
			temp->cost = 0;
		else if (i == 1)
			temp->cost = 1;
		else
			temp->cost = ((i - 2) * 2) + 1 + (i - 2);
		temp = temp->next;
		i++;
	}
	i = i - 2;
	while (i >= 0)
	{
		temp->position = i;
		temp->direction = "bottom";
		if (i == 0)
			temp->cost = 1;
		else
			temp->cost = (i * 2) + i + 1;
		temp = temp->next;
		i--;
	}
}
//ta com muitos erros mas e so para ter uma ideia da estrutura
//falta ver se o numero e menor ou igual a mediana
int	ft_3(t_list **stack_a, t_list **stack_b, int median)
{
	t_list	*tail_b;
	t_list	*temp_b;
	int		cost;
	int		i;

	tail_b = ft_lstlast(stack_b);
	i = 1;
	while (i <= 3)
	{
		temp_b = tail_b;
		while ((*stack_a)->number < tail_b->number)
			tail_b = tail_b->previous;
		cost = (*stack_a)->cost + tail_b->cost;
		if (cost > (*stack_a)->cost + tail_b->cost)
			cost = (*stack_a)->cost + tail_b->cost;
		else if (cost = (*stack_a)->cost + tail_b->cost)
		{
			if ((*stack_a)->number > (*stack_a)->previous->number)
				stack_a = (*stack_a)->previous;
		}
		i++;
	}
	//se tiver encontrado um node, chamar uma funcao para fazer os movimentos
	//pq ja vamos ter o ponteiro pro node da stack_a e da stack_b!!!
	//so precisamos aprender melhor a usar os ponteiros...
}
int	ft_2(t_list ***stack_a, t_list **stack_b, int median)
{
	t_list	*node_a_top;
	t_list	*node_a_bottom;
	t_list	*node_b;
	int		cost_top;
	int		cost_bottom;

	node_a_top = *stack_a;
	node_a_bottom = ft_lstlast(stack_a);
	node_b = *stack_b;
	cost_top = -1;
	cost_bottom = -1;
	while (cost_top != -1 || cost_top != -1)
	{
		if (node_a_top->number <= median)
		{

		}
		if (node_a_bottom->number <= median)
		{

		}
		if (cost_top != -1 || cost_top != -1)
		{

		}
		else
			node_a_top = node_a_top->next;
			node_a_bottom = node_a_bottom->previous;
	}
	send_to_b(node_a, stack_b);
	sort_in_b(stack_b, node_b);
}
void	send_to_b(t_list **stack_a, t_list **stack_b)
{
	//usar a aritmetica do custo
	if ((*stack_a)->direction == "top")
	{
		if ((*stack_a)->position == 1)
			ft_pb();
		else if ((*stack_a)->position == 2)
			ft_sa_sb();
			ft_pb();
		else
		{

		}
	}
	else
	{
		if ((*stack_a)->position == 1)
		{
			ft_rra_rrb();
			ft_pb();
		}
		else
		{

		}
	}
}
//bestie: o node que tem que estar abaixo (ou acima???) do top node
void	sort_in_b(t_list **top_node, t_list **bestie)
{
	//usar a aritmetica do custo
	if ((*bestie)->direction == "top")
	{
		if ((*bestie)->position == 1)
			return ;
		else if ((*bestie)->position == 2)
		{

		}
		else

	}
	else
	{
		if ((*bestie)->position == 0) // tem que colocar embaixo da lista. ainda nao pensei em como sinalizar isto!!)
		{

		}
		else
		{

		}
	}
}
void	ft_push_swap(t_list	**stack_a)
{
	t_list	*stack_b;
	int		median;

	stack_b = NULL;
	while (ft_lstsize(stack_a) != 3)
	{
		median = ft_median(stack_a);
		if (ft_3(&stack_a, &stack_b, median))
			ft_2(&stack_a, &stack_b, median);
		ft_att_vars_a(); //atualizar os valores da posicao, custo e direcao...
		ft_att_vars_b();
	}
	ft_sort_3(&stack_a);
	ft_b_to_a(&stack_a, &stack_b);
}
