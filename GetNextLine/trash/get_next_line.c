/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/14 04:55:34 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static enum e_sstatus	populate_line(t_fd *fd, t_string *s)
{
	ssize_t	start;

	start = fd->offset;
	while (fd->offset < fd->byte_read && (fd->buffer)[fd->offset] != '\n')
		(fd->offset)++;
	if (!push_str(s, &(fd->buffer)[start], fd->offset - start))
		return (FAILED);
	if (fd->offset < fd->byte_read && (fd->buffer)[fd->offset] == '\n')
	{
		if (!push_str(s, &(fd->buffer)[fd->offset], 1))
			return (FAILED);
		(fd->offset)++;
		return (TERMINATED);
	}
	return (PENDING);
}

static int	manage_populate_line(int fd, t_string *str)
{
	enum e_sstatus	str_status;
	static t_fd		file_d[1024];

	str_status = populate_line(&file_d[fd], str);
	if (str_status == FAILED)
		return (0);
	else if (str_status == PENDING)
	{
		file_d[fd].byte_read = read(fd, file_d[fd].buffer, BUFFER_SIZE);
		while (str_status == PENDING && file_d[fd].byte_read > 0)
		{
			file_d[fd].offset = 0;
			str_status = populate_line(&file_d[fd], str);
			if (str_status == FAILED)
				return (0);
			else if (str_status == PENDING)
				file_d[fd].byte_read = read(fd, file_d[fd].buffer, BUFFER_SIZE);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char				*line;
	t_string			*str;

	if (fd < 0 || fd >= 1024)
		return (0);
	str = create_string();
	if (!str)
		return (0);
	if (!manage_populate_line(fd, str) || !str->head)
	{
		free_string(str);
		return (0);
	}
	line = create_native_string(str);
	free_string(str);
	if (!line)
		return (0);
	return (line);
}
