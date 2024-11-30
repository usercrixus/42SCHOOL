/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_brute_force.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:12:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 05:18:01 by achaisne         ###   ########.fr       */
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
	is_classic_situation = x < a->c && x > a->next->c;
	exeption = new_minimum && is_min(a, a->c);
	exeption = exeption || (new_maximum && is_max(a, a->next->c));
	exeption = exeption || (list_len(&a, &a->previous) == 1);
	return (is_classic_situation || exeption);
}

int	calculate_step(int a, int b)
{
	if (a <= 0 && b <= 0)
		return (ft_abs(ft_min(a, b)));
	else if (a <= 0 && b >= 0)
		return (ft_abs(a) + b);
	else if (a >= 0 && b <= 0)
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
	len = list_len(a, &(*a)->previous) / 2 + 1;
	i = 0;
	while (i < len)
	{
		if (is_well_placed(buffer_right, x))
			return (i * -1);
		else if (is_well_placed(buffer_left, x))
			return (i);
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
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
		if (calculate_step(best_way.way, best_way.branch) > calculate_step(best_way_buffer, i * -1))
		{
			best_way.way = best_way_buffer;
			best_way.branch = i * -1;
		}
		best_way_buffer = get_best_way(a, buffer_left->c);
		if (calculate_step(best_way.way, best_way.branch) > calculate_step(best_way_buffer, i))
		{
			best_way.way = best_way_buffer;
			best_way.branch = i;
		}
		if (i > calculate_step(best_way.way, best_way.branch))
			break ;
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
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
	while (best_way.branch < 0)
	{
		best_way.branch++;
		rrotate(b, 'b');
	}
	while (best_way.branch > 0)
	{
		best_way.branch--;
		rotate(b, 'b');
	}
	while (best_way.way < 0)
	{
		best_way.way++;
		rrotate(a, 'a');
	}
	while (best_way.way > 0)
	{
		best_way.way--;
		rotate(a, 'a');
	}
}

int	final_roration(t_int_list **a, int max)
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
		if (buffer_right->c == max)
			return (i * -1);
		else if (buffer_left->c == max)
			return (i * 1);
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
	return (0);
}

int	sort_brute_force(t_int_list **b, t_int_list **a, int max)
{
	int				len;
	int				i;
	struct s_way	best_way;	
	t_int_list		**prev;
	t_int_list		**prev2;

	len = list_len(a, &(*a)->previous);
	while (len)
	{
		if ((*a)->previous->lsi == -1)
			rotate(a, 'a');
		else if ((*a)->previous->c >= max * 0.5)
		{
			push(b, a, 'b', 1);
		}
		else if ((*a)->previous->c <= max * 0.5)
		{
			push(b, a, 'b', 1);
			rotate(b, 'b');
		}
		len--;
	}
	while (*b)
	{
		best_way = get_best_branch(&(*b)->previous, &(*a)->previous);
		manage_rotate(a, b, best_way);
		push(a, b, 'a', 1);
	}
	best_way.branch = 0;
	best_way.way = final_roration(a, max);
	manage_rotate(a, b, best_way);
}
