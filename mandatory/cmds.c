#include "push_swap.h"

void	rra(t_stack *stack, int print)
{
	int	botton;
	int	x;
	int	i;

	botton = find_botton(stack);
	x = stack->stackA[botton];
	i = botton;
	while (i > 0)
	{
		stack->stackA[i] = stack->stackA[i - 1];
		i--;
	}
	stack->stackA[0] = x;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int print)
{
	int	x;
	int	i;

	x = stack->stackB[stack->size];
	i = stack->size;
	while (i > 0)
	{
		stack->stackB[i] = stack->stackB[i - 1];
		i--;
	}
	stack->stackB[find_top_b(stack)] = x;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	ra(t_stack *stack, int print)
{
	int	botton;
	int	x;
	int	i;

	x = stack->stackA[0];
	i = 0;
	botton = find_botton(stack);
	while (i <= botton)
	{
		stack->stackA[i] = stack->stackA[i + 1];
		i++;
	}
	stack->stackA[botton] = x;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int print)
{
	int	top;
	int	i;
	int	botton;

	top = stack->stackB[find_top_b(stack) + 1];
	botton = stack->stackB[stack->size];
	i = find_top_b(stack) + 1;
	while (i <= stack->size)
	{
		stack->stackB[i] = stack->stackB[i + 1];
		i++;
	}
	stack->stackB[stack->size] = top;
	if (print == 1)
		write(1, "rb\n", 3);
}
