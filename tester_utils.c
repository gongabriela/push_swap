#include "push_swap.h"

void	ft_lstprint(t_list *head)
{
	int		value;
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		value = temp->number;
		ft_printf("%d ", value);
		temp = temp->next;
	}
}
	/*	t_list *temp = best_node;
	printf("BEST NODE\n");
	printf("element: %d\n", temp->number);
	printf("direction: %c\n", temp->direction);
	printf("position: %d\n", temp->position);
	printf("cost: %d\n\n", temp->cost);*/
