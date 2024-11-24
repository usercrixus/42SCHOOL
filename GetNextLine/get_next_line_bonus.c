/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/24 21:35:21 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_buffer_line_feed(char *str, ssize_t len)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_char_array(t_str *str, unsigned long long line_size)
{
	char				*line;
	t_char_list			*buffer;
	unsigned long long	i;

	if (line_size <= 0 || !str)
		return (0);
	line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (0);
	buffer = str->head;
	i = 0;
	while (i < line_size)
	{
		if (!buffer)
		{
			free(line);
			return (0);
		}
		line[i] = (buffer->c)[(i + str->start) % T_STR_BUFFER_SIZE];
		i++;
		if ((i + str->start) % T_STR_BUFFER_SIZE == 0)
			buffer = buffer->next;
	}
	line[i] = '\0';
	return (line);
}

static int	populate_line(t_str *s, int fd)
{
	char	*buffer;
	ssize_t	byte_readed;

	if (!s)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);
	byte_readed = read(fd, buffer, BUFFER_SIZE);
	while (byte_readed > 0)
	{
		if (!push_str(s, buffer, byte_readed))
		{
			free(buffer);
			return (0);
		}
		if (is_buffer_line_feed(buffer, byte_readed))
		{
			free(buffer);
			return (1);
		}
		byte_readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (-1);
}

static unsigned long long	get_line_size(t_str *str, int fd)
{
	int					read_status;
	unsigned long long	line_size;

	if (!str)
		return (0);
	line_size = is_line_feed(str);
	if (!line_size)
	{
		read_status = populate_line(str, fd);
		if (!read_status)
			return (0);
		if (read_status == 1)
			line_size = is_line_feed(str);
		else
			line_size = str->size;
	}
	return (line_size);
}

char	*get_next_line(int fd)
{
	static t_str		*str[1024];
	unsigned long long	line_size;
	char				*line;

	if (fd < 0 || fd > 1024)
		return (0);
	if (!str[fd])
		str[fd] = create_str();
	if (!str[fd])
		return (0);
	line_size = get_line_size(str[fd], fd);
	if (!line_size)
		return (0);
	line = get_char_array(str[fd], line_size);
	if (!line)
		return (0);
	troncate_str_begin(str[fd], line_size);
	return (line);
}
