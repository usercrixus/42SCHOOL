/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 05:14:36 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	populate_a(t_int_list **a, char **argv, int argc)
{
	int			i;
	int			number;
	t_int_list	*node;

	i = 0;
	number = atoi(argv[i]);
	node = create_node(number);
	insert(a, &node);
	i++;
	while (i < argc)
	{
		number = atoi(argv[i]);
		node = create_node(number);
		insert(a, &node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;
	int				*list;
	int				i;

	a = 0;
	b = 0;
	if (argc < 2)
		return (1);
	populate_a(&a, &argv[1], argc - 1);
	list = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		list[i] = atoi(argv[i + 1]);
		i++;
	}
	sort_int(list, argc - 1);
	normalize(&a, list, argc - 1);
	set_lsi(a);
	sort_brute_force(&b, &a, argc - 2);
	return (0);
}
