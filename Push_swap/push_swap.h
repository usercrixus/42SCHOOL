/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:55 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/17 21:36:17 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_int_list
{
	int					c;
	struct s_int_list	*next;
	struct s_int_list	*previous;
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

t_int_list		*create_node(int c);
void			manage_push(t_int_list **stack_pushed, t_int_list **stack_poped);
void			push(t_int_list **stack, t_int_list **node);
void			swap(t_int_list **stack);
void			rotate(t_int_list **stack);
void			rrotate(t_int_list **stack);
int				is_sorted_a(t_int_list **start, t_int_list **end);
int				list_len(t_int_list **start, t_int_list **end);
void			print_list(t_int_list *a);
void			partition(t_int_list **start, t_int_list **end, t_int_list **b, t_int_list **a, int pivots);
t_int_list		*get_pivot(t_int_list **start, t_int_list **end, int pivot);
struct s_minmax	get_min_max(t_int_list **start, t_int_list **end);

#endif