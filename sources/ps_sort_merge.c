/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:44:41 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/09 14:03:28 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void ft_merge_sort(t_stack **stack)
{
    t_stack *left;
    t_stack *right;

    if (!(*stack) || (*stack)->next == *stack)
        return;
    ft_stack_keying(stack);
	left = *stack;
    right = (*stack)->next;
    while (right->next != *stack)
	{
		left = left->next;
        right = right->next;
        if (right->next != *stack)
			right = right->next;
    }
	right->next = left->next;
	left->next->prev = right;
	left->next = *stack;
	left->next->prev = left;
//	right->next->prev = NULL;
//	right->next = NULL;
//	left->next->prev = NULL;
//	left->next = NULL;

//	ft_merge_sort(&left);
//	ft_merge_sort(&right);
//  ft_print_stack(right);
	ft_merge(&left, &right);
  *stack = left;
  if (!ft_issorted(*stack))
	  ft_merge_sort(stack);
  printf("FINAL_____: ");
  ft_print_stack(*stack);
}

void ft_merge(t_stack **left, t_stack **right)
{
	t_stack *left_curr;
	t_stack *right_curr;
	int i;
	int len;

	left_curr = *left;
	right_curr = *right;
	len = ft_stack_len(*left);
	i = 0;
  printf("\nLeft:");
 ft_print_stack(left_curr);
 printf("\nRight:");
 ft_print_stack(right_curr);
	while (i < len)
	{
		while ((left_curr != NULL) && (right_curr != NULL))
		{
		    if ((left_curr->key > right_curr->key))
				ft_push2other(&right_curr, &left_curr, 4);
			ft_first2last(&left_curr, 6);
		}
		i++;
	}
	while (right_curr != NULL)
	{
		if (right_curr->key < right_curr->next->key)
			ft_swap_2(&right_curr, 2);
		ft_push2other(&right_curr, &left_curr, 4);
	}
	// Set the next and prev pointers to create a circular list
	(*left)->prev = left_curr;
	left_curr->next = *left;
	write(1, "\nEXIT", 5);
}*/

// This function divides the linked list into two parts and returns the head of second half.
t_stack *ft_split_stack(t_stack **stack)
{
   t_stack	*slowpointer;
   t_stack	*fastpointer;
   t_stack	*secondhalf;

   slowpointer = *stack;
   fastpointer = *stack;
	write(1, "entramos\n", 9);
//   while (fastpointer != NULL && fastpointer->next != NULL && fastpointer->next->next != NULL)
//   {
  //     fastpointer = fastpointer->next->next;
    //   slowpointer = slowpointer->next;
//   }
    while (fastpointer->next != *stack)
	{
		slowpointer = slowpointer->next;
        fastpointer = fastpointer->next;
        if (fastpointer->next != *stack)
			fastpointer = fastpointer->next;
    }
	write(1, "salimos\n", 8);
   secondhalf = slowpointer->next;
   // Separating the second part.
//	slowpointer->next = NULL;
	secondhalf->prev = fastpointer;
	fastpointer->next = secondhalf;
	slowpointer->next = *stack;
	slowpointer->next->prev = slowpointer;
   return (secondhalf);
}

// This function will merge two lists and will return the sorted list.
t_stack	*ft_merge(t_stack **first, t_stack **second)
{
   // If the 'firstList' linked list is empty, then we dont have to merge.
   if ((*first) == NULL)
       return (*second);

   // If the 'secondList' linked list is empty, then don’t have to merge.
   if ((*second) == NULL)
       return (*first);

   // Regular merge conditions.
   if ((*first)->data > (*second)->data)
   {
       (*second)->next = ft_merge(first, &(*second)->next);
       (*second)->next->prev = (*second);
       (*second)->prev = NULL;
       return (*second);
   }
   else
   {
       (*first)->next = ft_merge(&(*first)->next, second);
       (*first)->next->prev = (*first);
       (*first)->prev = NULL;
       return (*first);
   }
}

// It returns the sorted doubly linked list.
t_stack	*ft_merge_sort(t_stack **stack)
{
   if (*stack == NULL) {
       return *stack;
   }

   if ((*stack)->next == NULL) {
       return *stack;
   }
   t_stack *first; 
   t_stack *second;

   first = NULL;
   second = NULL;
   // Splitting the list.
//	ft_print_stack(*stack);
	write(1, "UN\n", 4);
   second = ft_split_stack(stack);
//	ft_print_stack(second);
	write(1, "DOS\n", 4);
   // Recursively calling merge sort on both the sublists.
   first = ft_merge_sort(stack);
//   second = ft_merge_sort(&second);
ft_print_stack(*stack);
printf("\n");
ft_print_stack(second);
printf("\n");
	write(1, "TRES\n", 5);
   // Merging the two sorted sub lists.
//   *stack = ft_merge(&first, &second);
	write(1, "CUATRO\n", 7);
   return (*stack);
}
