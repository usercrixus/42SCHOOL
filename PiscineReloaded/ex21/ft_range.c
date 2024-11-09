/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:38:27 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 15:54:14 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (0);
	result = (int *)malloc(sizeof(int) * (max - min));
	if (!result)
		return (0);
	i = 0;
	while (min + i < max)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
int main()
{
	int *tab = ft_range(3, 10);
	int	i;

	i = 0;
	while (i < 10 - 3)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/