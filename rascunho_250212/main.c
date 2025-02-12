/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:36:17 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/02/12 21:36:35 by ggoncalv         ###   ########.fr       */
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
int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long			ft_atol(const char *str)
{
	long		nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (str[i++] - '0') * sign + nbr * 10;
	return (nbr);
}
void	ft_free_char_args(char **char_args)
{
	int	i;

	if (!char_args)
		return ;
	i = 0;
	while (char_args[i])
	{
		free(char_args[i]);
		i++;
	}
	free(char_args);
}
int	ft_check_args(char **char_args)
{
	int	nbr;
	int	i;
	int	j;

	i = 0;
	while (char_args[i])
	{
		j = 0;
		if (char_args[i][j] == '-')
			j++;
		while (char_args[i][j])
		{	if (!ft_isdigit(char_args[i][j]))
				return(ft_free_char_args(char_args), ft_error(), -1);
			j++;
		}
		if (ft_strlen(char_args[i]) > 10)
			return(ft_free_char_args(char_args), ft_error(), -1);
		nbr = ft_atol(char_args[i]);
		if (nbr > -2147483648 && nbr < 2147483647) // > ou >=?
			i++;
		else
			return(ft_free_char_args(char_args), ft_error(), -1);
	}
	return (i);
}

void	ft_free_lst(t_list **head)
{
	t_list	*node;
	t_list	*temp;

	if (*head == NULL)
		return ;
	node = *head;
	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*head = NULL;
}
void	ft_init_stack(t_list **stack_a, char **char_args, int size)
{
	t_list	*tail;
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_new_node(char_args[i]);
		if (new_node == NULL)
		{
			ft_free_lst(*stack_a);
			ft_free_char_args(char_args);
			ft_error();
		}
		if (*stack_a == NULL)
			*stack_a = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		i++;
	}
}
int	ft_lstsize(t_list *head) //igual lstsize da libft
{
	int	i;

	i = 0;
	while(head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	ft_check_duplicates(t_list *stack_a, int size)
{
	t_list	*temp;
	t_list	*nbr;

	while (size > 0)
	{
		temp = stack_a;
		while (temp->next != NULL) //ou so temp != NULL????
		{
			if (nbr->number == temp->number)
				return (-1); //tem duplicado, dar free em tudo
			temp = temp->next;
		}
		nbr = nbr->next;
		size--;
	}
	return (0); //nao tem duplicados!!!
}
int	ft_check_if_sorted(t_list *stack_a, int size)
{
	t_list	*next;
	int	i;

	i = 0;
	next = stack_a->next;
	while (i < size)
	{
		if (next->number < stack_a->number)
			return (-1); //falta dar free na lista!
		next = next->next;
		stack_a = stack_a->next;
	}
	return(1);
}
void	ft_info_stack_a(t_list **stack_a)
{
	int	i;
	t_list	*temp;

	i = 1; //ou entao i = a posicao do no que ele enviou??? mas nao funcionaria para a primeria chamada...
	temp = *stack_a;
	//position & direction & cost;
	while (i <= ft_lstsize(stack_a)/2)
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

int	main(int argc, char **argv)
{
	char	**char_args;
	t_list	*stack_a;
	int		size;

	char_args = ft_divide_argv(argc, argv);
	size = ft_check_args(char_args);
	ft_init_stack(&stack_a, char_args, size);
	//colocar isso dentro de outra funcao
	ft_free_char_args(char_args);
	//colocar isso dentro de outra funcao
	if (ft_check_duplicates(stack_a, size) || ft_check_if_sorted(stack_a, size))
	{
		ft_free_lst(&stack_a);
		ft_error();
	}
	//em vez de chamar essa funcao, ja colocar ela direto aq? n tem mtas linhas... n sei
	//pq os ponteiros estao me confundindo
	ft_push_swap(&stack_a);
	ft_free_lst(&stack_a);
	return (0);
}
