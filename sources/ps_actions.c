/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:02:11 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/06 20:02:04 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack *stack)
{
	t_stack	*head;
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

void	ft_first2last(t_stack **stack, int op)
{
	*stack = (*stack)->next;
	if (op)
		ft_pr_action(op);
}

void	ft_last2first(t_stack **stack, int op)
{
	*stack = (*stack)->prev;
	if (op)
		ft_pr_action(op);
}

void	ft_swap_2(t_stack **stack, int op)
{
	int	temp;

	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
	if (op)
		ft_pr_action(op);
}

void	ft_push2other(t_stack **from, t_stack **to, int op)
{
	t_stack	*push;
	t_stack	*oldto;

	if (*from)
	{
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
		if (op)
			ft_pr_action(op);
	}
}
