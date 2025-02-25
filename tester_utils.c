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

			/*t_list *temp = stack_b;
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
		}
		printf("\n\n");*/

			/*median = get_median(*stack_a);
	if (check_trio(stack_a, tail_a, &stack_b, median))
		check_duo(stack_a, tail_a, &stack_b, median);
	ft_init_node_a(*stack_a, ft_lstsize(*stack_a));
	ft_init_node_b(stack_b, ft_lstsize(stack_b));
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);*/

	//printf("median: %d\n", median);

		//ft_lstprint(stack_a);
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

	/*void	check_best_node(t_list **head_a, t_list **tail_a, t_list **head_b, int median)
{
	t_list	*best_node;
	t_list	*temp_head;
	t_list	*temp_tail;

	temp_head = *head_a;
	temp_tail = *tail_a;
	while (temp_head != NULL && temp_tail != NULL)
	{
		best_node = NULL;
		while (!best_node)
		ft_check_cost(temp_head, *head_b, median);
		ft_check_cost(temp_tail, *head_b, median);
		best_node = ft_chosen_node(temp_head, temp_tail);
		if (best_node)
		{
			ft_move_and_sort(head_a, head_b, tail_a, best_node);
			temp_head = *head_a;
			temp_tail = *tail_a;
		}
		else
		{
			temp_head = temp_head->next;
			temp_tail = temp_tail->previous;
		}
	}
}*/

	/*ft_sort_a(stack_a, tail_a);
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);
	printf("\n\n");
	while (stack_b != NULL)
		ft_pa_pb(stack_a, &stack_b, 1);
	ft_lstprint(*stack_a);
	ft_lstprint(stack_b);
	printf("\n\n");*/
