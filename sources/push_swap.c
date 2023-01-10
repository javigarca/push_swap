/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/10 13:44:26 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dtint	data;
	t_stack	*stack_a;

	if (argc == 1)
		exit(0);
	data = ft_data_load(argv);
	stack_a = ft_build_stack(data);
	if (ft_issorted(stack_a))
		return (0);
	else
	{
		ft_stack_keying(&stack_a);
		ft_stack_indexing(&stack_a);
		if (ft_stack_len(stack_a) < 4)
			ft_sort_3(&stack_a);
		if (ft_stack_len(stack_a) == 4)
			ft_sort_4(stack_a);
		if (ft_stack_len(stack_a) == 5)
			ft_sort_5(stack_a);
		if (ft_stack_len(stack_a) > 5)
//		 	ft_sort_big(stack_a);
//			ft_sort_100(stack_a);
			ft_sort_new(stack_a);
	//	stack_a=ft_merge_sort(&stack_a);
//			ft_sort_quick(&stack_a);
	}
//	ft_print_stack(stack_a);
//	ft_free_stack(&stack_a);
//	free(stack_a);
	free(data.nb);
//	system("leaks push_swap");
	return (0);
}

void	ft_print_int(int *dt, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("int %d: %d\n", i, dt[i]);
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	int elem;

	elem = ft_stack_len(*stack);
	head = *stack;
	while (elem)
	{
		free(head);
		head = (*stack)->next;
		elem--;
	}
	stack = NULL;
	//free(*stack);
}

int	ft_issorted(t_stack *stack)
{
	t_stack	*head;
	int		sort;

	head = stack;
	stack = stack->next;
	sort = 0;
	while (stack != head)
	{
		if (stack->data < stack->prev->data)
			sort++;
		stack = stack->next;
	}
	if (!sort)
		return (1);
	return (0);
}
