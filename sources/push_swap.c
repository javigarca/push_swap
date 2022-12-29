#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dtint	data;
	t_stack	*stack_a;

//	printf("Start:%d\n", argc);
	if (argc < 2)
		ft_exit_error(argc);
	data = ft_data_load(argv);
//	ft_print_int(data, datalen);
	stack_a = ft_build_stack(data);
	printf("\nStack: ");
	ft_print_stack(stack_a);
	stack_a = NULL;
	free(stack_a);
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
