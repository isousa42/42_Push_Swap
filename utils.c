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