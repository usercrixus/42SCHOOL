/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:41 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/24 21:37:56 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	push_str_node(t_str *str)
{
	t_char_list	*node;

	if (!str)
		return (0);
	node = (t_char_list *)malloc(sizeof(t_char_list) * 1);
	if (!node)
		return (0);
	node->next = 0;
	if (str->head == 0)
		str->head = node;
	else
		str->tail->next = node;
	str->tail = node;
	return (1);
}

int	push_str(t_str *str, char *c, ssize_t len)
{
	ssize_t	i;

	if (!str || !c)
		return (0);
	i = 0;
	while (i < len)
	{
		if ((str->size + str->start + i) % T_STR_BUFFER_SIZE == 0)
			if (!push_str_node(str))
				return (0);
		(str->tail->c)[(str->size + str->start + i) % T_STR_BUFFER_SIZE] = c[i];
		i++;
	}
	str->size += len;
	return (1);
}

/*
void	free_str(t_str *str)
{
	t_char_list	*buffer;

	while (str->head)
	{
		buffer = str->head;
		str->head = str->head->next;
		free(buffer);
	}
	free(str);
}
*/

unsigned long long	is_line_feed(t_str *str)
{
	unsigned long long	i;
	t_char_list			*buffer;

	if (!str || !str->head)
		return (0);
	buffer = str->head;
	i = str->start;
	while (i < str->size + str->start)
	{
		if (i != 0 && i % T_STR_BUFFER_SIZE == 0)
		{
			buffer = buffer->next;
			if (!buffer)
				return (0);
		}
		if (buffer->c[i % T_STR_BUFFER_SIZE] == '\n')
			return (i - str->start + 1);
		i++;
	}
	return (0);
}

t_str	*create_str(void)
{
	t_str	*str;

	str = (t_str *)malloc(sizeof(t_str) * 1);
	if (!str)
		return (0);
	str->head = 0;
	str->tail = 0;
	str->size = 0;
	str->start = 0;
	return (str);
}

int	troncate_str_begin(t_str *str, unsigned long long size)
{
	t_char_list	*buffer;

	if (!str)
		return (0);
	if (size >= str->size)
		size = str->size;
	str->size -= size;
	str->start += size;
	while (str->start >= T_STR_BUFFER_SIZE)
	{
		if (!str->head || ! str->head->next)
			return (0);
		buffer = str->head;
		str->head = str->head->next;
		free(buffer);
		str->start -= T_STR_BUFFER_SIZE;
	}
	return (1);
}
