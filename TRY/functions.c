#include "push.h"

void    sa(int *stack_a, t_ps *ps, int control)
{
    int temp;
    if (ps->bottom_a < 1)
        return ;
    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;
    if (control == 1)
        write(1, "sa\n", 4);
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
        write(1, "ra\n", 4);

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
        write(1, "rra\n", 5);

}

void    pb(int *stack_a, int *stack_b, t_ps *ps)
{
    if (ps->bottom_a < 0)
        return ;
    ps->top_b--;
    stack_b[ps->top_b] = stack_a[0];
    
    stack_a[0] = 0;
    ra(stack_a, ps, 0);
    ps->bottom_a--;
    write(1, "pb\n", 4);

}

void    sb(int *stack_b, t_ps *ps, int control)
{
    int temp;

    if (ps->size - ps->top_b < 2)
        return ;
    temp = stack_b[ps->top_b];
    stack_b[ps->top_b] = stack_b[ps->top_b + 1];
    stack_b[ps->top_b + 1] = temp;
    if (control == 1)
        write(1, "sb\n", 4);

}

void    rb(int *stack_b, t_ps *ps, int control)
{
    int temp;
    int i;

    if (ps->size - ps->top_b < 2)
        return ;
    temp = stack_b[ps->top_b];
    i = ps->top_b;
    while (i < ps->size - 1)
    {
        
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    stack_b[i] = temp;
    if (control == 1)
        write(1, "rb\n", 4);

}

void    rrb(int *stack_b, t_ps *ps, int control)
{
    int temp;
    int i;

    i = ps->size - 1;
    temp = stack_b[ps->size - 1];
    while (i > ps->top_b)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[i] = temp;
    if (control == 1)
        write(1, "rrb\n", 5);

}

void    pa(int *stack_b, int *stack_a, t_ps *ps)
{
    ps->bottom_a++;
    rra(stack_a, ps, 0);
    stack_a[0] = stack_b[ps->top_b];
    stack_b[ps->top_b] = 0;
    ps->top_b++;
    write(1, "pa\n", 4);

}