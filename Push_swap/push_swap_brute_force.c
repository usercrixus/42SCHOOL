/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_brute_force.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:12:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 18:15:35 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	final_roration(t_int_list **a, int max)
{
	int			i;
	int			len;
	t_int_list	*buffer_right;
	t_int_list	*buffer_left;

	buffer_right = (*a);
	buffer_left = (*a);
	len = list_len(a, &(*a)->previous) / 2 + 1;
	i = 0;
	while (i < len)
	{
		if (buffer_right->c == max)
			return (i * -1);
		else if (buffer_left->c == max)
			return (i * 1);
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		i++;
	}
	return (0);
}

void	depush_a(t_int_list **b, t_int_list **a, int max)
{
	int	len;

	len = list_len(a, &(*a)->previous);
	while (len)
	{
		if ((*a)->previous->lis == -1)
			rotate(a, 'a');
		else if ((*a)->previous->c >= max * 0.5)
			push(b, a, 'b', 1);
		else if ((*a)->previous->c <= max * 0.5)
		{
			push(b, a, 'b', 1);
			rotate(b, 'b');
		}
		len--;
	}
}

void	depush_b(t_int_list **b, t_int_list **a)
{
	t_way	best_way;

	while (*b)
	{
		best_way = get_best_branch(&(*b)->previous, &(*a)->previous);
		manage_rotate(a, b, best_way);
		push(a, b, 'a', 1);
	}
}

int	sort_brute_force(t_int_list **b, t_int_list **a, int max)
{
	t_way	best_way;	

	depush_a(b, a, max);
	depush_b(b, a);
	best_way.branch = 0;
	best_way.way = final_roration(a, max);
	manage_rotate(a, b, best_way);
}
