#include "push_swap.h"

void    sa(int *stack_a, t_ps *ps, int control)
{
    int temp;
    if (ps->bottom_a < 0)
        return ;
    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;
    if (control == 1)
        printf("sa\n");
}

void    sb(int *stack_b, t_ps *ps, int control)
{
    int temp;

    if (ps->size - ps->bottom_a == 1)
        return ;    
    temp = stack_b[ps->top_b];
    stack_b[ps->top_b] = stack_b[ps->top_b + 1];
    stack_b[ps->top_b + 1] = temp;
    if (control == 1)
        printf("sb\n");
}

void    ra(int *stack_a, t_ps *ps, int control)
{
    int temp;
    int i;

    temp = stack_a[0];
    i = 0;
    while (i < ps->bottom_a)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    stack_a[i] = temp;
    if (control == 1)
        printf("ra\n");
}

void    rb(int *stack_b, t_ps *ps, int control)
{
    int temp;
    int i;

    temp = stack_b[ps->top_b];
    i = ps->top_b;
    while (i < ps->size)
    {
        
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    stack_b[i] = temp;
    if (control == 1)
        printf("rb\n");
}

void    rra(int *stack_a, t_ps *ps, int control)
{
    int temp;
    int i;

    i = ps->bottom_a;
    temp = stack_a[ps->bottom_a];
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[i] = temp;
    if (control == 1)
        printf("rra\n");
}

void    rrb(int *stack_b, t_ps *ps, int control)
{
    int temp;
    int i;

    i = ps->size;
    temp = stack_b[ps->size];
    while (i > ps->top_b)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[i] = temp;
    if (control == 1)
        printf("rrb\n");
}

void    pb(int *stack_a, int *stack_b, t_ps *ps)
{
    if (stack_a[0] == 0)
        return ;
    stack_b[ps->top_b - 1] = stack_a[0];
    ps->top_b--;
    stack_a[0] = 0;
    ra(stack_a, ps, 0);
    ps->bottom_a--;
    printf("pb\n");
}

void    pa(int *stack_b, int *stack_a, t_ps *ps)
{
    ps->bottom_a++;
    rra(stack_a, ps, 0);
    stack_a[0] = stack_b[ps->top_b];
    stack_b[ps->top_b] = 0;
    ps->top_b++;
    printf("pa\n");
}