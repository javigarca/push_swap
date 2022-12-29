#include "push_swap.h"

t_dtint	ft_data_load(char **data)
{
	char	*arguments;
	char	**argument;
	t_dtint	datareturn;
	int		i;

	i = 0;
	arguments = ft_args_join(data);
	ft_check_num(arguments);
	datareturn.nb = (int *) malloc(sizeof (int *) * ft_num_sub(arguments, ' '));
	argument = ft_split(arguments, ' ');
	while (argument[i])
	{
		datareturn.nb[i] = ft_myatoi(argument[i]);
		free(argument[i++]);
	}
	free(arguments);
	datareturn.len = i;
	ft_print_int(datareturn.nb, datareturn.len);
	ft_check_dupl(datareturn.nb, datareturn.len);
	return (datareturn);
}

void	ft_check_dupl(int *data, int len)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < len)
	{
		while (++k < len)
		{
			if ((data[i] == data[k]) && (i != k))
				if (!ft_isspace(*data))
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

void	ft_check_num(char *data)
{
	while (*data)
	{
		if (!ft_isdigit(*data))
			if (!ft_isspace(*data))
				ft_exit_error(3);
		data++;
	}
}
