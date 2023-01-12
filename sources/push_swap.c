/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/11 19:00:00 by javigarc         ###   ########.fr       */
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
	if (!ft_issorted(stack_a))
	{
		ft_stack_keying(&stack_a);
		ft_stack_indexing(&stack_a);
		ft_sort_select(stack_a);
	}
	ft_stack_free(&stack_a);
	free(data.nb);
//	system("leaks push_swap");
	return (0);
}

void	ft_sort_select(t_stack *stack_a)
{
	if (ft_stack_len(stack_a) < 4)
		ft_sort_3(&stack_a);
	if (ft_stack_len(stack_a) == 4)
		ft_sort_4(stack_a);
	if (ft_stack_len(stack_a) == 5)
		ft_sort_5(stack_a);
	if ((ft_stack_len(stack_a) > 5) && (ft_stack_len(stack_a) < 101))
		ft_sort_new(stack_a, 4);
	if (ft_stack_len(stack_a) > 100)
		ft_sort_big(stack_a);
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

void	ft_stack_free(t_stack **list)
{
	t_stack	*next;
	t_stack	*tmp;

	if (list && *list)
	{
		next = (*list)->next;
		while (next && (next != *list))
		{
			tmp = next;
			next = next->next;
			free(tmp);
		}
		free(*list);
		*list = NULL;
	}
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
