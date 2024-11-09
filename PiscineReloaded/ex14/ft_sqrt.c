/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:19:58 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 15:32:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < nb / i)
	{
		i++;
	}
	if (i == nb / i && nb % i == 0)
		return (i);
	return (0);
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(8));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(19));
	printf("%d\n", ft_sqrt(25));
}
*/