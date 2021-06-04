#include "push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	temp;

	temp = stack->stackA[0];
	if (stack->stackA[1] == 0)
		return ;
	stack->stackA[0] = stack->stackA[1];
	stack->stackA[1] = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int print)
{
	int	temp;

	temp = stack->stackB[find_top_b(stack) + 1];
	stack->stackB[find_top_b(stack) + 1] = stack->stackB[find_top_b(stack) + 2];
	stack->stackB[find_top_b(stack) + 2] = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	pb(t_stack *stack, int print)
{
	int	save;
	int	i;

	save = stack->stackA[0];
	i = 0;
	if (save == 0)
		return ;
	while (i <= stack->size)
	{
		stack->stackA[i] = stack->stackA[i + 1];
		i++;
	}
	stack->stackB[find_top_b(stack)] = save;
	if (print == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack *stack, int print)
{
	int	save;
	int	i;

	save = stack->stackB[find_top_b(stack) + 1];
	if (save == 0)
		return ;
	stack->stackB[find_top_b(stack) + 1] = 0;
	i = stack->size;
	while (i > 0)
	{
		stack->stackA[i] = stack->stackA[i - 1];
		i--;
	}
	stack->stackA[i] = save;
	if (print == 1)
		write(1, "pa\n", 3);
}

int	find_botton(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->stackA[i])
		i++;
	while (stack->stackA[i] == 0)
		i--;
	return (i);
}
