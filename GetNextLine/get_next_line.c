/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/12 15:46:49 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static enum e_sstatus	populate_line(
	char *buffer, t_string *s, ssize_t byte_read, ssize_t *offset)
{
	while (*offset < byte_read && buffer[*offset] != '\n')
	{
		if (!push_char(s, buffer[*offset]))
		{
			free_string(s);
			return (FAILED);
		}
		(*offset)++;
	}
	if (*offset < byte_read && buffer[*offset] == '\n')
	{
		if (!push_char(s, buffer[*offset]))
		{
			free_string(s);
			return (FAILED);
		}
		(*offset)++;
		return (TERMINATED);
	}
	return (PENDING);
}

static int	manage_populate_line(int fd, t_string *str)
{
	enum e_sstatus		str_status;
	static char			buffer[BUFFER_SIZE];
	static ssize_t		byte_read;
	static ssize_t		offset;

	str_status = populate_line(buffer, str, byte_read, &offset);
	if (str_status == FAILED)
		return (0);
	else if (str_status == PENDING)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		while (byte_read > 0)
		{
			offset = 0;
			str_status = populate_line(buffer, str, byte_read, &offset);
			if (str_status == FAILED)
				return (0);
			else if (str_status == TERMINATED)
				break ;
			byte_read = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char				*line;
	t_string			*str;

	str = create_string();
	if (!str)
		return (0);
	if (!manage_populate_line(fd, str))
	{
		free(str);
		return (0);
	}
	if (!str->head)
	{
		free(str);
		return (0);
	}
	line = create_native_string(str);
	free_string(str);
	free(str);
	if (!line)
		return (0);
	return (line);
}
