/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:58:45 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/10 23:04:43 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

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

char	*get_next_line(int fd);
int		push_char(t_string *str, char c);
int		get_str_len(t_string *str);
void	free_string(t_string *str);
char	*create_native_string(t_string *str);

#endif