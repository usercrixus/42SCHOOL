#include "push_swap.h"

#include <stdio.h>
#include "../libft/libft.h"

void print_list(t_int_list *a)
{
	t_int_list *buffer;

	if (!a)
		return;
	buffer = a;
	printf("%d ", buffer->c);
	buffer = buffer->next;
	while(buffer != a)
	{
		printf("%d ", buffer->c);
		buffer = buffer->next;
	}
	printf("\n");
}

struct minmax populate_a(t_int_list **a, char **argv, int argc)
{
	int i;
	int number;
	struct minmax minmax;

	i = 1;
	number = atoi(argv[i]);
	t_int_list *node = create_node(number);
	manage_push(a, &node);
	minmax.min = number;
	minmax.max = number;
	i++;
	while (i < argc)
	{
		number = atoi(argv[i]);
		if (number > minmax.max)
			minmax.max = number;
		if (number < minmax.min)
			minmax.min = number;
		t_int_list *node = create_node(number);
		manage_push(a, &node);
		i++;
	}

	return minmax;
}

struct pivots calculate_pivots(int argc, char **argv, struct minmax minmax)
{
	int i;
	int number;
	struct pivots pivots;

	i = 1;
	pivots.pivot_high = minmax.max;
	pivots.pivot_low = minmax.min;
	while(i < argc)
	{
		number = atoi(argv[i]);
		if (number > (minmax.max + minmax.min) / 2 && number < pivots.pivot_high)
			pivots.pivot_high = number;
		if (number < (minmax.max + minmax.min) / 2 && number > pivots.pivot_low)
			pivots.pivot_low = number;
		i++;
	}
	return (pivots);
}

int max (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main(int argc, char **argv)
{
	t_int_list *a;
	t_int_list *b;
	enum e_action action_a;
	enum e_action action_b;
	struct minmax minmax;
	struct pivots pivots;
	int buffer_low_pivot;

	a = 0;
	b = 0;

	if (argc < 2)
		return (1);
	minmax = populate_a(&a, argv, argc);
	pivots = calculate_pivots(argc, argv, minmax);
	buffer_low_pivot = minmax.min;
	int trigger = 0;
	long len =1000000;
	while (len--)
	{
		action_a = best_action_a(a, pivots.pivot_high);
		action_b = best_action_b(b, buffer_low_pivot);

		if ((action_a == none && action_b == pa) || trigger)
		{
			trigger = 1;
			manage_push(&a, &b);
			printf("pa\n");
			if(!b)
			{
				print_list(a);
				return (0);
			}
		}
		else if (action_a == pb){
			manage_push(&b, &a);
			buffer_low_pivot = max(pivots.pivot_low, b->c);
			printf("pb\n");
		}
		else if (action_a == sa && action_b == sb)
		{
			swap(&a);
			swap(&b);
			printf("ss\n");
		}
		else if (action_a == ra && action_b == rb)
		{
			rotate(&a);
			rotate(&b);
			printf("rr\n");
		}
		else if (action_a == rra && action_b == rrb)
		{
			rrotate(&a);
			rrotate(&b);
			printf("rr\n");
		}
		else {
			if (action_a == sa)
			{
				swap(&a);
				printf("sa\n");
			}
			else if (action_b == sb)
			{
				swap(&b);
				printf("sb\n");
			}
			else if (action_a == ra)
			{
				rotate(&a);
				printf("ra\n");
			}
			else if (action_b == rb)
			{
				rotate(&b);
				printf("rb\n");
			}
			else if (action_a == rra)
			{
				rrotate(&a);
				printf("rra\n");
			}
			else if (action_b == rrb)	
			{
				rrotate(&b);
				printf("rrb\n");
			}
		}
	}
	return (0);
}