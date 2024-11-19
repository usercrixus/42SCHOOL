/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/11/19 20:57:33 by achaisne         ###   ########.fr       */
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
	ft_putendl_fd("rr", 1);
}