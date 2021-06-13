#include "push.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void    init(t_ps *ps, int *stack_a, int *stack_b, char **argv)
{
    int j = 0;
    int i;
    int sort[ps->size];
    ps->bottom_a = ps->size - 1;
    ps->top_b = ps->size;
	ps->pos = 0;
	ps->chunks = 0;

    // if (check_dup(argv) == -1)
    // {
    //     printf("ERROR");
    //     exit(0);
    // }

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
		sort[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
    j = 0;
	while (j < ps->size + 1)
	{
		if (stack_a[j] == 0)
		{
			stack_a[j] = 1;
		}
		j++;
	}

}

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

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     check_dup(char **argv)
{
    int i = 1;
    int j;
    int x;
    int y;
    int check = 0;

    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
            {
				if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				{
					write(1, "\033[1;31mError\e[0m \U0001F92C\n", 23);
					exit(0);
				}
            }
            j++;
        }
        i++;
    }
    return (0);
}