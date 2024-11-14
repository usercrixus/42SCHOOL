/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:45 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/14 05:38:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define T_STRING_BUFFER_SIZE 1024

typedef struct s_char_list
{
	char				c[8 * T_STRING_BUFFER_SIZE];
	struct s_char_list	*next;
}	t_char_list;

typedef struct s_string
{
	unsigned long long	size;
	t_char_list			*head;
	t_char_list			*tail;
}	t_string;

typedef struct s_fd
{
	char	buffer[8 * BUFFER_SIZE];
	ssize_t	byte_read;
	ssize_t	offset;
}	t_fd;

enum e_sstatus
{
	FAILED,
	TERMINATED,
	PENDING
};

char		*get_next_line(int fd);
int			push_str(t_string *str, char *c, ssize_t len);
int			get_str_len(t_string *str);
void		free_string(t_string *str);
char		*create_native_string(t_string *str);
t_string	*create_string(void);

#endif