/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/19 21:03:35 by achaisne         ###   ########.fr       */
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

int power(int base, int exp) {
    int result = 1;
    while (exp--) {
        result *= base;
    }
    return result;
}

int convert_to_ternary(int number, int index) {
    if (index < 0)
        return 0;
    return (number / power(3, index)) % 3;
}

int	sort(t_int_list **b, t_int_list **a, int max)
{
	int	len;
	int	shift;
	int	bit_len;
	int	trigger;

	shift = 0;
	bit_len = 0;
	while (max){
		max /= 3;
		bit_len++;
	}
	bit_len = 5;
	while (bit_len > 0)
	{
		len = list_len(a, &((*a)->previous));
		trigger = 0;
		while (len)
		{
			int digit = convert_to_ternary((*a)->c, shift);
			if (digit == 0)
			{
				if (trigger)
				{
					rr(a, b);
					trigger = 0;
				}
				else
					rotate(a);
				
			}
			else if (digit == 1)
			{
				if (trigger)
				{
					rotate(b);
					trigger = 0;
				}
				swap(b, a, 1);
			}
			else if (digit == 2)
			{
				if (trigger)
					rotate(b);
				swap(b, a, 1);
				trigger = 1;
			}
			len--;
		}
		if (trigger)
			rotate(b);
		while (*b)
			swap(a, b, 1);

		shift++;
		bit_len--;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_int_list		*a;
	t_int_list		*b;
	int				max;
	int				*list;
	int				i;

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
	sort(&b, &a, argc - 1);
	print_list(a);
	return (0);
}
