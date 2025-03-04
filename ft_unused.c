// MEDIAN

int	ft_int_check_if_sorted(int *int_args, int args_size)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 0;
	while (i < args_size - 1)
	{
		if (int_args[i] > int_args[i + 1])
		{
			sorted = 1;
			break;
		}
		i++;
	}
	return(sorted);
}

int	*init_int_args(t_list *stack_a, int size)
{
	t_list	*head_a;
	int		*args;
	int		i;

	head_a = stack_a;
	args = ft_calloc(size, sizeof(int));
	i = 0;
	while (head_a != NULL)
	{
		args[i] = head_a->number;
		head_a = head_a->next;
		i++;
	}
	return (args);
}

int	get_median(t_list *stack_a)
{
	int	*args;
	int	size;
	int	i;
	int	temp;

	size = ft_lstsize(stack_a);
	args  = init_int_args(stack_a, size);
	while (ft_int_check_if_sorted(args, size))
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
	if (size % 2 == 1)
		temp = args[size / 2];
	else
		temp = args[(size / 2) - 1];
	return (free(args), temp);
}

//INIT NODES

void	ft_init_node_a_bottom(t_list *new_node, int i)
{
	while (i > 0)
	{
		new_node->position = i;
		new_node->direction = 'b';
		new_node->total_cost = -2;
		new_node->cost = i + 1 + (i - 1);
		new_node = new_node->next;
		i--;
	}
}

//FUNCAO COM MAIS DE 25 LINHAS DEIXA DE PREGUICA E VAI DIVIDIR
void	ft_init_node_a(t_list *new_node, int size)
{
	int	i;

	i = 1;
	while (i <= (size + 1) / 2)
	{
		new_node->position = i;
		new_node->direction = 't';
		new_node->total_cost = -2;
		if (i == 1)
			new_node->cost = 1;
		else
			new_node->cost = i + (i - 2);
		i++;
		new_node = new_node->next;
	}
	if (size % 2 == 0)
		i = i - 1;
	else
		i = i - 2;
	ft_init_node_a_bottom(new_node, i);
}
void	ft_init_node_b_bottom(t_list *stack_b, int i)
{
	while (i > 0)
	{
		stack_b->position = i;
		stack_b->direction = 'b';
		stack_b->total_cost = -2;
		stack_b->cost = (i * 2) + (i + 1);
		stack_b = stack_b->next;
		i--;
	}
}
void	ft_init_node_b(t_list *stack_b, int size)
{
	int	i;

	i = 1;
	while (i <= (size + 1) / 2)
	{
		stack_b->position = i;
		stack_b->direction = 't';
		stack_b->total_cost = -2;
		if (i == 1)
			stack_b->cost = 0;
		else
			stack_b->cost = ((i - 2) * 2) + 1 + (i - 2);
		i++;
		stack_b = stack_b->next;
	}
	if (size % 2 == 0)
		i = i - 1;
	else
		i = i - 2;
	ft_init_node_b_bottom(stack_b, i);
}

//move and sort

void	ft_move_top_a(t_list **head_a, t_list **head_b, t_list *best_node)
{
	int	counter;

	if (best_node->position == 1)
		return(ft_pa_pb(head_a, head_b, 1));
	else
	{
		counter = best_node->position - 2;
		while (counter-- > 0)
			ft_ra_rb(head_a, 0);
		ft_sa_sb(head_a, 0);
		ft_pa_pb(head_a, head_b, 1);
		/*counter = best_node->position - 2;
		while (counter-- > 0)
			ft_rra_rrb(head_a, 0);*/
	}
}

void	ft_move_bottom_a(t_list **head_a, t_list **head_b, t_list *best_node)
{
	int	counter;

	if (best_node->position == 1)
		return(ft_rra_rrb(head_a, 0), ft_pa_pb(head_a, head_b, 1));
	else
	{
		counter = best_node->position;
		while (counter-- > 0)
			ft_rra_rrb(head_a, 0);
		ft_pa_pb(head_a, head_b, 1);
		/*counter = best_node->position - 1;
		while (counter-- > 0)
			ft_ra_rb(head_a, 0);*/
	}
}

void	ft_sort_top_b(t_list **head_b, t_list *node_b)
{
	int	counter;

	if (ft_lstsize(*head_b) == 2 || node_b->position == 1)
	{
		if (node_b->number > (*head_b)->number)
			return (ft_rra_rrb(head_b, 1));
		return ;
	}
	else
	{
		counter = node_b->position - 2;
		while (counter-- > 0)
		{
			ft_sa_sb(head_b, 1);
			ft_ra_rb(head_b, 1);
		}
		ft_sa_sb(head_b, 1);
		counter = node_b->position - 2;
		while (counter-- > 0)
			ft_rra_rrb(head_b, 1);
	}
}

