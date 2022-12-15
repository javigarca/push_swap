#include "push_swap.h"

void	ft_exit_error(int code)
{
	if (code == 1)
		ft_error_args();
	if (code == 2)
		ft_error_dupl();
}

void	ft_error_args()
{
	ft_putstr_fd("ERROR, not enough arguments\n", 1);
	exit(1);
}

void	ft_error_dupl()
{
	ft_putstr_fd("ERROR, some argument is duplicated\n", 1);
	exit(1);
}

