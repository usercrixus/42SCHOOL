/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/26 05:10:35 by achaisne         ###   ########.fr       */
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
	swap(a, &node, 0);
	i++;
	while (i < argc)
	{
		number = atoi(argv[i]);
		node = create_node(number);
		swap(a, &node, 0);
		i++;
	}
}

int	sort(t_int_list **b, t_int_list **a, int max)
{
	int	len;
	int i;
	struct s_way	best_way;	

	len = list_len(a, &(*a)->previous);
	while (len)
	{
		if ((*a)->lsi == -1)
			rotate(a);
		else if ((*a)->c >= max * 0.5 )
		{
			swap(b, a, 1);
		}
		else if ((*a)->c <= max * 0.5)
		{
			swap(b, a, 1);
			rotate(b);
		}
		len--;
	}
	while (*b)
	{
		best_way = get_best_branch(b, a);
		manage_rotate(a, b, best_way);
		swap(a, b, 1);
	}
	while (!is_max(*a, (*a)->c))
		rotate(a);
}


int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;
	int				max;
	int				*list;
	int				i;
	t_int_list		*end;

	a = 0;
	b = 0;
	if (argc < 2)
		return 1;
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
	end = a->previous;
	print_list(a);
	quick_sort(&a, &end, &b, &a);
	// set_lsi(a);
	// sort(&b, &a, argc - 2);
	print_list(a);
	return (0);
}
