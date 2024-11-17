/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/17 21:27:47 by achaisne         ###   ########.fr       */
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

void	manage_push(t_int_list **stack_pushed, t_int_list **stack_poped)
{
	t_int_list	*poped;

	poped = pop(stack_poped);
	push(stack_pushed, &poped);
	ft_putendl_fd("pa", 1);
}

void	swap(t_int_list **stack)
{
	t_int_list	*poped;
	t_int_list	*insert;

	poped = pop(stack);
	insert = (*stack)->next;
	push(&insert, &poped);
	ft_putendl_fd("sw", 1);
}

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

int	is_sorted(t_int_list *a, t_int_list *b)
{
	while (a && a->next)
		if (a->c < a->next->c)
			a = a->next;
	if (!a->next)
		return (1);
	return (0);
}
