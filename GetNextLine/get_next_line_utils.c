/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:41 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/13 23:56:33 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	push_char(t_string *str, char c)
{
	t_char_list	*node;

	if (str->size % T_STRING_BUFFER_SIZE == 0)
	{
		node = (t_char_list *)malloc(sizeof(t_char_list) * 1);
		if (!node)
			return (0);
		node->c = (char *)malloc(sizeof(char) * (T_STRING_BUFFER_SIZE));
		if (!node->c)
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
	}
	(str->tail->c)[str->size % (T_STRING_BUFFER_SIZE - 1)] = c;
	str->size++;
	return (1);
}

void	free_string(t_string *str)
{
	t_char_list	*buffer;

	while (str->head)
	{
		buffer = str->head;
		str->head = str->head->next;
		free(buffer->c);
		free(buffer);
	}
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
		line[i] = (buffer->c)[i % (T_STRING_BUFFER_SIZE - 1)];
		i++;
		if (i % T_STRING_BUFFER_SIZE == 0)
			buffer = buffer->next;
	}
	line[i] = '\0';
	return (line);
}
