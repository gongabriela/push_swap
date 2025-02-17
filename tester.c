#include "push_swap.h"

/*void	ft_error()
{
	ft_putendl_fd("Error", 2);
	exit(0);
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
int	ft_check_duplicates(int	*int_args, int size)
{
	int	nbr;
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		nbr = int_args[j];
		i = 0;
		while (i < size)
		{
			if (nbr == int_args[i])
				return(-1); //retornar -1 ou 0? acho q e 0
			else
				i++;
		}
		j++;
	}
	return(1);
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
		return(free(int_args), free(char_args), ft_error(), NULL); //novamente nao e free(char_args)
	return(int_args);
}

t_list	*ft_new_node(int	number)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}
void ft_lstprint(t_list *head)
{
	int	value;

	while (head != NULL)
	{
		value = head->number;
        ft_printf("%d ", value);
        head = head->next;
    }
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
int	ft_check_if_sorted(int *int_args, int args_size)
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
	int		args_size;
	int		i;
	t_list	*stack_a; //cabeca da lista stack_a
	t_list	*tail;
	int		median;

	i = 0;
	//dividir args na char_args
	char_args = ft_divide_argv(argc, argv);
	ft_printf("args being stored in char_args: ");
	while (char_args[i] != NULL)
	{
		ft_printf("%s ", char_args[i]);
		i++;
	}

	//verificar se os args sao validos (falta verificar args repetidos)
	args_size = ft_check_args(char_args);
	ft_printf("\nresult of args_size: %d\n", args_size);

	//passar os args de char pra int e dar free no char_args
	int_args = ft_char_to_int(char_args, args_size);
	ft_printf("int_args: ");
	i = 0;
	while (i < args_size)
	{
		ft_printf("%d ", int_args[i]);
		i++;
	}
	ft_free_char_args(char_args);

	//check if it is sorted
	if (!ft_check_if_sorted(int_args, args_size))
		free(int_args), ft_error();

	//criar a stack_a
	stack_a = NULL;
	ft_init_stack(&stack_a, &tail, int_args, args_size);
	ft_printf("\nElements of the linked list: ");
	ft_lstprint(stack_a);
	ft_free_lst(&stack_a);

	//encontrar a mediana e dar free no int_args
	median = ft_find_median(int_args, args_size);
	ft_printf("\nSorted int_args: ");
	i = 0;
	while (i < args_size)
	{
		ft_printf("%d ", int_args[i]);
		i++;
	}
	free(int_args);
	ft_printf("\nmedian: %d\n", median);

	return (0);
}*/

//movements tester
/*#include "push_swap.h"

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	t_list	*head_b;
	t_list	*node1_b;
	t_list	*node2_b;
	t_list	*node3_b;
	t_list	*node4_b;

	head = NULL;
	node1 = ft_new_node(1);
	head = node1;
	node2 = ft_new_node(2);
	node1->next = node2;
	node3 = ft_new_node(3);
	node2->next = node3;
	node4 = ft_new_node(4);
	node3->next = node4;
	ft_lstprint(head);
	ft_printf("\n");

	head_b = NULL;
	node1_b = ft_new_node(10);
	head_b = node1_b;
	node2_b = ft_new_node(20);
	node1_b->next = node2_b;
	node3_b = ft_new_node(30);
	node2_b->next = node3_b;
	node4_b = ft_new_node(40);
	node3_b->next = node4_b;
	ft_lstprint(head_b);

	//stack is sorted
	if (ft_is_stack_sorted(head))
		ft_printf("The list is sorted!\n");
	else
		ft_printf("The list is not sorted!\n");

	//ft_sa_sb
	ft_printf("performing sa in this list:\n");
	ft_sa_sb(&head);
	ft_lstprint(head);

	//ft_pa_pb
	ft_printf("\nperforming pa in this list: \n");
	ft_pa_pb(&head, &head_b);
	ft_lstprint(head);
	ft_printf("\n");
	ft_lstprint(head_b);

	ft_printf("\n\nperforming pb in this list: \n");
	ft_pa_pb(&head_b, &head);
	ft_lstprint(head);
	ft_printf("\n");
	ft_lstprint(head_b);

	//ft_ra_rb
	ft_printf("\nperforming the ra movement:\n");
	ft_ra_rb(&head, 0, "r");
	ft_lstprint(head);
	ft_printf("\n");
	ft_lstprint(head_b);
	ft_printf("\n");

	return (0);
}*/
