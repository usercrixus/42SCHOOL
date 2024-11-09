/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:17:36 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/08 18:09:23 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tab_size(const char *s, char c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

char	*get_string(const char *s, int start, int end)
{
	char	*buffer;
	int		k;

	buffer = (char *)malloc(sizeof(char) * (end - start + 1));
	k = 0;
	while (k < end - start)
	{
		buffer[k] = s[k + start];
		k++;
	}
	buffer[k] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;
	int		end;

	result = (char **)malloc(sizeof(char *) * (tab_size(s, c) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (start != end)
			result[j++] = get_string(s, start, end);
	}
	result[j] = 0;
	return (result);
}
