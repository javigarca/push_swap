/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:21:33 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/03 20:26:22 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_pos(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	slen;

	slen = ft_stack_len(*stack_a);
	while (slen)
	{
		if ((((*stack_a)->data >> bit) & 1) == 1)
		{
			ft_push2other(stack_a, stack_b, 5);
			if (ft_stack_len(*stack_b) > 1)
				ft_first2last(stack_b, 7);
		}
		else
			ft_first2last(stack_a, 6);
		slen--;
	}
	if (*stack_b)
	{
		slen = ft_stack_len(*stack_b);
		while (slen)
		{
			ft_push2other(stack_b, stack_a, 4);
			ft_first2last(stack_a, 6);
			slen--;
		}
	}
}

void	ft_sort_neg(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	slen;

	i = 0;
	slen = ft_stack_len(*stack_a);
	while (i < slen)
	{
		if ((((*stack_a)->data >> 31) & 1) == 1)
			ft_push2other(stack_a, stack_b, 5);
		else
			ft_first2last(stack_a, 6);
		i++;
	}
	if (*stack_b)
	{
		i = 0;
		slen = ft_stack_len(*stack_b);
		while (i < slen)
		{
			ft_push2other(stack_b, stack_a, 4);
			i++;
		}
	}
}

int	ft_stack_max(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack)
		return (0);
	max = INT_MIN;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

void	ft_sort_big(t_stack *stack)
{
	t_stack	*stack_b;
	int		bit;
	int		maxbit;

	maxbit = ft_find_bit(stack);
	stack_b = NULL;
	bit = 0;
	while (bit <= maxbit)
	{
		ft_sort_pos(&stack, &stack_b, bit);
		bit++;
	}
	ft_sort_neg(&stack, &stack_b);
}

void	ft_sort_3(t_stack **stack)
{
	if (ft_issorted(*stack))
		return ;
	if ((*stack)->data < (*stack)->next->data)
	{
		ft_last2first(stack, 9);
		if (!(ft_issorted(*stack)))
			ft_swap_2(stack, 1);
	}
	else
	{
		if ((*stack)->next->data > (*stack)->next->next->data)
		{
			ft_first2last(stack, 6);
			ft_swap_2(stack, 1);
		}
		else
			if ((*stack)->next->next->data > (*stack)->data)
				ft_swap_2(stack, 1);
		else
			ft_first2last(stack, 6);
	}
}
