#include "push_swap.h"

void    org_3dig(int *stack_a, t_ps *ps)
{
    if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
        sa(stack_a, ps, 1);
    else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
    {
        sa(stack_a, ps, 1);
        rra(stack_a, ps, 1);
    }
    else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
        ra(stack_a, ps, 1);
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2] && stack_a[0] < stack_a[2])
    {
        sa(stack_a, ps, 1);
        ra(stack_a, ps, 1);
    }
    else if (stack_a[0] < stack_a[1] && stack_a[1] < stack_a[2])
        return ;
    else
        rra(stack_a, ps, 1);
}

void    org_b(int *stack_b, t_ps *ps)
{
    if (stack_b[ps->top_b] > stack_b[ps->top_b + 1] && stack_b[ps->top_b] < stack_b[ps->top_b + 2])
        sb(stack_b, ps, 1);
    else if (stack_b[ps->top_b] > stack_b[ps->top_b + 1] && stack_b[ps->top_b + 1] > stack_b[ps->top_b + 2])
    {
        sb(stack_b, ps, 1);
        rrb(stack_b, ps, 1);
    }
    else if (stack_b[ps->top_b] > stack_b[ps->top_b + 1] && stack_b[ps->top_b + 1] < stack_b[ps->top_b + 2])
        rb(stack_b, ps, 1);
    else if (stack_b[ps->top_b] < stack_b[ps->top_b + 1] && stack_b[ps->top_b + 1] > stack_b[ps->top_b + 2] && stack_b[ps->top_b] < stack_b[ps->top_b + 2])
    {
        sb(stack_b, ps, 1);
        rb(stack_b, ps, 1);
    }
    else if (stack_b[ps->top_b] < stack_b[ps->top_b + 1] && stack_b[ps->top_b + 1] < stack_b[ps->top_b + 2])
        return ;
    else
        rrb(stack_b, ps, 1);
}

void    org_4dig(int *stack_a, int *stack_b, t_ps *ps)
{
    // CHECK THE SMALLEST NUMBER (flag)
    int i = 0;
    int flag = stack_a[0];

    while (i < ps->bottom_a)
    {
        if (stack_a[i] < stack_a[i + 1])
        {
            if (stack_a[i] < flag)
                flag = stack_a[i];
        }
        i++;
    }
    if (stack_a[ps->bottom_a] < flag)
        flag = stack_a[ps->bottom_a];
    // ORGANIZE
    if (flag == stack_a[0])
        pb(stack_a, stack_b, ps);
    else if (flag == stack_a[1])
    {
        sa(stack_a, ps, 1);
        pb(stack_a, stack_b, ps);
    }
    else if (flag == stack_a[2])
    {
        rra(stack_a, ps, 1);
        rra(stack_a, ps, 1);
        pb(stack_a, stack_b, ps);
    }
    else if (flag == stack_a[3])
    {
        rra(stack_a, ps, 1);
        pb(stack_a, stack_b, ps);
    }
    org_3dig(stack_a, ps);
    pa(stack_b, stack_a, ps);
}