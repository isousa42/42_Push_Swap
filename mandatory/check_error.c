#include "push_swap.h"

int	if_order(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stackA[i] > stack->stackA[i + 1])
			return (0);
		i++;
	}
	free(stack->stackA);
	free(stack->stackB);
	return (1);
}

int	check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
			{
				if (ft_strnstr(argv[i], argv[j], ft_strlen(argv[i])))
				{
					write(1, "Error\n", 6);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_caracters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
