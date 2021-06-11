#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10;
		num += (sign * (*(str++) - '0'));
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return (num);
}

int check_duplicates(int *array, int size)
{
    int i;
    int j;
    int check;

    i = 0;
    while (i < size)
    {
        j = 0;
        check = -1;
        while (j < size)
        {
            if (array[j] == array[i])
                check++;
            if (check == 1)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int    bubble_sort(int *stack, t_ps *ps)
{
    int middle;
    int mid_pos;
    int array[ps->bottom_a + 1];
    int temp;
    int i;
    int j;

    i = 0;
    while (i < ps->bottom_a)
    {
        array[i] = stack[i];
        i++;
    }
    i = 0;
    while(i < ps->bottom_a - 1)
    {
        j = 0;
        while (j < ps->bottom_a - i - 1)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    mid_pos = ps->bottom_a / 2;
    middle = array[mid_pos];
    return (middle);
}

int     check_res(int *stack_a, t_ps *ps, int middle)
{
    int i;

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

int     check_bigger(int *stack, t_ps *ps)
{
    int i = 0;
    ps->big = -99999;
    while (i <= ps->size)
    {
        if (ps->big < stack[i] && stack[i] != 0)
            ps->big = stack[i];
        i++;
    }
    i = 0;
    while (i <= ps->size)
    {
        if (ps->big == stack[i])
            return (i);
        i++;
    }
    return (0);
}