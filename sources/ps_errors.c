#include "push_swap.h"

void	ft_exit_error(int code)
{
//	if (code == 1)
//		ft_putstr_fd("ERROR, not enough arguments\n", 1);
//	if (code == 2)
//		ft_putstr_fd("ERROR, some argument is duplicated\n", 1);
//	if (code == 3)
//		ft_putstr_fd("ERROR, some argument is not a number\n", 1);
//	if (code == 4)
//		ft_putstr_fd("ERROR, not enough memory for allocation\n", 1);
//	if (code == 5)
//		ft_putstr_fd("ERROR, some number out of INT scope\n", 1);
//	system ("leaks push_swap");
	code = 0;
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if ((c == 43) || (c == 45))
		return (1);
	return (0);
}

int	ft_myatoi(const char *str)
{
	int		i;
	int		sign;
	long	atoi;

	i = 0;
	atoi = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		ft_exit_error(2);
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		atoi *= 10;
		atoi += (str[i] - 48);
		i++;
	}
	if (((atoi * sign) < INT_MIN) || ((atoi * sign) > INT_MAX))
		ft_exit_error(5);
	return (atoi * sign);
}

void	ft_pr_action(int op)
{
	if (op == 1)
		write(1, "sa\n", 3);
	if (op == 2)
		write(1, "sb\n", 3);
	if (op == 3)
		write(1, "ss\n", 3);
	if (op == 4)
		write(1, "pa\n", 3);
	if (op == 5)
		write(1, "pb\n", 3);
	if (op == 6)
		write(1, "ra\n", 3);
	if (op == 7)
		write(1, "rb\n", 3);
	if (op == 8)
		write(1, "rr\n", 3);
	if (op == 9)
		write(1, "rra\n", 4);
	if (op == 10)
		write(1, "rrb\n", 4);
	if (op == 11)
		write(1, "rrr\n", 4);
}
