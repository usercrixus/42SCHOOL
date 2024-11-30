/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_manage_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:00:51 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/30 18:15:39 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manage_rotate(t_int_list **a, t_int_list **b, t_way best_way)
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
	while (best_way.branch < 0 && best_way.branch++)
		rrotate(b, 'b');
	while (best_way.branch > 0 && best_way.branch--)
		rotate(b, 'b');
	while (best_way.way < 0 && best_way.way++)
		rrotate(a, 'a');
	while (best_way.way > 0 && best_way.way--)
		rotate(a, 'a');
}
