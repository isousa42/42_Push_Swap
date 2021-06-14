#include "push_swap.h"

void	org_3dig(int *stack_a, t_ps *ps)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		sa(stack_a, ps, 1);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
	{
		sa(stack_a, ps, 1);
		rra(stack_a, ps, 1);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
		ra(stack_a, ps, 1);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] < stack_a[2])
	{
		sa(stack_a, ps, 1);
		ra(stack_a, ps, 1);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] < stack_a[2])
		return ;
	else
		rra(stack_a, ps, 1);
}

void	org_stack_a(int *stack_a, int *stack_b, t_ps *ps)
{
	int	middle;

	middle = bubble_sort(stack_a, ps);
	while (stack_a[0] < middle)
		pb(stack_a, stack_b, ps);
	while (check_res(stack_a, ps, middle))
	{
		while (stack_a[0] < middle)
			pb(stack_a, stack_b, ps);
		if (ps->pos > (ps->bottom_a + 1) / 2)
			rra(stack_a, ps, 1);
		else
			ra(stack_a, ps, 1);
		while (stack_a[0] < middle)
			pb(stack_a, stack_b, ps);
	}
}

void	org_stack_b(int *stack_a, int *stack_b, t_ps *ps)
{
	int	size;
	int	dist;

	if (stack_b[ps->top_b + 1] == stack_b[check_bigger(stack_b, ps)]
		&& (ps->size - ps->top_b) > 3)
		sb(stack_b, ps, 1);
	size = ps->size - ps->top_b;
	size = size / 2;
	dist = (check_bigger(stack_b, ps) - (ps->top_b - 1));
	while (stack_b[ps->top_b] != stack_b[check_bigger(stack_b, ps)])
	{
		if (dist > size)
			rrb(stack_b, ps, 1);
		else
			rb(stack_b, ps, 1);
	}
	pa(stack_b, stack_a, ps);
}
