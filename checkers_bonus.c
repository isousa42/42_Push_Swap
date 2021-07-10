#include "checker.h"

int	check_dup(char **argv)
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
				if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				{
					write(1, "\033[1;31mError\e[0m \U0001F92C\n", 23);
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(1, "Error\n", 7);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
