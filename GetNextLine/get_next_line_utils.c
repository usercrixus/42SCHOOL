/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:41 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/14 04:39:48 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	push_str_node(t_string *str)
{
	t_char_list	*node;

	node = (t_char_list *)malloc(sizeof(t_char_list) * 1);
	if (!node)
		return (0);
	node->next = 0;
	if (str->head == 0)
	{
		str->head = node;
		str->tail = node;
	}
	else
	{
		str->tail->next = node;
		str->tail = node;
	}
	return (1);
}

int	push_str(t_string *str, char *c, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if ((str->size + i) % T_STRING_BUFFER_SIZE == 0)
			if (!push_str_node(str))
				return (0);
		(str->tail->c)[(str->size + i) % T_STRING_BUFFER_SIZE] = c[i];
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
	return (str);
}

char	*create_native_string(t_string *str)
{
	char				*line;
	t_char_list			*buffer;
	unsigned long long	i;

	line = (char *)malloc(sizeof(char) * (str->size + 1));
	if (!line)
		return (0);
	buffer = str->head;
	i = 0;
	while (i < str->size)
	{
		line[i] = (buffer->c)[i % T_STRING_BUFFER_SIZE];
		i++;
		if (i % T_STRING_BUFFER_SIZE == 0)
			buffer = buffer->next;
	}
	line[i] = '\0';
	return (line);
}
