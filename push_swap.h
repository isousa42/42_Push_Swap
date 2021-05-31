#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_ps
{
	int top_b;
    int bottom_a;
    int size;
    int big;

}		t_ps;


int check_duplicates(int *array, int size);
int	ft_atoi(const char *str);

void    sa(int *stack_a, t_ps *ps);
void    sb(int *stack_b, t_ps *ps);
void    ra(int *stack_a, t_ps *ps, int control);
void    rb(int *stack_b, t_ps *ps, int control);
void    rra(int *stack_a, t_ps *ps, int control);
void    rrb(int *stack_b, t_ps *ps, int control);
void    pb(int *stack_a, int *stack_b, t_ps *ps);
void    pa(int *stack_b, int *stack_a, t_ps *ps);

void    org_3dig(int *stack_a, t_ps *ps);
void    org_4dig(int *stack_a, int *stack_b, t_ps *ps);