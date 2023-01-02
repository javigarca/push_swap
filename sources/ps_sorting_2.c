/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:13:46 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/02 23:33:38 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5(t_stack *stack)
{
	int i;
	int k;
	int min;
	t_stack *stack_b;
	t_stack *stack_a;

	k = 0;
	stack_a = stack;
	stack_b = NULL;
	while (k < 2)
	{
		i = 0;
		min = ft_stack_min(stack_a);
		while (i < ft_stack_len(stack_a))
		{
			if (stack_a->data == min)
			{
				ft_push2other(&stack_a, &stack_b, 5);
				k++;
				break;
			}
			ft_first2last(&stack_a, 6);
			i++;
		}
	}
//	printf("\nA: ");
//	ft_print_stack(stack_a);
//	printf("\nB: ");
//	ft_print_stack(stack_b);
	if (!(ft_issorted(stack_a)))
		ft_sort_3(stack_a);
	if (stack_b->data < stack_b->next->data)
		ft_swap_2(&stack_b, 2);
	ft_push2other(&stack_b, &stack_a, 4);
	ft_push2other(&stack_b, &stack_a, 4);
}

int	ft_stack_min(t_stack *stack)
{
	t_stack	*head;
	int		min;

	if (!stack)
		return (0);
	head = stack;
	stack = stack->next;
	min = INT_MAX;
	while (stack != head)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}
