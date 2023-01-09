/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:37:50 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/07 21:55:57 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_quick(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return;
	t_stack *pivot = (t_stack *)malloc(sizeof(t_stack));
	t_stack *left = NULL;
	t_stack *right = NULL;
	t_stack *current = (*stack)->next;
	if (!pivot)
		ft_exit_error();
		return;
	
	while (current != *stack)
	{
		t_stack *next = current->next;
		if (current->data < pivot->data)
		{
			current->prev = NULL;
			current->next = left;
			if (left)
				left->prev = current;
			left = current;
			ft_swap_2(&pivot, 2);
			ft_push2other(&pivot, &left, 4);
		}
		else
		{
			current->prev = right;
			current->next = NULL;
			if (right)
				right->next = current;
			right = current;
			ft_swap_2(&pivot, 2);
			ft_push2other(&pivot, &right, 5);
		}
		current = next;
	}
	ft_sort_quick(&left);
	ft_sort_quick(&right);
	if (left)
	{
		*stack = left;
		left->prev = pivot;
	}
	else
	{
		*stack = pivot;
	}
	pivot->next = right;
	if (right)
	{
		right->prev = pivot;
	}
}



/*
void	ft_sort_quick(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return;
	t_stack *pivot = (t_stack *)malloc(sizeof(t_stack));
	t_stack *left = NULL;
	t_stack *right = NULL;
	t_stack *current = (*stack)->next;
	if (!pivot)
		ft_exit_error();
	*pivot = **stack;
	while (current != *stack)
	{
		t_stack *next = current->next;
		if (current->data < pivot->data)
		{
			current->prev = NULL;
			current->next = left;
			if (left)
				left->prev = current;
			left = current;
			ft_swap_2(&pivot, 2);
			ft_push2other(&pivot, &left, 4);
		}
		else
		{
			current->prev = right;
			current->next = NULL;
			if (right)
				right->next = current;
			right = current;
			ft_swap_2(&pivot, 2);
			ft_push2other(&pivot, &right, 5);
		}
		current = next;
	}
	ft_sort_quick(&left);
	ft_sort_quick(&right);
	if (left)
	{
		*stack =
		*/
