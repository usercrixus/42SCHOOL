/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:19:06 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 18:10:22 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*get_max_lis(t_int_list *start)
{
	t_int_list	*result;
	t_int_list	*buffer;

	result = start;
	buffer = start->next;
	while (buffer != start)
	{
		if (buffer->lis > result->lis)
			result = buffer;
		buffer = buffer->next;
	}
	return (result);
}

void	calculate_lis(t_int_list *start, t_int_list *current)
{
	t_int_list	*buffer_previous;

	buffer_previous = current;
	while (buffer_previous != start)
	{
		buffer_previous = buffer_previous->previous;
		if (buffer_previous->c > current->c)
		{
			if (1 + buffer_previous->lis > current->lis)
			{
				current->lis = 1 + buffer_previous->lis;
				current->lis_previous = buffer_previous;
			}
		}
	}
}

void	set_lis(t_int_list *a)
{
	t_int_list	*current;
	t_int_list	*end;
	t_int_list	*start;
	t_int_list	*max_lsi;

	start = get_maximum(a);
	current = start->next;
	while (current != start)
	{
		calculate_lis(start, current);
		current = current->next;
	}
	current = start->next;
	current = get_maximum(start);
	max_lsi = get_max_lis(current);
	while (max_lsi)
	{
		max_lsi->lis = -1;
		max_lsi = max_lsi->lis_previous;
	}
}
