/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:02:11 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/16 15:44:29 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last2first2(t_stack **stack_a, t_stack **stack_b, int op)
{
	ft_last2first(stack_a, 0);
	ft_last2first(stack_b, 0);
	if (op)
		ft_pr_action(op);
}

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b, int op)
{
	ft_swap_2(stack_a, 0);
	ft_swap_2(stack_b, 0);
	if (op)
		ft_pr_action(op);
}
