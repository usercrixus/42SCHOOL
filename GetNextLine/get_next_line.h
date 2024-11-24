/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:45 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/24 21:38:00 by achaisne         ###   ########.fr       */
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

# define T_STR_BUFFER_SIZE 1024

typedef struct s_char_list
{
	char				c[T_STR_BUFFER_SIZE];
	struct s_char_list	*next;
}	t_char_list;

typedef struct s_str
{
	unsigned long long	size;
	int					start;
	t_char_list			*head;
	t_char_list			*tail;
}	t_str;

char				*get_next_line(int fd);
int					push_str(t_str *str, char *c, ssize_t len);
int					get_str_len(t_str *str);
//void				free_str(t_str *str);
char				*get_char_array(t_str *str, unsigned long long line_size);
t_str				*create_str(void);
unsigned long long	is_line_feed(t_str *str);
int					troncate_str_begin(t_str *str, unsigned long long size);

#endif