/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:45 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/12 05:12:10 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_char_list
{
	char				c;
	struct s_char_list	*next;
}	t_char_list;

typedef struct s_string
{
	t_char_list	*head;
	t_char_list	*tail;
}	t_string;

enum e_sstatus
{
	FAILED,
	TERMINATED,
	PENDING
};

char		*get_next_line(int fd);
int			push_char(t_string *str, char c);
int			get_str_len(t_string *str);
void		free_string(t_string *str);
char		*create_native_string(t_string *str);
t_string	*create_string(void);

#endif