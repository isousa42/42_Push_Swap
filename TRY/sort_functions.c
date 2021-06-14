#include "push_swap.h"

void	sort(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	select_middle(int *array, t_ps *ps, int temp, int middle)
{
	if (temp <= 100)
	{
		sort(array, ps->bottom_a + 1);
		middle = (ps->bottom_a + 1) / 2;
		middle = array[middle];
	}
	else
	{
		sort(array, temp);
		ps->chunks = ps->chunks + (temp / 10);
		middle = array[ps->chunks];
	}
	return (middle);
}

int	bubble_sort(int *stack, t_ps *ps)
{
	int	middle;
	int	*array;
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp = ps->size;
	middle = 0;
	array = ft_calloc(ps->size, sizeof(int *));
	while (i <= temp)
	{
		array[i] = stack[i];
		i++;
	}
	middle = select_middle(array, ps, temp, middle);
	free(array);
	return (middle);
}
