/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:46 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/17 21:24:40 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;

	buffer = *start;
	if (buffer && buffer->next == *end)
		return (1);
	while (buffer->next != *end && buffer->c <= buffer->next->c)
		buffer = buffer->next;
	if (buffer->next == *end)
		return (1);
	return (0);
}

int	list_len(t_int_list **start, t_int_list **end)
{
	t_int_list	*buffer;
	int			i;

	i = 0;
	buffer = *start;
	while (buffer != *end)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
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
