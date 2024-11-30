/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/29 20:08:41 by achaisne         ###   ########.fr       */
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
	poped = (*stack)->previous;
	if (poped == *stack)
	{
		*stack = 0;
		return (poped);
	}
	(*stack)->previous->previous->next = *stack;
	(*stack)->previous = (*stack)->previous->previous;
	poped->next = poped;
	poped->previous = poped;
	return (poped);
}

void	native_push(t_int_list **stack, t_int_list **node)
{
	if (!*stack)
	{
		*stack = *node;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
	}
	else
	{
		(*node)->next = *stack;
		(*node)->previous = (*stack)->previous;
		(*stack)->previous->next = *node;
		(*stack)->previous = *node;
	}
}

void	insert(t_int_list **stack, t_int_list **node)
{
	if (!*stack)
	{
		*stack = *node;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
	}
	else
	{
		(*node)->next = *stack;
		(*node)->previous = (*stack)->previous;
		(*stack)->previous->next = *node;
		(*stack)->previous = *node;
		*stack = *node;
	}
}
