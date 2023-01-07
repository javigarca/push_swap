/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:03:39 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/06 23:48:32 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_indexing(t_stack **stack)
{
	int		ord;
	t_stack *stack_i;

	ord = 1;
	stack_i = *stack;
	while (ord <= ft_stack_len(stack_i))
	{
		stack_i->index = ord++;
//		printf("\nvalor: %i --- orden: %i", stack_i->data, stack_i->index); 
		stack_i = stack_i->next;
	}
}

int	ft_stack_min_i(t_stack *stack)
{
	int	min;
	int	i;
	int	mini;

	if (!stack)
		return (0);
	min = INT_MAX;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data < min)
		{
			min = stack->data;
			mini = stack->index;
		}
		stack = stack->next;
	}
	return (mini);
}

int	ft_stack_min_i2(t_stack *stack)
{
	int	min;
	int	i;
	int	prev;
	int mini;

	if (!stack)
		return (0);
	prev = ft_stack_min_i(stack);
	if (ft_stack_len(stack) == 1)
		return (prev);
	min = INT_MAX;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if ((stack->data < min) && (stack->index != prev))
		{
			min = stack->data;
			mini = stack->index;
		}
		stack = stack->next;
	}
	return (mini);
}

int	ft_best_op(t_stack *stack, int min, int min2)
{
	int len;
	int valmin;
	int	valmin2;
	int best;

	if (min == min2)
		return (min);
	len = ft_stack_len(stack);
	if (min < (len-min))
		valmin = min;
	else
		valmin = len - min;
	if (min2 < (len-min2))
		valmin2 = min2;
	else
		valmin2 = len - min2;
	if (valmin < valmin2)
		best = min;
	else
		best = min2;
	if (best > (len/2))
		best *= -1;
	return (best);
}


void	ft_sort_100(t_stack *stack)
{
	int		min;
	int		min2;
	int		best;
	t_stack	*stack_b;

	ft_stack_indexing(&stack);
	stack_b = NULL;
//	ft_print_stack(stack);
	while (stack)
	{
		ft_stack_indexing(&stack);
		min = ft_stack_min_i(stack);
//			printf("\nMIN: %i\n", min);
		min2 = ft_stack_min_i2(stack);
//			printf("MIN2: %i\n", min2);
//		best = ft_best_op(stack, min, min2);
		best = ft_best_op_min(stack, min);
//			printf("BEST: %i\n", best);
		while (stack->index != ft_abs(best))
		{
///			printf("ABS: %i\n", ft_abs(best));
//			ft_exit_error();
			if (best > 0)
				ft_first2last(&stack, 6);
//				printf("mayor");
			else
				ft_last2first(&stack, 9);
//				printf("MENOR");
		}
		ft_push2other(&stack, &stack_b, 5);
	}
	while (stack_b)
	{
		if (stack_b->data < stack_b->next->data)
			ft_swap_2(&stack_b, 2);
		ft_push2other(&stack_b, &stack, 4);
	}
}
