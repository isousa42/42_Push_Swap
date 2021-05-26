#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_ps
{
	int top_b;
    int bottom_a;

}		t_ps;


int check_duplicates(int *array, int size);
int	ft_atoi(const char *str);

void    sa(int *array, t_ps *ps);