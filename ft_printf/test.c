/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:22:28 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/11 04:14:36 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int *p = (int *)malloc(sizeof(int) * 1);
	int	x1;
	int	x2;

	x1 = ft_printf("%c %s %p %i %d %u %x %X %% end\n", 'c', "test2", p, -2147483647 - 1, -2147483647 - 1, (unsigned int)4294967295, -2147483647 - 1, 2147483647);
	x2 = printf("%c %s %p %i %d %u %x %X %% end\n", 'c', "test2", p, -2147483647 - 1, -2147483647 - 1, (unsigned int)4294967295, -2147483647 - 1, 2147483647);
	if (x1 != x2)
		printf("return error : %d %d", x1, x2);
	else
		printf("well done\n");
	return (0);
}