/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:21:33 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/06 23:44:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_i(t_stack *stack)
{
	return (ft_stack_len(stack) - 1);
}

int ft_abs(int x)
{
	if (x < 0)
		return (-(x));
	else
		return ((x));
}

int	ft_best_op_min(t_stack *stack, int min)
{
	int len;
	int best;

	len = ft_stack_len(stack);
	if (min <= (len-min))
		best = min;
	else
		best =  -(min);
	return (best);
}
