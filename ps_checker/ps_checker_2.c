/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:07:13 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/09 17:37:29 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_issorted(*stack_a)) || (*stack_b))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
}

t_dtint	ft_checker_stacker(char **data, int argc)
{
	t_dtint	datart;

	pre_validation(data, argc);
	ft_data_validation(data, argc);
	datart = ft_data_load(data, argc);
	if (ft_check_dupl(datart))
	{
		free(datart.nb);
		ft_exit_error();
	}
	return (datart);
}
