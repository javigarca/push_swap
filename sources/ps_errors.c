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
	if (code == 5)
		ft_putstr_fd("ERROR, some number out of INT scope\n", 1);
//	system ("leaks push_swap");
	exit(1);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_myatoi(const char *str)
{
	int	i;
	int	sign;
	int	atoi;

	i = 0;
	atoi = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		atoi *= 10;
		atoi += (str[i] - 48);
		if ((atoi < INT_MIN) || (atoi > INT_MAX))
			ft_exit_error(5);
		i++;
	}
	return (atoi * sign);
}
