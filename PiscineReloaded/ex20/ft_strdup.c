/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:26:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 15:29:12 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src)) + 1);
	if (!cpy)
		return (0);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

/*
#include <stdio.h>
int	main()
{
	printf("%s", ft_strdup("Hello all"));
}
*/