/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:16:52 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 00:18:04 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_int_list **stack)
{
	if (*stack)
		*stack = (*stack)->next;
	ft_putendl_fd("r", 1);
}

void	rrotate(t_int_list **stack)
{
	if (*stack)
		*stack = (*stack)->previous;
	ft_putendl_fd("rr", 1);
}

void	rr(t_int_list **stacka, t_int_list **stackb)
{
	if (*stacka)
		*stacka = (*stacka)->next;
	if (*stackb)
		*stackb = (*stackb)->next;
	ft_putendl_fd("rrr", 1);
}

void	rrr(t_int_list **stacka, t_int_list **stackb)
{
	if (*stacka)
		*stacka = (*stacka)->previous;
	if (*stackb)
		*stackb = (*stackb)->previous;
	ft_putendl_fd("rrrr", 1);
}

void	swap(t_int_list **stack_pushed, t_int_list **stack_poped, int verbose)
{
	t_int_list	*poped;

	poped = pop(stack_poped);
	push(stack_pushed, &poped);
	if (verbose)
		ft_putendl_fd("pa", 1);
}

void	swap_top(t_int_list **stack)
{
	t_int_list	*poped;
	t_int_list	*insert;

	poped = pop(stack);
	insert = (*stack)->next;
	push(&insert, &poped);
	ft_putendl_fd("sw", 1);
}