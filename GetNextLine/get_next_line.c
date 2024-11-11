/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:26 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/11 19:24:57 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		c;
	t_string	str;

	str.head = 0;
	str.tail = 0;
	while ((read(fd, &c, 1) > 0) && c != '\n')
		if (!push_char(&str, c))
		{
			free_string(&str);
			return (0);
		}
	line = create_native_string(&str);
	if (!line)
	{
		free_string(&str);
		return (0);
	}
	free_string(&str);
	return (line);
}
