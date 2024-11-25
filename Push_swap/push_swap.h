/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:55 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 05:11:11 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/base/libft.h"
# include "../libft/math/math.h"

typedef struct s_int_list
{
	int					c;
	struct s_int_list	*next;
	struct s_int_list	*previous;
	int					lsi;
	struct s_int_list	*lsi_previous;
}	t_int_list;

struct s_pivots
{
	int	pivot_high;
	int	pivot_low;
};

struct s_minmax
{
	int	min;
	int	max;
};

struct s_way
{
	int branch;
	int way;
	int step;
};

//lis
void			set_lsi(t_int_list *start);
// linked list
t_int_list		*create_node(int c);
t_int_list		*pop(t_int_list **stack);
void			push(t_int_list **stack, t_int_list **node);
// brute force
struct s_way	get_best_branch(t_int_list **b, t_int_list **a);
int				get_best_way(t_int_list **a, int x);
int				manage_rotate(t_int_list **a, t_int_list **b, struct s_way best_way);
// helper
int				list_len(t_int_list **start, t_int_list **end);
int				is_min(t_int_list *a, int x);
int				is_max(t_int_list *a, int x);
void			print_list(t_int_list *a);
// normalize
void			normalize(t_int_list **a, int *tab, int size);
void			sort_int(int *tab, int size);
// action
void			swap_top(t_int_list **stack);
void			swap(t_int_list **stack_pushed, t_int_list **stack_poped, int verbose);
void			rotate(t_int_list **stack);
void			rrotate(t_int_list **stack);
void			rr(t_int_list **stacka, t_int_list **stackb);
void			rrr(t_int_list **stacka, t_int_list **stackb);

t_int_list		*pop(t_int_list **stack);

#endif