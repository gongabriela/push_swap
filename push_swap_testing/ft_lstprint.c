void	ft_lstprint(t_list *head)
{
	t_list	*temp;
	int		value;

	temp = head;
	while (temp != NULL)
	{
		value = temp->number;
		ft_printf("%d ", value);
		temp = temp->next;
	}
	ft_printf("\n");
}
