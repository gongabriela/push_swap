
#include "push_swap.h"

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
