/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:04:22 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 17:21:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_factorial(11));
	printf("%d\n", ft_recursive_factorial(12));
	printf("%d\n", ft_recursive_factorial(13));
	printf("%d\n", ft_recursive_factorial(14));
	printf("%d\n", ft_recursive_factorial(15));
	printf("%d\n", ft_recursive_factorial(16));
}
*/