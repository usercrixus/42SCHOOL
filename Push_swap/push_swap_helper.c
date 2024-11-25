/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:46 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 00:15:21 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;
	int			i;

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
	t_int_list *end;
	t_int_list *buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c < x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c <= x)
		return (0);
	return (1);	
}

int is_max(t_int_list *a, int x)
{
	t_int_list *end;
	t_int_list *buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c > x)
			return (0);
		buffer = buffer->next;
	}
	if (buffer->c >= x)
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
