/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:03:39 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/10 22:20:06 by javigarc         ###   ########.fr       */
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
	int		elem;
	int		chunk;
	int		tlen;
	int		clen;
//	int		i;
	t_stack	*stack_b;
	t_stack	*head;

	if (!stack)
		return;
	tlen = ft_stack_len(stack);
	clen = tlen;
	chunk = tlen / 4;
//	printf("CH: %i", chunk);
	stack_b = NULL;
	elem = 0;
	ft_print_stack(stack);
	while (chunk <= tlen)
	{
		while (elem <=chunk)
		{
			if (stack->key <= chunk)
			{
//				printf("k: %i - ck: %i", stack->key, chunk);
//				best = ft_best_op_min(stack, stack->index);
				ft_best_op_min(&stack, stack->index);
//				printf("chunk:%i inx:%i\n", chunk, stack->index);
				ft_push2other(&stack, &stack_b, 5);
				ft_stack_indexing(&stack);
				head = stack;
				elem++;
			}
			else
				stack = stack->next;
		}
		printf("-----chunk: %i\n", chunk);
//		ft_print_stack(stack_b);
//		printf("vuelta %i", chunk);
/*		printf("\nHD:");
		ft_print_stack(head);
		printf("\nST:");
	ft_print_stack(stack);
*/		printf("STHD:");

		stack = head;
		clen = ft_stack_len(stack);
	ft_print_stack(stack);
		chunk += tlen/4;
	}
	printf("---------EN B\n");
	while (stack_b != NULL)
	{
		if (stack_b->key == ft_stack_max_k(stack_b))
			ft_push2other(&stack_b, &stack, 4);
		else
			ft_first2last(&stack_b, 7);
	}
	if (!(ft_issorted(stack)))
		ft_print_stack(stack);
}
