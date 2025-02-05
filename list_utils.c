#include "push_swap.h"

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
