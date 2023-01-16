/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/16 18:45:59 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_dtint	data;
	char	*com;
	int		chk;

	if (argc == 1)
		exit(0);
	ft_data_validation(argv, argc);
	data = ft_data_load(argv, argc);
	if (ft_check_dupl(data))
	{
		free(data.nb);
		ft_exit_error();
	}
	stack_a = ft_build_stack(data);
	stack_b = NULL;
	chk =  0;
	com = get_next_line(0);
	while ((com) && (chk == 0))
	{
		printf("COM:%s\n", com);
		chk=ft_do_op(&stack_a, &stack_b, com);
		free(com);
		com = get_next_line(0);
	}
//	free(com);
	if (!(ft_issorted(stack_a)) || (stack_b))
	{
			ft_print_stack(stack_a);
			write(1, "BAD", 3);
		chk++;
	}
	if (chk)
	{
		write (1, "KO\n", 3);
	}
	else
		write (1, "OK\n", 3);
	free(data.nb);
	ft_stack_free(&stack_a);
	ft_stack_free(&stack_b);
	return (0);
}
