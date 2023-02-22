/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:03:39 by javigarc          #+#    #+#             */
/*   Updated: 2023/02/22 18:50:23 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_max_k(t_stack *stack)
{
	int	i;
	int	max;
	int	maxk;

	if (!stack)
		return (0);
	max = INT_MIN;
	i = -1;
	while (i++ < ft_stack_len(stack))
	{
		if (stack->data >= max)
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
	t_stack	*stack_b;

	stack_b = NULL;
	if (!stack)
		return ;
	ft_sort_new_a(&stack, &stack_b, chunks);
	ft_stack_indexing(&stack_b);
	while (stack_b != NULL)
	{
		if (stack_b->key == ft_stack_max_k(stack_b))
		{
			ft_best_op_b(&stack_b, stack_b->index);
			ft_push2other(&stack_b, &stack, 4);
			ft_stack_indexing(&stack_b);
		}
		else
			stack_b = stack_b->next;
	}
	ft_stack_free(&stack_b);
}

void	ft_sort_new_a(t_stack **stack_a, t_stack **stack_b, size_t chunks)
{
	int		elem;
	int		chunk;
	int		tlen;

	tlen = ft_stack_len(*stack_a);
	chunk = tlen / chunks;
	elem = 0;
	while (*stack_a)
	{
		while (elem <= chunk && *stack_a)
		{
			if ((*stack_a)->key <= chunk)
			{
				ft_best_op_a(stack_a, (*stack_a)->index);
				ft_push2other(stack_a, stack_b, 5);
				ft_stack_indexing(stack_a);
				elem++;
			}
			else
				*stack_a = (*stack_a)->next;
		}
		chunk += tlen / chunks;
	}
}
