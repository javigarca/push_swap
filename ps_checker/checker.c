/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/17 11:18:56 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_dtint	data;
	char	*com;
	int		chk;

	if (argc == 1)
		exit(0);
	data = ft_checker_stacker(argv, argc);
	stack_a = ft_build_stack(data);
	free(data.nb);
	stack_b = NULL;
	chk = 0;
	com = get_next_line(0);
	while (com)
	{
		chk = ft_do_op(&stack_a, &stack_b, com);
		free (com);
		if (chk)
			ft_error_val(&stack_a, &stack_b);
		com = get_next_line(0);
	}
	ft_exit_checker(&stack_a, &stack_b);
	return (0);
}
