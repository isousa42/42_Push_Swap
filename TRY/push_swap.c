#include "push_swap.h"

void	init_struct(t_ps *ps)
{
	ps->bottom_a = ps->size - 1;
	ps->top_b = ps->size;
	ps->pos = 0;
	ps->chunks = 0;
}

void	init(t_ps *ps, int *stack_a, int *stack_b, char **argv)
{
	int	j;
	int	i;

	j = 0;
	while (j < ps->size)
	{
		stack_a[j] = 0;
		stack_b[j] = 0;
		j++;
	}
	j = 0;
	i = 1;
	while (i < ps->size + 1)
	{
		stack_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	j = 0;
	while (j < ps->size + 1)
	{
		if (stack_a[j] == 0)
			stack_a[j] = 1;
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	ps.size = argc - 1;
	int		stack_a[ps.size];
	int		stack_b[ps.size];

	if (check_digit(argv) == -1)
	{
		write(1, "Error\n", 7);
		exit(0);
	}
	check_dup(argv);
	init_struct(&ps);
	init(&ps, stack_a, stack_b, argv);
	if (check_order(stack_a, &ps) == 1)
		exit(0);
	if (argc == 4)
		org_3dig(stack_a, &ps);
	if (argc >= 5)
	{
		while (ps.bottom_a > 2)
			org_stack_a(stack_a, stack_b, &ps, argc);
		org_3dig(stack_a, &ps);
		while (ps.top_b < ps.size)
			org_stack_b(stack_a, stack_b, &ps);
	}
	return (0);
}
