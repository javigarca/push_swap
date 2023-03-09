/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:57:51 by javigarc          #+#    #+#             */
/*   Updated: 2023/03/09 14:16:09 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ptdata(t_dtint	data)
{
	int i;

	i=0;
	while (i < data.len)
		printf("dt:%i\n", data.nb[i++]);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_dtint	data;

	if (argc == 1)
		exit(0);
	if (argc == 2 && (argv[1] ==NULL))
		printf("ENTRO\n");
	else
		printf("NOOOOOOOO ENTRA: *%s*\n", argv[1]);
//		ft_exit_error();
//	pre_validation(argv, argc);
	ft_data_validation(argv, argc);
	data = ft_data_load(argv, argc);
//	ptdata(data);
	if (ft_check_dupl(data))
	{
		free(data.nb);
		ft_exit_error();
	}
	stack_a = ft_build_stack(data);
	if (!ft_issorted(stack_a))
	{
		ft_stack_keying(&stack_a);
		ft_stack_indexing(&stack_a);
		ft_sort_select(stack_a);
	}
	free(data.nb);
	ft_stack_free(&stack_a);
	return (0);
}


