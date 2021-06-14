#include "checker.h"

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

void	check_init(char **argv, t_ps *ps, int *stack_a, int *stack_b)
{
	if (check_digit(argv) == -1 || check_dup(argv) == -1)
	{
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	ps->bottom_a = ps->size - 1;
	ps->top_b = ps->size;
	init(ps, stack_a, stack_b, argv);
}

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

void	select_function(char *line, t_ps *ps, int *stack_a, int *stack_b)
{
	if (line[0] == 's' && line[1] == 'a')
		sa(stack_a, ps);
	else if (line[0] == 's' && line[1] == 'b')
		sb(stack_b, ps);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(stack_a, ps);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(stack_b, ps);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(stack_b, stack_a, ps);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(stack_a, stack_b, ps);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(stack_a, ps);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(stack_b, ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		*stack_a;
	int		*stack_b;
	char	*line;

	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	stack_b = (int *)malloc(sizeof(int) * argc - 1);
	ps.size = argc - 1;
	check_init(argv, &ps, stack_a, stack_b);
	while (get_next_line(STDIN_FILENO, &line))
		select_function(line, &ps, stack_a, stack_b);
	free(line);
	if (check_order(stack_a, &ps) == 1 && ps.top_b == ps.size)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	return (0);
}
