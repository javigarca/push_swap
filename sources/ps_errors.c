#include "push_swap.h"

void	ft_exit_error(int code)
{
	if (code == 1)
		ft_putstr_fd("ERROR, not enough arguments\n", 1);
	if (code == 2)
		ft_putstr_fd("ERROR, some argument is duplicated\n", 1);
	if (code == 3)
		ft_putstr_fd("ERROR, some argument is not a number\n", 1);
	if (code == 4)
		ft_putstr_fd("ERROR, not enough memory for allocation\n", 1);
//	system ("leaks push_swap");
	exit(1);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}
