#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dtint	data;
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc == 1)
		exit(1);
	data = ft_data_load(argv);
	stack_a = ft_build_stack(data);
	stack_b = NULL;
	if (ft_issorted(stack_a))
		return (0);
	else
	{
		if (ft_stack_len(stack_a) < 4)
			ft_sort_3(&stack_a);
		else
			if (ft_stack_len(stack_a) < 6)
				ft_sort_5(stack_a);
			else
				ft_sort_big(stack_a);
	}
	stack_a = NULL;
	stack_b = NULL;
	free(stack_a);
	free(stack_b);
	free(data.nb);
//	system("leaks push_swap");
	return (0);
}

void	ft_print_int(int *dt, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("int %d: %d\n", i, dt[i]);
		i++;
	}
}
