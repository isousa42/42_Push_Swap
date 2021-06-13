#include "push_swap.h"

int	check_order(int *stack_a, t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_res(int *stack_a, t_ps *ps, int middle)
{
	int	i;

	i = 0;
	while (i <= ps->bottom_a)
	{
		if (stack_a[i] < middle)
		{
			ps->pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_bigger(int *stack, t_ps *ps)
{
	int	i;
	int	big;

	i = ps->top_b;
	big = -2147483647;
	while (i < ps->size)
	{
		if (big < stack[i])
			big = stack[i];
		i++;
	}
	i = ps->top_b;
	while (i < ps->size)
	{
		if (big == stack[i])
			return (i);
		i++;
	}
	return (0);
}
