/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:21:33 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/11 10:20:53 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_i(t_stack *stack)
{
	return (ft_stack_len(stack) - 1);
}

int ft_abs(int x)
{
	if (x < 0)
		return (-(x));
	else
		return ((x));
}

void	ft_best_op_a(t_stack **stack, int min)
{
	int len;

	len = ft_stack_len(*stack);
	if (len == 1)
		return;
	if (min <= (len/2))
	{
		while (min-- > 1)
		{
			*stack = (*stack)->prev;
			ft_first2last(stack, 6);
		}
	}
	else
	{
		min = len + 1 - min;
		while (min-- > 0)
		{
			*stack = (*stack)->next;
			ft_last2first(stack, 9);
		}
	}
}
void	ft_best_op_b(t_stack **stack, int max)
{
	int len;

	len = ft_stack_len(*stack);
	if (len == 1)
		return;
	if (max <= (len/2))
	{
		while (max-- > 1)
		{
			*stack = (*stack)->prev;
			ft_first2last(stack, 7);
		}
	}
	else
	{
		max = len + 1 - max;
		while (max-- > 0)
		{
			*stack = (*stack)->next;
			ft_last2first(stack, 10);
		}
	}
}
