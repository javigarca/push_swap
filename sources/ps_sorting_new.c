/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:03:39 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/10 15:09:26 by javigarc         ###   ########.fr       */
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

void	ft_sort_new(t_stack *stack)
{
	int		best;
	int		chunk;
	int		tlen;
	int		clen;
	int		mov;
	int		i;
	t_stack	*stack_b;

	if (!stack)
		return;
	tlen = ft_stack_len(stack);
	clen = tlen;
	chunk = tlen / 4;
//	printf("CH: %i", chunk);
	stack_b = NULL;
	mov = 1;
	while (chunk <= tlen)
	{
		i = 0;
		while (i < clen)
		{
			if (stack->key < chunk)
			{
//				printf("k: %i - ck: %i", stack->key, chunk);
				best = ft_best_op_min(stack, stack->index);
				while (mov != 0)
				{
					if (best > 0)
					{
						ft_pr_action(9);
						mov--;
					}
					else
					{
						ft_pr_action(6);
						mov--;
					}
				}
				ft_push2other(&stack, &stack_b, 5);
				ft_stack_indexing(&stack);
			}
			else
				stack = stack->next;
			mov++;
			i++;
		}
//		printf("vuelta %i", chunk);
		clen = ft_stack_len(stack);
		chunk += tlen/4;
	}
	while (stack_b != NULL)
	{
		if (stack_b->key == ft_stack_max_k(stack_b))
			ft_push2other(&stack_b, &stack, 4);
		else
			ft_first2last(&stack_b, 7);
	}
//	ft_print_stack(stack);
}
