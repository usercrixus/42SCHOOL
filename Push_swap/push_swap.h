/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:55 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/19 20:56:32 by achaisne         ###   ########.fr       */
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
void			swap(t_int_list **stack_pushed, t_int_list **stack_poped, int verbose);
void			push(t_int_list **stack, t_int_list **node);
void			swap_top(t_int_list **stack);
void			rotate(t_int_list **stack);
void			rrotate(t_int_list **stack);
void			rr(t_int_list **stacka, t_int_list **stackb);
int				list_len(t_int_list **start, t_int_list **end);
void			print_list(t_int_list *a);
void			normalize(t_int_list **a, int *tab, int size);
void			sort_int(int *tab, int size);

#endif