/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2022/12/20 00:27:23 by javigarc         ###   ########.fr       */
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

// push_swap //
void	ft_print_int(int *dt, int len);
// ps_data //
int		*ft_data_load(char **data);
void	ft_check_dupl(int *data, int len);
void	ft_check_num(char *data);
char	*ft_args_join(char **data);
int		ft_num_sub(const char *str, char c);
// ps_error //
void	ft_exit_error(int code);
int		ft_isspace(int c);
// ps_list_utils //
t_stack	*ft_build_stack(int *dt);
int		ft_insert_node_start(t_stack **node, int dt);
int		ft_create_node_end(t_stack **node, int dt);
int		ft_delete_node_end(t_stack **node, int dt);
void	ft_print_stack(t_stack *node);
//  //
//  //
#endif
