/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:19:06 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/28 04:52:16 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*get_maximum(t_int_list *a)
{
	t_int_list	*buffer;

	buffer = a;
	while (!is_max(a, buffer->c))
	{
		buffer = buffer->next;
	}
	return (buffer);
}

t_int_list	*get_max_lsi(t_int_list *start)
{
	t_int_list	*result;
	t_int_list	*buffer;

	result = start;
	buffer = start->next;
	while (buffer != start)
	{
		if (buffer->lsi > result->lsi)
			result = buffer;
		buffer = buffer->next;
	}
	return (result);
}

void	calculate_lsi(t_int_list *start, t_int_list *current)
{
	t_int_list	*buffer_previous;

	buffer_previous = current;
	while (buffer_previous != start)
	{
		buffer_previous = buffer_previous->previous;
		if (buffer_previous->c > current->c)
		{
			if (1 + buffer_previous->lsi > current->lsi)
			{
				current->lsi = 1 + buffer_previous->lsi;
				current->lsi_previous = buffer_previous;
			}
		}
	}
}

t_int_list	*next_lsi_node(t_int_list *current, t_int_list *end)
{
	t_int_list	*buffer;
	t_int_list	*next_lsi_node;

	buffer = current->next;
	next_lsi_node = 0;
	while (buffer != end)
	{
		if (!next_lsi_node && buffer->lsi > current->lsi)
			next_lsi_node = buffer;
		else if (next_lsi_node && buffer->lsi < next_lsi_node->lsi && buffer->lsi > current->lsi)
			next_lsi_node = buffer;
		buffer = buffer->next;
	}
	if (!next_lsi_node && buffer->lsi > current->lsi)
		next_lsi_node = buffer;
	else if (next_lsi_node && buffer->lsi < next_lsi_node->lsi && buffer->lsi > current->lsi)
		next_lsi_node = buffer;
	return (next_lsi_node);
}

void	reset_lis(t_int_list *a)
{
	t_int_list	*buffer;
	int			len;
	t_int_list	*end;

	end = a->previous;
	len = list_len(&a, &end);
	buffer = a;
	while (len--)
	{
		buffer->lsi = 1;
		buffer = buffer->next;
	}
	
}

void	set_lsi(t_int_list *a)
{
	t_int_list	*current;
	t_int_list	*end;
	t_int_list	*start;
	t_int_list	*max_lsi;

	start = get_maximum(a);
	current = start->next;
	while (current != start)
	{
		calculate_lsi(start, current);
		current = current->next;
	}
	current = start->next;
	current = get_maximum(start);
	max_lsi = get_max_lsi(current);
	while (max_lsi)
	{
		max_lsi->lsi = -1;
		max_lsi = max_lsi->lsi_previous;
	}
}
