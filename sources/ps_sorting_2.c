/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:13:46 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/03 18:56:48 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_4(t_stack *stack)
{
	int		i;
	int		min;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	min = ft_stack_min(stack);
	while (stack->data != min)
		ft_first2last(&stack, 6);
	ft_push2other(&stack, &stack_b, 5);
	ft_sort_3(&stack);
	ft_push2other(&stack_b, &stack, 4);
	free(stack);
}

void	ft_sort_5(t_stack *stack)
{
	int		i;
	int		min;
	int		max;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	min = ft_stack_min(stack);
	max = ft_stack_max(stack);
	while (ft_stack_len(stack) > 3)
	{
		if ((stack->data == min) || (stack->data == max))
			ft_push2other(&stack, &stack_b, 5);
		else
			ft_first2last(&stack, 6);
	}
	ft_sort_3(&stack);
	if ((stack_b->data < stack_b->next->data))
		ft_swap_2(&stack_b, 2);
	ft_push2other(&stack_b, &stack, 4);
	ft_first2last(&stack, 6);
	ft_push2other(&stack_b, &stack, 4);
	free(stack);
}

int	ft_stack_min(t_stack *stack)
{
	int		min;
	int		i;

	if (!stack)
		return (0);
	min = INT_MAX;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_bit(t_stack *stack)
{
	int	num;
	int	bit;

	bit = 31;
	if (ft_stack_max(stack) > -(ft_stack_min(stack)))
		num = ft_stack_max(stack);
	else
		num = -(ft_stack_min(stack));
	while (((num >> bit) & 1) == 0)
		bit--;
	return (bit);
}
