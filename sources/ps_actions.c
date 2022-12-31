#include "push_swap.h"

int		ft_issorted(t_stack *stack)
{
	t_stack *head;
	int		sort;

	head = stack;
	stack = stack->next;
	sort = 0;
	while (stack != head)
	{
		if (stack->data < stack->prev->data)
			sort++;
		stack = stack->next;
	}
	if (!sort)
		return (1);
	return (0);
}

void	ft_first2last(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	ft_last2first(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ft_swap_2(t_stack **stack)
{
	int temp;

	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

void	ft_push2other(t_stack **from, t_stack **to)
{
	t_stack	*push;
	t_stack *oldto;

	if (!*from)
		return;
	push = *from;
	ft_delete_node(from);
	if (!*to)
	{
		*to = push;
		(*to)->next = *to;
		(*to)->prev = *to;
	}
	else
	{
		oldto = (*to)->prev;
        (*to)->prev = push;
        (*to)->prev->next = *to;
        (*to)->prev->prev = oldto;
        (*to)->prev->prev->next = push;
        *to = (*to)->prev;
	}
}