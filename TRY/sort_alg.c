#include "push_swap.h"

void	sort_array(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	while(i < size)
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

int	bubble_sort_chunk(int *stack, t_ps *ps)
{
	int	middle;
	int	mid_pos;
	int	array[ps->size];
	int	temp;
	int	i;
	int	j;

	i = 0;
	mid_pos = 0;
	j = 0;
	while (i < ps->size)
	{
		array[i] = stack[i];
		i++;
	}
	sort_array(array, ps->size);
	ps->chunks = ps->chunks + (ps->size / 10);
	middle = array[ps->chunks];
	return (middle);
}

int	bubble_sort(int *stack, t_ps *ps)
{
	int	middle;
	int	mid_pos;
	int	array[ps->bottom_a + 1];
	int	i;

	i = 0;
	while (i <= ps->bottom_a)
	{
		array[i] = stack[i];
		i++;
	}
	sort_array(array, ps->bottom_a + 1);
	mid_pos = (ps->bottom_a + 1) / 2;
	middle = array[mid_pos];
	return (middle);
}