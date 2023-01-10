/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:04:23 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/10 21:17:06 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_load_nodes(t_dtint dt, t_stack **fnode, t_stack **lnode, \
		t_stack **stack)
{
	t_stack	*next_node;
	int		i;

	i = 1;
	while (i < dt.len)
	{
		next_node = (t_stack *) malloc(sizeof (t_stack));
		if (!next_node)
			ft_exit_error();
		next_node->data = dt.nb[i];
		next_node->index = 0;
		next_node->next = *fnode;
		(*stack)->next = next_node;
		*lnode = *stack;
		*stack = next_node;
		(*stack)->prev = *lnode;
		i++;
	}
}

t_stack	*ft_build_stack(t_dtint dt)
{
	t_stack	*stack;
	t_stack	*first_node;
	t_stack	*last_node;

	stack = (t_stack *) malloc(sizeof (t_stack));
	if (!stack)
		ft_exit_error();
	stack->data = dt.nb[0];
	stack->index = 0;
	stack->next = stack;
	stack->prev = stack;
	first_node = stack;
	ft_load_nodes(dt, &first_node, &last_node, &stack);
	last_node = stack;
	stack = stack->next;
	stack->prev = last_node;
	return (stack);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	printf("\n*%i*", current->data);
	printf("i%i-", current->index);
	printf("k%i-", current->key);
	current = current->next;
	while (current != stack)
	{
		printf("*%i*", current->data);
		if (current->index)
			printf("i%i-", current->index);
		if (current->key)
			printf("k%i-", current->key);
		current = current->next;
	}
	printf("\n");
}

void	ft_delete_node(t_stack **nodel)
{
	if (*nodel == (*nodel)->next)
		*nodel = NULL;
	else
	{
		(*nodel)->next->prev = (*nodel)->prev;
		(*nodel)->prev->next = (*nodel)->next;
		*nodel = (*nodel)->next;
	}
}

int	ft_stack_len(t_stack *stack)
{
	t_stack	*head;
	int		len;

	if (!stack)
		return (0);
	head = stack;
	stack = stack->next;
	len = 1;
	while (stack != head)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
