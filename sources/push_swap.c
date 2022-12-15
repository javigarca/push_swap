#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*data;

	printf("Start:%d\n", argc);
	if (argc < 2)
		ft_exit_error(argc);
	data = ft_data_load(argv);
	printint(data);

//	ft_check_data(data);
	return (0);
}

void	printint(int *dt)
{
	int i = 0;

	while (dt[i])
	{
		printf("int %d: %d \n", i, dt[i]);
		i++;
	}
}
