/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:41 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/23 20:13:06 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static int	push_str_node(t_string *str)
{
	t_char_list	*node;

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

int	push_str(t_string *str, char *c, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if ((str->size + str->start + i) % T_STRING_BUFFER_SIZE == 0)
			if (!push_str_node(str))
				return (0);
		(str->tail->c)[(str->size + str->start + i) % T_STRING_BUFFER_SIZE] = c[i];
		i++;
	}
	str->size += len;
	return (1);
}

void	free_string(t_string *str)
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

t_string	*create_string(void)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof(t_string) * 1);
	if (!str)
		return (0);
	str->head = 0;
	str->tail = 0;
	str->size = 0;
	str->start = 0;
	return (str);
}

void	set_start_str(t_string *str, long long size)
{
	int					new_start;
	struct s_char_list	*buffer;
	struct s_char_list	*buffer_free;

	str->size -= size;
	new_start = (str->start + size) / T_STRING_BUFFER_SIZE;
	buffer = str->head;
	while (new_start)
	{
		str->head = str->head->next;
		new_start--;
	}
	str->start = (str->start + size) % T_STRING_BUFFER_SIZE;
	while (buffer != str->head)
	{
		buffer_free = buffer;
		buffer = buffer->next;
		free(buffer_free);
	}
}

int	is_contain_line_feed(t_string *str)
{
	t_char_list			*buffer;
	unsigned long long	i;

	buffer = str->head;
	i = str->start;
	while (i < str->size)
	{
		if (i != 0 && i % T_STRING_BUFFER_SIZE == 0)
			buffer = buffer->next;
		if (buffer->c[i] == '\n')
			return (i - str->start + 1);
		i++;
	}
	return (0);
}

char	*create_native_string(t_string *str)
{
	char				*line;
	t_char_list			*buffer;
	unsigned long long	i;
	int					size;

	size = is_contain_line_feed(str);
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (0);
	buffer = str->head;
	i = str->start;
	while (i < size)
	{
		line[i] = (buffer->c)[i % T_STRING_BUFFER_SIZE];
		i++;
		if (i % T_STRING_BUFFER_SIZE == 0)
			buffer = buffer->next;
	}
	line[i] = '\0';
	set_start_str(str, size);
	return (line);
}
