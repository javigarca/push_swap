/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2022/12/15 23:06:26 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

void	printint(int *dt);
// ps_data //
int		*ft_data_load(char **data);
void	ft_check_data(int *data);
char	*ft_args_join(char **data);
int		ft_num_sub(const char *str, char c);
// ps_error //
void	ft_exit_error(int code);
void	ft_error_args();
void	ft_error_dupl();
//  //
//  //
//  //
#endif
