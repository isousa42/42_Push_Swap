#include "push.h"

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