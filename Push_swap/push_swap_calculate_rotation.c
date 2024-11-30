/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calculate_rotation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:02:43 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 18:23:43 by achaisne         ###   ########.fr       */
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

int	get_steps(int a, int b)
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

void	set_best_way(t_int_list **a, t_int_list *n, int branch, t_way *best_way)
{
	t_way	way_buffer;

	way_buffer.branch = branch;
	way_buffer.way = get_best_way(a, n->c);
	if (get_steps(way_buffer.branch, way_buffer.way)
		< get_steps(best_way->branch, best_way->way))
	{
		best_way->branch = way_buffer.branch;
		best_way->way = way_buffer.way;
	}
}

t_way	get_best_branch(t_int_list **b, t_int_list **a)
{
	int			i;
	int			len;
	t_int_list	*buffer_right;
	t_int_list	*buffer_left;
	t_way		best_way;

	buffer_right = (*b);
	buffer_left = (*b);
	len = list_len(b, &(*b)->previous);
	i = 0;
	best_way.way = get_best_way(a, (*b)->c);
	best_way.branch = 0;
	while (len / 2)
	{
		set_best_way(a, buffer_right, i * -1, &best_way);
		set_best_way(a, buffer_left, i, &best_way);
		if (i > get_steps(best_way.way, best_way.branch))
			break ;
		buffer_left = buffer_left->previous;
		buffer_right = buffer_right->next;
		len--;
		i++;
	}
	return (best_way);
}
