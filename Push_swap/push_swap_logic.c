#include "push_swap.h"


int is_sorted_a(t_int_list *stack)
{
	t_int_list	*buffer;

	buffer = stack;
	if (buffer && buffer->next == stack)
		return (1);
	while (buffer->next != stack && buffer->c <= buffer->next->c)
		buffer = buffer->next;
	if (buffer->next == stack)
		return (1);
	return (0);
}

enum e_action best_action_a(t_int_list *stack, int pivot)
{
	if (is_sorted_a(stack))
		return (none);
	if (stack->c < pivot)
		return (pb);
	if (stack && stack->next && stack->next != stack)
		if (stack->c > stack->next->c && stack->next->c != pivot)
			return (sa);
		else
			return (ra);
	return (none);
}


int is_sorted_b(t_int_list *stack)
{
	t_int_list	*buffer;

	buffer = stack;
	if (buffer && buffer->next == stack)
		return (1);
	buffer = buffer->next;
	while (buffer->next != stack && buffer->c >= buffer->next->c)
		buffer = buffer->next;
	if (buffer->next == stack)
		return (1);
	return (0);
}

enum e_action best_action_b(t_int_list *stack, int pivot)
{
	if (!stack)
		return (none);
	if (is_sorted_b(stack))
		return (pa);	
	if (stack && stack->next != stack)
		if (stack->c < stack->next->c && stack->next->c != pivot)
			return (sb);
		else
			return (rb);
	return (none);
}