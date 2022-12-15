#include "push_swap.h"

int	*ft_data_load(char **data)
{
	char	*arguments;
	char	**argument;
	int		*datareturn;
	int		i;

	i = 0;
	arguments = ft_args_join(data);
	datareturn = (int *) malloc(sizeof (int) * ft_num_sub(arguments, ' '));
	ft_putstr_fd(arguments, 1);
	ft_putnbr_fd(ft_num_sub(arguments, ' '), 1);
	argument = ft_split(arguments, ' ');
	ft_putstr_fd("\nArgumentos\n", 1);
	while (argument[i])
	{
	ft_putstr_fd(argument[i], 1);
	ft_putstr_fd("--\n", 1);
		datareturn[i] = ft_atoi(argument[i]);
	ft_putnbr_fd(datareturn[i], 1);
	ft_putstr_fd("**\n", 1);
		i++;
	}
	free(argument);
	free(arguments);
	ft_putstr_fd("FIN", 1);
	return (datareturn);
}

void	ft_check_data(int *data)
{
	int i;
	int	k;
	int max;

	i = 0;
	k = 0;
	max = 0;
	while (data[i++])
		max++;
	i = 0;
	while (i < max)
	{
		while (++k < max)
		{
			if ((data[i] == data[k]) && (i != k))
				ft_exit_error(2);
		}
		k = 0;
		i++;
	}
}

char	*ft_args_join(char **data)
{
	int		i;
	char	*join;
	int		total;

	i = 1;
	total = 0;
	while (data[i])
		total += ft_strlen(data[i++]);
	i = 1;
	join = (char *) malloc(sizeof (char *) * total + 1);
	while (data[i])
	{
		join = ft_strjoin(join, data[i++]);
		join = ft_strjoin(join, " ");
	}
	return (join);
}


int	ft_num_sub(const char *str, char c)
{
	int	cont;
	int	sub;

	cont = 0;
	sub = 0;
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != c && sub == 0)
		{
			sub = 1;
			cont++;
		}
		else if (*str == c)
		{
			sub = 0;
		}
		str++;
	}
	return (cont);
}
