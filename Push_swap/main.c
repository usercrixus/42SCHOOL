/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/17 21:33:12 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include "../libft/libft.h"

void	populate_a(t_int_list **a, char **argv, int argc)
{
	int			i;
	int			number;
	t_int_list	*node;

	i = 1;
	number = atoi(argv[i]);
	node = create_node(number);
	manage_push(a, &node);
	i++;
	while (i < argc)
	{
		number = atoi(argv[i]);
		node = create_node(number);
		manage_push(a, &node);
		i++;
	}
}

int	sort(t_int_list **start, t_int_list **end, t_int_list **b, t_int_list **a)
{
	t_int_list		*pivot_node;
	struct s_minmax	minmax;
	int				pivot;

	minmax = get_min_max(start, end);
	pivot = (minmax.max + minmax.min) / 2;
	if (minmax.max == minmax.min)
		return (0);
	partition(start, end, b, a, pivot);
	pivot_node = *a;
	while (*b)
		manage_push(a, b);
	*start = *a;
	if (is_sorted_a(start, end))
		return (0);
	sort(&pivot_node, end, b, a);
	sort(start, &pivot_node, b, a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;
	t_int_list		*start;
	t_int_list		*end;
	struct s_minmax	minmax;
	int				pivot;

	a = 0;
	b = 0;
	start = 0;
	end = 0;
	if (argc < 2)
		return 1;
	populate_a(&a, argv, argc);
	end = a->previous;
	start = a;
	minmax = get_min_max(&start, &end);
	sort(&start, &end, &b, &a);
	ft_putstr_fd("Sorted list: ", 1);
	print_list(a);
	return (0);
}
