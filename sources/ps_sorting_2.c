/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:13:46 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/03 12:54:33 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5(t_stack *stack)
{
	int i;
	int min;
	int max;
	t_stack *stack_b;
	t_stack *stack_a;

	i = 0;
	stack_a = stack;
	stack_b = NULL;
//	printf ("\nMIN: %i", ft_stack_min(stack));
	min = ft_stack_min(stack);
//	printf ("\nMAX: %i", ft_stack_max(stack));
	max = ft_stack_max(stack);
	while (i <= ft_stack_len(stack_a))
	{
		if ((stack_a->data == min) || (stack_a->data == max))
			ft_push2other(&stack_a, &stack_b, 5);
		else
			ft_first2last(&stack_a, 6);
		i++;
	}
//	printf("\nA: ");
//	ft_print_stack(stack_a);
//	printf("\nB: ");
//	ft_print_stack(stack_b);
	if (!(ft_issorted(stack_a)))
		ft_sort_3(&stack_a);
	if (stack_b->data < stack_b->next->data)
		ft_swap_2(&stack_b, 2);
	ft_push2other(&stack_b, &stack_a, 4);
	ft_first2last(&stack_a, 6);
	ft_push2other(&stack_b, &stack_a, 4);
//	printf("\nA: ");
//	ft_print_stack(stack_a);
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
	int num;
	int bit;
	
	bit = 31;
	if (ft_stack_max(stack) > -(ft_stack_min(stack)))
		num = ft_stack_max(stack);
	else
		num = -(ft_stack_min(stack));
	while (((num >> bit) & 1) == 0)
		bit--;
	return (bit);
}
