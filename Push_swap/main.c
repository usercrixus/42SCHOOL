/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/23 04:26:02 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int maxstep = 2;
int trigger = 0;

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
	if (buffer->c <= x)
		return (0);
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
	if (buffer->c >= x)
		return (0);
	return (1);	
}

int	is_well_placed(t_int_list *a, int x)
{
	int new_minimum = is_min(a, x);
	int new_maximum = is_max(a, x);

	int is_classic_situation = x > a->c && x < a->previous->c && !(is_min(a, a->previous->c) && is_max(a, a->c)) && list_len(&a, &a->previous) > 2;
	int exeption4 = list_len(&a, &a->previous) == 2 && x > a->c && x < a->previous->c;
	int exeption1 = new_minimum && is_max(a, a->c);
	int exeption2 = new_maximum && is_max(a, a->c);
	int exeption3 = new_maximum && is_min(a, a->c) && is_max(a, a->previous->c);
	int exeption5 = list_len(&a, &a->previous) == 1;
	if (trigger)
		return is_classic_situation || exeption1 || exeption2 || exeption3 || exeption4 || exeption5;	
	is_classic_situation = x < a->c && x > a->previous->c && !(is_min(a, a->c) && is_max(a, a->previous->c)) && list_len(&a, &a->previous) > 2;
	exeption4 = list_len(&a, &a->previous) == 2 && x < a->c && x > a->previous->c;
	exeption1 = new_minimum && is_min(a, a->c);
	exeption2 = new_maximum && is_min(a, a->c);
	exeption3 = new_maximum && is_max(a, a->c) && is_min(a, a->previous->c);
	exeption5 = list_len(&a, &a->previous) == 1;
	return is_classic_situation || exeption1 || exeption2 || exeption3 || exeption4 || exeption5;
}
int calculate_step(int a, int b)
{
	if (a < 0 && b < 0)
		return (ft_abs(ft_min(a, b)));
	else if (a < 0 && b > 0)
		return (ft_abs(a) + b);
	else if (a > 0 && b < 0)
		return (ft_abs(b) + a);
	else
		return (ft_max(a, b));
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
	len = len / 2 + 1;
	i = 0;
	while (len)
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
	return (0);
}

struct s_way	get_best_branch(t_int_list **b, t_int_list **a)
{
	int			i;
	int			len;
	t_int_list	*buffer_right;
	t_int_list	*buffer_left;
	int			best_way_buffer;
	struct s_way	best_way;
	

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
		if (calculate_step(best_way.way, best_way.branch) > maxstep)
		{
			best_way.branch = 0;
			best_way.way = 0;
			return best_way;
		}
		if (i > calculate_step(best_way.way, best_way.branch))
			return (best_way);
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
	best_way.step = calculate_step(best_way.way, best_way.branch);
	return (best_way);
}

int	manage_rotate(t_int_list **a, t_int_list **b, struct s_way best_way)
{
	while (best_way.branch < 0 && best_way.way < 0)
	{
		rrr(b, a);
		best_way.branch++;
		best_way.way++;
	}
	while (best_way.branch > 0 && best_way.way > 0)
	{
		rr(b, a);
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
}

int	sort(t_int_list **b, t_int_list **a, int max)
{
	int	len;
	int i;
	struct s_way	best_way;	

	len = list_len(a, &(*a)->previous);
	printf("%d\n", len);
	swap(b, a, 1);

	while (len-- > 2)
	{
		best_way = get_best_branch(a, b);
		manage_rotate(b, a, best_way);
		swap(b, a, 1);
	}
	maxstep = max;
	trigger = 1;
	while (*b)
	{
		best_way = get_best_branch(b, a);
		manage_rotate(a, b, best_way);
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
	sort(&b, &a, argc - 2);
	print_list(a);
	return (0);
}
