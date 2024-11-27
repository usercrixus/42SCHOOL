/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:06:12 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/27 04:37:20 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/math/math.h"

void	partition(t_int_list **start, t_int_list **end, t_int_list **b, t_int_list **a, int pivots)
{
	while (*a != *start)
		rrotate(a);
	while (*a != *end)
	{
		if ((*a)->c > pivots)
			swap(b, a, 1);
		else
		{
			rotate(a);
		}
	}
	if ((*a)->c < pivots)
		swap(b, a, 1);
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

struct s_minmax	get_min_max(t_int_list *start, t_int_list *end)
{
	struct s_minmax	minmax;
	t_int_list		*buffer;
	int				number;

	buffer = start;
	minmax.max = buffer->c;
	minmax.min = buffer->c;
	while (buffer != end)
	{
		number = buffer->c;
		if (number > minmax.max)
			minmax.max = number;
		if (number < minmax.min)
			minmax.min = number;
		buffer = buffer->next;
	}
	number = buffer->c;
	if (number > minmax.max)
		minmax.max = number;
	if (number < minmax.min)
		minmax.min = number;
	return minmax;
}
int count = 0;
int	quick_sort(t_int_list **start, t_int_list **end, t_int_list **b, t_int_list **a)
{
	t_int_list		*pivot_node;
	struct s_minmax	minmax;
	int				pivot;
	
	count++;
	if (count == 450)
		exit(1);
	pivot_node = *a;
	if (is_sorted_a(start, end))
		return (0);
	printf("start : %d end : %d\n", (*start)->c, (*end)->c);
	minmax = get_min_max(*start, *end);
	pivot = (minmax.max + minmax.min) / 2;
	//printf("pivot : %d min :%d max : %d\n", pivot, minmax.min, minmax.max);
	if (minmax.max == minmax.min)
		return (0);
	partition(start, end, b, a, pivot);
	*end = *a;
	while (*b)
		swap(a, b, 1);
	pivot_node = *a;
	print_list(*a);
	printf("pivot : %d end : %d\n", pivot_node->c, (*end)->c);
	quick_sort(&pivot_node, end, b, a);
	print_list(*a);
	printf("start : %d piv : %d\n", (*start)->c, pivot_node->c);
	quick_sort(start, &pivot_node, b, a);
	print_list(*a);
	return (1);
}
