/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2023/01/02 22:47:12 by javigarc         ###   ########.fr       */
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
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;
typedef struct s_dtint
{
	int	*nb;
	int	len;
}			t_dtint;
// push_swap //
void	ft_print_int(int *dt, int len);
// ps_data //
t_dtint	ft_data_load(char **data);
void	ft_check_dupl(int *data, int len);
void	ft_check_num(char *data);
char	*ft_args_join(char **data);
int		ft_num_sub(const char *str, char c);
// ps_error //
void	ft_exit_error(int code);
int		ft_isspace(int c);
int		ft_issign(int c);
int		ft_myatoi(const char *str);
void	ft_pr_action(int op);
// ps_list_utils //
t_stack	*ft_build_stack(t_dtint dt);
void	ft_load_nodes(t_dtint dt, t_stack **fnode, t_stack **lnode, \
		t_stack **stack);
void	ft_delete_node(t_stack **nodel);
void	ft_print_stack(t_stack *node);
int		ft_stack_len(t_stack *stack);
// ps_actions //
int		ft_issorted(t_stack *stack);
void	ft_first2last(t_stack **stack, int op);
void	ft_last2first(t_stack **stack, int op);
void	ft_swap_2(t_stack **stack, int op);
void	ft_push2other(t_stack **from, t_stack **to, int op);
// ps_sorting.c //
void	ft_sort_pos(t_stack **stack_a, t_stack **stack_b, int bit);
void	ft_sort_neg(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_max(t_stack *stack);
void	ft_sort_big(t_stack *stack);
void	ft_sort_3(t_stack *stack);
// ps_sorting_2.c //
void	ft_sort_5(t_stack *stack);
int		ft_stack_min(t_stack *stack);
#endif
