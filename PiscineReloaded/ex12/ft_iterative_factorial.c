/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:50:39 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 17:20:14 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	result = 1;
	i = 1;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_iterative_factorial(11));
	printf("%d\n", ft_iterative_factorial(12));
	printf("%d\n", ft_iterative_factorial(13));
	printf("%d\n", ft_iterative_factorial(14));
	printf("%d\n", ft_iterative_factorial(15));
	printf("%d\n", ft_iterative_factorial(16));
}
*/