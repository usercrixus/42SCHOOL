/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/12 05:33:13 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static enum e_sstatus	str_strt(
	char *buffer, t_string *s, ssize_t byte_read, ssize_t *offset)
{
	while (buffer[*offset] != '\n' && *offset < byte_read)
	{
		if (!push_char(s, buffer[*offset]))
		{
			free_string(s);
			return (FAILED);
		}
		(*offset)++;
	}
	if (buffer[*offset] == '\n' && *offset < byte_read)
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

static enum e_sstatus	str_end(
	char *buffer, t_string *s, ssize_t byte_read, ssize_t *offset)
{
	*offset = 0;
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

static int	populate_t_string_line(int fd, t_string *str)
{
	enum e_sstatus		str_status;
	static char			buffer[BUFFER_SIZE];
	static ssize_t		byte_read;
	static ssize_t		offset;

	str_status = str_strt(buffer, str, byte_read, &offset);
	if (str_status == FAILED)
		return (0);
	else if (str_status == PENDING)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		while (byte_read > 0)
		{
			str_status = str_end(buffer, str, byte_read, &offset);
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
	if (!populate_t_string_line(fd, str))
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
