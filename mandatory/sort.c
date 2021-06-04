#include "push_swap.h"

void	ft_sort(int size, int *array)
{
	int	i;
	int	temp;

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

int	middle_move(t_stack *stack)
{
	int	*array;
	int	middle;

	array = ft_calloc(stack->size, sizeof(int));
	ft_memcpy(array, stack->stackA, sizeof(int) * stack->size);
	ft_sort(stack->size, array);
	stack->chunk = stack->chunk + (stack->size / 10);
	middle = array[stack->chunk];
	return (middle);
}

int	midle_number(t_stack *stack)
{
	int	*array;
	int	middle;

	array = ft_calloc(find_new_size(stack), sizeof(int));
	ft_memcpy(array, stack->stackA, sizeof(int) * find_new_size(stack));
	ft_sort(find_new_size(stack), array);
	middle = find_new_size(stack) / 2;
	middle = array[middle];
	return (middle);
}

int	has_less(t_stack *stack, int middle)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stackA[i] < middle && stack->stackA[i] != 0)
		{
			stack->pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}
