/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/25 23:48:26 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*create_node(int c)
{
	t_int_list	*node;

	node = (t_int_list *)malloc(sizeof(t_int_list) * 1);
	node->next = node;
	node->previous = node;
	node->c = c;
	node->lsi = 1;
	node->lsi_previous = 0;
	return (node);
}

t_int_list	*pop(t_int_list **stack)
{
	t_int_list	*poped;

	if (!*stack)
		return (0);
	poped = (*stack);
	if ((*stack)->next == *stack)
	{
		*stack = 0;
		return (poped);
	}
	(*stack)->previous->next = (*stack)->next;
	(*stack)->next->previous = (*stack)->previous;
	(*stack) = (*stack)->next;
	poped->next = poped;
	poped->previous = poped;
	return (poped);
}

void	push(t_int_list **stack_pushed, t_int_list **node)
{
	if (!*stack_pushed)
	{
		*stack_pushed = *node;
		(*stack_pushed)->next = *stack_pushed;
		(*stack_pushed)->previous = *stack_pushed;
	}
	else
	{
		(*node)->next = *stack_pushed;
		(*node)->previous = (*stack_pushed)->previous;
		(*stack_pushed)->previous->next = *node;
		(*stack_pushed)->previous = *node;
		*stack_pushed = *node;
	}
}
