/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/23 20:10:55 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>



static t_string	*manage_populate_line(t_string *str, int fd)
{
	char			buffer[BUFFER_SIZE];
	ssize_t			byte_readed;
	int				i;

	byte_readed = read(fd, buffer, BUFFER_SIZE);
	while (byte_readed > 0)
	{
		i = 0;
		while (i < byte_readed)
		{
			push_str(str, &buffer[i], 1);
			i++;
		}
		if (is_contain_line_feed(str))
			byte_readed = 0;
		else
			byte_readed = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	char				*line;
	static t_string		*str[1024];

	if (fd < 0 || fd >= 1024)
		return (0);
	if (!str[fd])
		str[fd] = create_string();
	if (!is_contain_line_feed(str[fd]))
		manage_populate_line(str[fd], fd);
	line = create_native_string(str[fd]);
	if (!line)
		return (0);
	return (line);
}
