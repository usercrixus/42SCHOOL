/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:07:23 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/08 20:59:05 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*block;
	int		size;

	size = element_size * element_count;
	block = malloc(size);
	if (!block)
		return (0);
	ft_bzero(block, size);
	return (block);
}
