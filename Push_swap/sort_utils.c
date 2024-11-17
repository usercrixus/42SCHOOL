/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:44 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/17 21:35:25 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition(t_int_list **start, t_int_list **end, t_int_list **b, t_int_list **a, int pivots)
{
	t_int_list	*pivot;

	while (*a != *start)
		rotate(a);
	pivot = 0;
	while (*a != *end)
	{
		if ((*a)->c > pivots)
			manage_push(b, a);
		else
		{
			if (!pivot)
				pivot = *a;
			rotate(a);
		}
	}
	if (!pivot)
		pivot = *a;
	while (*a != pivot)
		rrotate(a);
}

int	diff(int a, int b)
{
	return (a - b);
}

t_int_list	*get_pivot(t_int_list **start, t_int_list **end, int pivot)
{
	t_int_list	*buffer;
	t_int_list	*node;

	node = *start;
	buffer = *start;
	while (buffer != *end)
	{
		if (diff(node->c, pivot) > diff(buffer->c, pivot))
			node = buffer;
		buffer = buffer->next;
	}
	return (node);
}

struct s_minmax	get_min_max(t_int_list **start, t_int_list **end)
{
	struct s_minmax	minmax;
	t_int_list		*buffer;
	int				number;

	buffer = *start;
	minmax.max = buffer->c;
	minmax.min = buffer->c;
	while (buffer != *end)
	{
		number = buffer->c;
		if (number > minmax.max)
			minmax.max = number;
		if (number < minmax.min)
			minmax.min = number;
		buffer = buffer->next;
	}
	return (minmax);
}
