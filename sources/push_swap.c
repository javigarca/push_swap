#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dtint	data;
	t_stack	*stack_a;
	t_stack *stack_b;
//	int sort;
//	int len;

//	printf("Start:%d\n", argc);
	if (argc < 2)
		ft_exit_error(argc);
	data = ft_data_load(argv);
//	ft_print_int(data, datalen);
	stack_a = ft_build_stack(data);
	stack_b = NULL;
	printf("\nStack: ");
	ft_print_stack(stack_a);
//	ft_delete_node(&stack_a);
//	printf("\nStack del: ");
//	ft_print_stack(stack_a);
//	ft_first2last(&stack_a);
//	printf("\nStack l2f: ");
//	ft_print_stack(stack_a);
//	ft_last2first(&stack_a);
//	printf("\nStack f2l:");
//	ft_print_stack(stack_a);
//	ft_swap_2(&stack_a);
//	printf("\nStack sw2:");
//	ft_print_stack(stack_a);
//	ft_push2other(&stack_a, &stack_b);
//	printf("\nStack push A:");
//	ft_print_stack(stack_a);
//	printf("\nStack push B:");
//	ft_print_stack(stack_b);
//	sort = ft_issorted(stack_a);
//	printf("\nres sort: %i\n", sort);
//	len = ft_stack_len(stack_a);
//	printf("len: %i\n", len);
	
/* ** END ** */	
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
