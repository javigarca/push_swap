/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:03:39 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/11 10:57:21 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_max_k(t_stack *stack)
{
	int	i;
	int	max;
	int maxk;

	if (!stack)
		return (0);
	max = INT_MIN;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data > max)
		{
			max = stack->data;
			maxk = stack->key;
		}
		stack = stack->next;
	}
	return (maxk);
}

void	ft_sort_new(t_stack *stack, size_t chunks)
{
	int		elem;
	int		chunk;
	int		tlen;
	t_stack	*stack_b;

	if (!stack)
		return;
	tlen = ft_stack_len(stack);
	chunk = tlen / chunks;
	stack_b = NULL;
	elem = 0;
	while (stack)
	{
		while (elem <= chunk && stack)
		{
			if (stack->key <= chunk)
			{
				ft_best_op_a(&stack, stack->index);
				ft_push2other(&stack, &stack_b, 5);
				ft_stack_indexing(&stack);
				elem++;
			}
			else
				stack = stack->next;
		}
		chunk += tlen/chunks;
	}
//	printf("eN B*-*-*---*-*----*\n");
	ft_stack_indexing(&stack_b);
	while (stack_b != NULL)
	{
//		ft_print_stack(stack_b);
		if (stack_b->key == ft_stack_max_k(stack_b))
		{
			ft_best_op_b(&stack_b, stack_b->index);
			ft_push2other(&stack_b, &stack, 4);
			ft_stack_indexing(&stack_b);
		}
		else
			stack_b = stack_b->next;
	}
	if (!(ft_issorted(stack)))
		ft_print_stack(stack);
}
