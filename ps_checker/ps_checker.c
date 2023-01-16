/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:31:35 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/16 18:49:48 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_op(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!ft_strcmp(com, "sa\n") || !ft_strcmp(com, "sb\n") || !ft_strcmp(com, "ss\n"))
		ft_do_swap(stack_a, stack_b, com);
	else if (!ft_strcmp(com, "pa\n"))
		ft_push2other(stack_b, stack_a, 0);
	else if (!ft_strcmp(com, "pb\n"))
		ft_push2other(stack_a, stack_b, 0);
	else if (!ft_strcmp(com, "ra\n") || !ft_strcmp(com, "rb\n") || !ft_strcmp(com, "rr\n"))
		ft_do_rotation(stack_a, stack_b, com);
	else if (!ft_strcmp(com, "rra\n") || !ft_strcmp(com, "rrb\n") || !ft_strcmp(com, "rrr\n"))
		ft_do_rev_rot(stack_a, stack_b, com);
	else
	{
		write(1, "NOOO", 4);
		return (1);
	}
	return (0);
}

void	ft_do_swap(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!ft_strcmp(com, "sa\n"))
		ft_swap_2(stack_a, 0);
	if (!ft_strcmp(com, "sb\n"))
		ft_swap_2(stack_b, 0);
	if (!ft_strcmp(com, "ss\n"))
		ft_swap_both(stack_a, stack_b, 0);
}

void	ft_do_rotation(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!ft_strcmp(com, "ra\n"))
		ft_first2last(stack_a, 0);
	if (!ft_strcmp(com, "rb\n"))
		ft_first2last(stack_b, 0);
	if (!ft_strcmp(com, "rr\n"))
		ft_first2last2(stack_a, stack_b, 0);
}

void	ft_do_rev_rot(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!ft_strcmp(com, "rra\n"))
		ft_last2first(stack_a, 0);
	if (!ft_strcmp(com, "rrb\n"))
		ft_last2first(stack_b, 0);
	if (!ft_strcmp(com, "rrr\n"))
		ft_last2first2(stack_a, stack_b, 0);
}
