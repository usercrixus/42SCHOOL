/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:46 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/19 05:05:19 by achaisne         ###   ########.fr       */
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
