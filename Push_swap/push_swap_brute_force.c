/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_brute_force.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:12:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 23:59:02 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_well_placed(t_int_list *a, int x)
{
	int	new_minimum;
	int	new_maximum;
	int	exeption;
	int	is_classic_situation;

	new_minimum = is_min(a, x);
	new_maximum = is_max(a, x);
	is_classic_situation = x > a->c && x < a->previous->c && !(is_min(a, a->previous->c) && is_max(a, a->c)) && list_len(&a, &a->previous) > 2;
	exeption = list_len(&a, &a->previous) == 2 && x > a->c && x < a->previous->c;
	exeption = exeption || (new_minimum && is_max(a, a->c));
	exeption = exeption || (new_maximum && is_max(a, a->c));
	exeption = exeption || (new_maximum && is_min(a, a->c) && is_max(a, a->previous->c));
	exeption = exeption || (list_len(&a, &a->previous) == 1);
	return (is_classic_situation || exeption);
}

int	calculate_step(int a, int b)
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
	int				i;
	int				len;
	t_int_list		*buffer_right;
	t_int_list		*buffer_left;
	int				best_way_buffer;
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
