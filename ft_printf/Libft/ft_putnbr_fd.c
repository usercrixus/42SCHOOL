/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:23:04 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/11 04:45:47 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	int		printed_size;

	nbr = ft_itoa(n);
	if (!nbr)
		return (0);
	printed_size = ft_putstr_fd(nbr, fd);
	free(nbr);
	return printed_size;
}
