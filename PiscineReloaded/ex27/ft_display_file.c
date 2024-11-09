/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:40:40 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 18:15:37 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd);
		i++;
	}
}

int	print_file(char *file_name)
{
	int		fd;
	ssize_t	byte;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.", 2);
		ft_putchar('\n', 2);
		return (1);
	}
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		ft_putchar(c, 1);
		byte = read(fd, &c, 1);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc > 2)
		{
			ft_putstr("Too many arguments.", 2);
			ft_putchar('\n', 2);
		}
		if (argc < 2)
		{
			ft_putstr("File name missing.", 2);
			ft_putchar('\n', 2);
		}
		return (1);
	}
	print_file(argv[1]);
}
