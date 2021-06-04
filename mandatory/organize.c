#include "push_swap.h"

void	organize_3(t_stack *stack)
{
	int	botton;
	int	middle;
	int	top;

	botton = stack->stackA[2];
	top = stack->stackA[0];
	middle = stack->stackA[1];
	if (top > middle && middle < botton && botton > top)
		sa(stack, 1);
	else if (top > middle && middle > botton && botton < top)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (top > middle && middle < botton && botton < top)
		ra(stack, 1);
	else if (top < middle && middle > botton && botton > top)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (top < middle && middle > botton && botton < top)
		rra(stack, 1);
}

void	organize_a(t_stack *stack, int middle)
{
	int	size;

	while (stack->stackA[0] < middle)
		pb(stack, 1);
	size = find_new_size(stack);
	has_less(stack, middle);
	while (has_less(stack, middle))
	{
		while (stack->stackA[0] < middle)
			pb(stack, 1);
		if (stack->pos > size / 2)
			rra(stack, 1);
		else
			ra(stack, 1);
		while (stack->stackA[0] < middle)
			pb(stack, 1);
	}
}

void	organize_b(t_stack *stack)
{
	int	new_size;
	int	distance;

	if (stack->stackB[find_top_b(stack) + 2] == stack->stackB[find_big(stack)]
		&& find_new_size_b(stack) > 3)
		sb(stack, 1);
	new_size = find_new_size_b(stack);
	new_size = new_size / 2;
	distance = (find_big(stack) - find_top_b(stack));
	while (stack->stackB[find_top_b(stack) + 1]
		!= stack->stackB[find_big(stack)])
	{
		if (distance > new_size)
			rrb(stack, 1);
		else
			rb(stack, 1);
	}
	pa(stack, 1);
}
