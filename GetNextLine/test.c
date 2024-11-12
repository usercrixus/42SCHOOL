/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:17 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/12 04:26:30 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	int i = 150;
	while (line && i--)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);

/*
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Test 2");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");


	i = 0;
	int j = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (j < 15 && line)
	{
		while (line[i] != '\n')
		{
			printf("%c", line[i]);
			i++;
		}
		printf("\n");
		free(line);
		line = get_next_line(fd);
		j++;
	}
	close(fd);
*/
}