//parece que nao ta performando os movimentos...
void	ft_sort_bottom_b(t_list **head_b, t_list *node_b)
{
	int	counter;

	if (ft_lstsize(*head_b) == 2 || node_b->position == 1)
	{
		if (node_b->number > (*head_b)->number)
			return (ft_ra_rb(head_b, 1));
	}
	if (ft_lstsize(*head_b) == 2)
		return ;
	else
	{
		counter = node_b->position;
		while (counter-- > 0)
		{
			ft_rra_rrb(head_b, 1);
			ft_sa_sb(head_b, 1);
		}
		counter = node_b->position + 1;
		while (counter-- > 0)
			ft_ra_rb(head_b, 1);
	}
}
t_list	*ft_lstlast(t_list **head_a)
{
	t_list *tail_a;

	tail_a = *head_a;
	while(tail_a->next != NULL)
		tail_a = tail_a->next;
	return (tail_a);
}
void	ft_move_and_sort(t_list **head_a, t_list **head_b, t_list **tail_a, t_list *best_node)
{
	t_list	*node_b;

	if (best_node->direction == 't')
		ft_move_top_a(head_a, head_b, best_node);
	else
		ft_move_bottom_a(head_a, head_b, best_node);
	if (ft_lstsize(*head_b) == 1)
		return ;
	*tail_a = ft_lstlast(head_a);
	node_b = *head_b;
	while (best_node->number <= node_b->number && node_b->next != NULL)
		node_b = node_b->next;
	if (node_b->direction == 't')
		ft_sort_top_b(head_b, node_b);
	else
		ft_sort_bottom_b(head_b, node_b);
}

//algoritmo antigo
void	ft_check_cost(t_list *node_a, t_list *head_b, int median)
{
	if (node_a->number <= median)
	{
		if (!head_b)
		{
			node_a->total_cost = node_a->cost;
			return ;
		}
		while (node_a->number < head_b->number && head_b->next != NULL)
			head_b = head_b->next;
		if (head_b->next == NULL && head_b->number > node_a->number)
			node_a->total_cost = node_a->cost + 1; //vai so fazer rrb e por no fim
		else
			node_a->total_cost = node_a->cost + head_b->cost;
	}
	else
		node_a->total_cost = -1;
}

t_list	*ft_chosen_node(t_list *node_1, t_list *node_2)
{
	if (!node_1 && node_2->total_cost == -1)
		return (NULL);
	else if (!node_1 && node_2->total_cost > -1)
		return (node_2);
	if (node_1->total_cost == -1 && node_2->total_cost == -1)
		return (NULL);
	if (node_1->total_cost == -1)
		return (node_2);
	else if (node_2->total_cost == -1)
		return (node_1);
	if ((node_1->total_cost == node_2->total_cost && node_1->number < node_2->number) || (node_1->total_cost < node_2->total_cost))
		return (node_1);
	return(node_2);
}
int	check_trio(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;

	ft_check_cost(*head_a, *head_b, median);
	ft_check_cost((*head_a)->next, *head_b, median);
	ft_check_cost(*tail_a, *head_b, median);
	best_node = ft_chosen_node(*head_a, (*head_a)->next);
	best_node = ft_chosen_node(best_node, *tail_a);
	if (!best_node)
		return (1);
	ft_move_and_sort(head_a, head_b, tail_a, best_node);

	return (0);
}
void	check_duo(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;
	t_list	*temp_head;
	t_list	*temp_tail;

	temp_head = (*head_a)->next;
	temp_tail = *tail_a;
	while (temp_head->total_cost == -1 && temp_tail->total_cost == -1)
	{
		temp_head = temp_head->next;
		temp_tail = temp_tail->previous;
		ft_check_cost(temp_head, *head_b, median);
		ft_check_cost(temp_tail, *head_b, median);
	}
	best_node = ft_chosen_node(temp_head, temp_tail);
	ft_move_and_sort(head_a, head_b, tail_a, best_node);
}

void	ft_sort_a(t_list **head_a, t_list **tail_a)
{
	while (!ft_check_if_sorted(head_a))
	{
		if ((*head_a)->number > (*head_a)->next->number)
			ft_sa_sb(head_a, 0);
		if ((*head_a)->number > (*tail_a)->number)
			ft_ra_rb(head_a, 0);
		if ((*head_a)->next->number > (*tail_a)->number)
		{
			ft_rra_rrb(head_a, 0);
			ft_sa_sb(head_a, 0);
		}
	}
}
