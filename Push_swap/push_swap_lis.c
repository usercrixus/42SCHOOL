/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:19:06 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 03:59:52 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list *get_maximum(t_int_list *a)
{
	t_int_list	*buffer;

	buffer = a;
	while (!is_max(a, buffer->c))
	{
		buffer = buffer->next;
	}
	return (buffer);
}

t_int_list *get_max_lsi(t_int_list *start)
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

void calculate_lsi(t_int_list *start, t_int_list *current)
{
	t_int_list *buffer_previous;

	buffer_previous = current;
	while (buffer_previous != start)
	{
		buffer_previous = buffer_previous->previous;
		if (buffer_previous->c > current->c)
			if (1 + buffer_previous->lsi > current->lsi)
			{
				current->lsi = 1 + buffer_previous->lsi;
				current->lsi_previous = buffer_previous;
			}
	}
}

t_int_list *next_lsi_node(t_int_list *current, t_int_list *end)
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

void set_lsi(t_int_list *a)
{
	t_int_list *current;
	t_int_list *end;
	t_int_list	*start;

	start = get_maximum(a);
	current = start->next;
	while (current != start)
	{
		calculate_lsi(start, current);
		current = current->next;
	}
	current = start->next;

	current = get_maximum(start);
	t_int_list *max_lsi = get_max_lsi(current);
	while (max_lsi)
	{
		max_lsi->lsi = -1;
		max_lsi = max_lsi->lsi_previous;
	}
	
	// t_int_list *b = current;
	// end = b->previous;
	// while (b != end)
	// {
	// 	printf("%d ---- %d\n", b->c, b->lsi);
	// 	b = b->next;
	// }
	// exit(1);
}
