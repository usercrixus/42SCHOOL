/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:46 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/29 18:39:45 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;
	t_int_list	*buffer_end;

	buffer = *start;
	while (!is_max(buffer, buffer->c))
	{
		buffer = buffer->next;
	}
	buffer_end = buffer->previous;
	if (buffer && buffer->next == buffer_end)
		return (1);
	while (buffer->next != buffer_end && buffer->c >= buffer->next->c)
	{
		buffer = buffer->next;
	}
	if (buffer->next == buffer_end)
		return (1);
	return (0);
}

int	list_len(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;
	int			i;

	if (!(*start))
		return (0);
	i = 1;
	buffer = *start;
	while (buffer != *end)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

int	is_min(t_int_list *a, int x)
{
	t_int_list	*end;
	t_int_list	*buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c < x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c < x)
		return (0);
	return (1);
}

int	is_max(t_int_list *a, int x)
{
	t_int_list	*end;
	t_int_list	*buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c > x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c > x)
		return (0);
	return (1);
}

void	print_list(t_int_list *a)
{
	t_int_list	*buffer;
	t_int_list	end;

	if (!a)
		return ;
	buffer = a;
	printf("%d ", buffer->c);
	buffer = buffer->next;
	while (buffer != a)
	{
		printf("%d ", buffer->c);
		buffer = buffer->next;
	}
	printf("\n");
}
