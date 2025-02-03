#include "push_swap.h"

void	ft_error()
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
				return(free(char_args), ft_error(), -1);
			j++;
		}
		if (ft_strlen(char_args[i]) > 10)
			return(free(char_args), ft_error(), -1);
		nbr = ft_atol(char_args[i]);
		if (nbr > -2147483648 && nbr < 2147483647) // > ou >=?
			i++;
		else
			return(free(char_args), ft_error(), -1);
	}
	return (i);
}
int	*ft_char_to_int(char **char_args, int i) //i = args_size
{
	int	*int_args;

	int_args = ft_calloc(i, sizeof(int));
	if (int_args == NULL)
		return (free(char_args), ft_error(), NULL);
	i = 0;
	while(char_args[i])
	{
		int_args[i] = ft_atol(char_args[i]);
		i++;
	}
	return(int_args);
}

void ft_lstprint(t_list *head)
{
	int	value;
	while (head != NULL)
	{
		value = *(int *)(head->content);
        ft_printf("%d ", value);
        head = head->next;
    }
}
void del(void *content)
{
    // If the content is a dynamically allocated integer, free it
    free(content);
}

void	*ft_init_stack(int *int_args, int	size, t_list **stack_a)
{
	t_list	*new;
	void	*bottom_a_pointer;
	int		i;

	i = 0;
	while(size > i)
	{
		new = ft_lstnew(&int_args[i]);
		if (new == NULL)
			return(free(int_args), ft_lstclear(stack_a, del), NULL); //achar funcao de dar free na list, acho que tem no libft
		if (i == size - 1)
			bottom_a_pointer = new;
		ft_lstadd_back(stack_a, new); //talvez fazer o seu proprio?
		i++;
	}
	return(bottom_a_pointer);
}
int	main(int argc, char **argv)
{
	char	**char_args;
	int		*int_args;
	int		args_size;
	int		i;
	t_list	*stack_a;
	void	*bottom_a_pointer;
	void	*head;

	i = 0;
	char_args = ft_divide_argv(argc, argv);
	ft_printf("args being stored in char_args: ");
	while (char_args[i] != NULL)
	{
		ft_printf("%s ", char_args[i]);
		i++;
	}

	args_size = ft_check_args(char_args);
	ft_printf("\nresult of args_size: %d\n", args_size);

	int_args = ft_char_to_int(char_args, args_size);
	ft_printf("int_args: ");
	i = 0;
	while (i < args_size)
	{
		ft_printf("%d ", int_args[i]);
		i++;
	}

	i = 0;
	while (i < args_size)
	{
		free(char_args[i]);
		i++;
	}
	free(char_args);

	 stack_a = NULL;
	bottom_a_pointer = ft_init_stack(int_args, args_size, &stack_a);
	//ft_printf("Last number: %d", int_args[i - 1]); //printar ultimo arg
	//printar stack
	head = stack_a;
	ft_printf("Elements of the linked list: ");
	ft_lstprint(head);
	ft_lstclear(&stack_a, del);
	//printar pointer e ver se ta igual ultimo arg

	free(int_args); //aqui deve dar double free porque a lista vai apontar
					//para a array, ela nao vai copiar o valor!
	return (0);
}
