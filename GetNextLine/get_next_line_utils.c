/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:41 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/11 03:01:12 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	push_char(t_string *str, char c)
{
	t_char_list	*node;
	t_char_list	*buffer;

	node = (t_char_list *)malloc(sizeof(t_char_list) * 1);
	if (!node)
		return (0);
	node->c = c;
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

int	get_str_len(t_string *str)
{
	int			len;
	t_char_list	*buffer;

	buffer = str->head;
	len = 0;
	while (buffer)
	{
		len++;
		buffer = buffer->next;
	}
	return (len);
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
}

char	*create_native_string(t_string *str)
{
	char		*line;
	t_char_list	*buffer;
	int			i;
	int			len;

	if (!str->head)
		return (0);
	len = get_str_len(str);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (0);
	buffer = str->head;
	i = 0;
	while (buffer)
	{
		line[i] = buffer->c;
		i++;
		buffer = buffer->next;
	}
	line[i] = '\0';
	return (line);
}