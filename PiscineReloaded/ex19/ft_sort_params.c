/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:04:21 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/09 16:50:23 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sort(char **tab, int size)
{
	char	*buffer;
	int		trigger;
	int		i;

	trigger = 1;
	while (trigger)
	{
		trigger = 0;
		i = 0;
		while (i < size)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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

int	main(int argc, char **argv)
{
	int	i;

	sort(argv, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}	
}
