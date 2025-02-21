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
	printf("\n");
}
	//teste
	/*t_list *temp = stack_a;
	while (temp != NULL)
	{
		if (temp->previous != NULL)
			printf("previous: %d\n", temp->previous->number);
		printf("position: %d\n", temp->position);
		printf("number: %d\n", temp->number);
		printf("direction: %c\n", temp->direction);
		printf("cost: %d\n", temp->cost);
		printf("total cost: %d\n", temp->total_cost);
		if (temp->next != NULL)
			printf("next: %d\n\n", temp->next->number);
		temp = temp->next;
	}*/

	//testing the movements:
	/*	printf("performing pb twice:\n");
	ft_pa_pb(head_a, head_b, 1);
	ft_pa_pb(head_a, head_b, 1);
	ft_lstprint(*head_a);
	ft_lstprint(*head_b);

	printf("performing sa/sb:\n");
	ft_sa_sb(head_a, 0);
	ft_sa_sb(head_b, 1);
	ft_lstprint(*head_a);
	ft_lstprint(*head_b);

	printf("performing ra/rb:\n");
	ft_ra_rb(head_a, 0);
	ft_ra_rb(head_b, 1);
	ft_lstprint(*head_a);
	ft_lstprint(*head_b);

	printf("perfoming rra/rrb:\n");
	ft_rra_rrb(head_a, 0);
	ft_rra_rrb(head_b, 1);
	ft_lstprint(*head_a);
	ft_lstprint(*head_b);*/
