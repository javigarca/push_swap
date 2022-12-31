#include "push_swap.h"

void	ft_load_nodes(t_dtint dt, t_stack **fnode, t_stack **lnode, \
		t_stack **stack)
{
	t_stack	*next_node;
	int		i;

	i = 1;
	while (i < dt.len)
	{
		next_node = (t_stack *) malloc(sizeof (t_stack));
		if (!next_node)
			ft_exit_error(4);
		next_node->data = dt.nb[i];
		next_node->next = *fnode;
		(*stack)->next = next_node;
		*lnode = *stack;
		*stack = next_node;
		(*stack)->prev = *lnode;
		i++;
	}
}

t_stack	*ft_build_stack(t_dtint dt)
{
	t_stack	*stack;
	t_stack	*first_node;
	t_stack	*last_node;

	stack = (t_stack *) malloc(sizeof (t_stack));
	if (!stack)
		ft_exit_error(4);
	stack->data = dt.nb[0];
	stack->next = stack;
	stack->prev = stack;
	first_node = stack;
	ft_load_nodes(dt, &first_node, &last_node, &stack);
	last_node = stack;
	stack = stack->next;
	stack->prev = last_node;
	return (stack);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return;
	current = stack;
	printf("%i-", current->data);
	current = current->next;
	while (current != stack)
	{
		printf("%i-", current->data);
		current = current->next;
	}
}

void	ft_delete_node(t_stack **nodel)
{
	if (*nodel == (*nodel)->next)
		*nodel = NULL;
	else
	{
		(*nodel)->next->prev = (*nodel)->prev;
		(*nodel)->prev->next = (*nodel)->next;
		*nodel = (*nodel)->next;
	}
}
