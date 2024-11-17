#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct	s_int_list{
	int c;
	struct s_int_list *next;
	struct s_int_list *previous;
} t_int_list;

enum e_action
{
	sa,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
	rbrb,
	rara,
	none
};

struct pivots
{
	int pivot_high;
	int pivot_low;
};

struct minmax
{
	int min;
	int max;
};


t_int_list *create_node(int c);
void manage_push(t_int_list **stack_pushed, t_int_list **stack_poped);
void push(t_int_list **stack, t_int_list **node);
void swap(t_int_list **stack);
void rotate(t_int_list **stack);
void rrotate(t_int_list **stack);
int is_sorted_a(t_int_list *stack);

enum e_action best_action_a(t_int_list *stack, int pivot);
enum e_action best_action_b(t_int_list *stack, int min);

#endif