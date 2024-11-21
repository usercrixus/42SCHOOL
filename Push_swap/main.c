/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/21 05:28:33 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include "../libft/libft.h"

int	abs(int x)
{
	if(x < 0)
		return x * -1;
	return (x);
}

int max(int x, int y)
{
	if(x > y)
		return (y);
	return (x);
}

int min(int x, int y)
{
	if(x < y)
		return (x);
	return (y);
}

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

int	is_min(t_int_list *a, int x)
{
	t_int_list *end;
	t_int_list *buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c < x)
			return (0);
		buffer = buffer->next;
	}
	return (1);	
}

int is_max(t_int_list *a, int x)
{
	t_int_list *end;
	t_int_list *buffer;

	end = a->previous;
	buffer = a;
	while (buffer != end)
	{
		if (buffer->c > x)
			return (0);
		buffer = buffer->next;
	}
	return (1);	
}

int	is_well_placed(t_int_list *a, int x)
{
	// printf("HERE %d : \n", x);
	// printf("%d < %d && %d > %d) || (%d < %d && %d)\n", a->c, x, a->previous->c, x, a->c, x, is_min(a, a->previous->c));
	// print_list(a);
	int is_forbidden = is_max(a, a->previous->c) && is_min(a, a->c) && a->c < x && a->previous->c > x && list_len(&a, &a->previous) > 2;
	int is_classic_situation = a->c < x && a->previous->c > x;
	int is_previous_is_min = a->c < x && is_min(a, a->previous->c);
	int len_2 = list_len(&a, &a->previous) == 2 && is_max(a, x);
	int is_not_new_max = is_min(a, a->previous->c) && !is_max(a, x);

	return  (is_classic_situation);
}
int calculate_step(int a, int b)
{
	if (a < 0 && b < 0)
		return (abs(min(a, b)));
	else if (a < 0 && b > 0)
		return (abs(a) + b);
	else if (a > 0 && b < 0)
		return (abs(b) + a);
	else
		return (max(a, b));
}

int	get_best_way(t_int_list **a, int x)
{
	int			i;
	int			len;
	t_int_list	*buffer_right;
	t_int_list	*buffer_left;

	buffer_right = (*a);
	buffer_left = (*a);
	len = list_len(a, &(*a)->previous);
	i = 0;
	while (len / 2)
	{
		if (is_well_placed(buffer_right, x))
			return (i);
		else if (is_well_placed(buffer_left, x))
			return (i * -1);
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
	// print_list(*a);
	// printf("way : %d\n",i);
	// exit(0);
	return (0);
}

struct way	get_best_branch(t_int_list **b, t_int_list **a)
{
	int			i;
	int			len;
	t_int_list	*buffer_right;
	t_int_list	*buffer_left;
	int			best_way_buffer;
	struct way	best_way;
	

	buffer_right = (*b);
	buffer_left = (*b);
	len = list_len(b, &(*b)->previous);
	i = 0;
	best_way.way = get_best_way(a, (*b)->c);
	best_way.branch = 0;
	while (len / 2)
	{
		best_way_buffer = get_best_way(a, buffer_right->c);
		if (calculate_step(best_way.way, best_way.branch) > calculate_step(best_way_buffer, i))
		{
			best_way.way = best_way_buffer;
			best_way.branch = i;
		}
		best_way_buffer = get_best_way(a, buffer_left->c);
		if (calculate_step(best_way.way, best_way.branch) > calculate_step(best_way_buffer, i))
		{
			best_way.way = best_way_buffer;
			best_way.branch = i * -1;
		}
		if (i > calculate_step(best_way.way, best_way.branch))
			break ;
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
	best_way.step = calculate_step(best_way.way, best_way.branch);
	// print_list(*a);
	// printf("branch : %d way : %d\n", best_way.branch, best_way.way);
	// exit(0);
	return (best_way);
}

int	sort(t_int_list **b, t_int_list **a, int max)
{
	int	len;
	int i;
	struct way	best_way;	

	len = list_len(a, &(*a)->previous);
	printf("%d\n", len);
	while (len--)
	{
		if((*a)->c == 0)
			rotate(a);
		else
			swap(b, a, 1);
	}
	i = 1;
	while (i++ < max)
	{
		// print_list(*a);
		// print_list(*b);
		// exit(0);
		best_way = get_best_branch(b, a);
		// printf("branch %d way %d\n", best_way.branch, best_way.way);
		// break;
		while (best_way.branch < 0 && best_way.way < 0)
		{
			rrr(a, b);
			best_way.branch++;
			best_way.way++;
		}
		while (best_way.branch > 0 && best_way.way > 0)
		{
			rr(a, b);
			best_way.branch--;
			best_way.way--;
		}
		while (best_way.branch < 0 && best_way.branch)
		{
			best_way.branch++;
			rrotate(b);
		}
		while (best_way.branch > 0 && best_way.branch)
		{
			best_way.branch--;
			rotate(b);
		}
		while (best_way.way < 0 && best_way.way)
		{
			best_way.way++;
			rrotate(a);
		}
		while (best_way.way > 0 && best_way.way)
		{
			best_way.way--;
			rotate(a);
		}
		swap(a, b, 1);
	}
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
