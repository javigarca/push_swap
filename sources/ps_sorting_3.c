/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:21:33 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/10 22:15:08 by javigarc         ###   ########.fr       */
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

void	ft_best_op_min(t_stack **stack, int min)
{
	int len;

	len = ft_stack_len(*stack);
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

/*

int	ft_best_op_min(t_stack *stack, int min)
{
	int len;
	int best;

	len = ft_stack_len(stack);
	if (min <= (len/2))
		best = min;
	else
		best =  (min - len) - 1;
	return (best);
int	ft_best_op_max(t_stack *stack, int max)
{
	int len;
	int best;

	len = ft_stack_len(stack);
	if (min 1<= (len-min))
		best = min;
	else
		best =  -(min);
	return (best);
}*/
