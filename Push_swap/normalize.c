/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:50:12 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/22 00:06:46 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sort_int(int *tab, int size)
{
	int		buffer;
	int		trigger;
	int		i;

	trigger = 1;
	while (trigger)
	{
		trigger = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				buffer = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = buffer;
				trigger = 1;
			}
			i++;
		}
	}
}

void	normalize(t_int_list **a, int *tab, int size)
{
	int	i;
	t_int_list *buffer;
	t_int_list *end;
	i = 0;

	end = (*a)->previous;
	while (i < size)
	{
		buffer = *a;
		while (buffer != end)
		{
			if (buffer->c == tab[i])
				break;;
			buffer = buffer->next;
		}
		if (buffer->c == tab[i])
			buffer->c = i;
		i++;
	}
}