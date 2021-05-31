#include "push_swap.h"

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
            return (i);
        i++;
    }
    return (-1);

}

int     check_bigger(int *stack, t_ps *ps)
{
    int i = 0;
    ps->big = -999;
    while (i <= ps->size)
    {
        if (ps->big < stack[i])
            ps->big = stack[i];
        i++;
    }
    i = 0;
    while (i < ps->size)
    {
        if (ps->big == stack[i])
            return (i);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int     stack_a[argc - 1];
    int     stack_b[argc - 1];
    int     sort[argc - 1];
    int     i;
    int     j;
    t_ps ps;

    i = 1;
    j = 0;
    ps.bottom_a = argc - 2;
    ps.top_b = argc - 1;
    ps.size = argc - 2;

    // SET ARRAY TO NULL
    while (j < argc - 1)
    {
        stack_a[j] = 0;
        stack_b[j] = 0;
        j++;
    }

    // FILL UP THE ARRAY
    j = 0;
    while (i < argc)
    {
        stack_a[j] = ft_atoi(argv[i]);
        sort[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    // CHECK ERROR
    if (check_duplicates(stack_a, argc - 1) == -1)
    {
        printf("ERROR = DUPLICATES!");
        exit(0);
    }

    // ORGANIZE 2 NUMBERS
    if (argc == 3)
    {
        if (stack_a[0] > stack_a[1])
            sa(stack_a, &ps);
    }

    // ORGANIZE 3 NUMBERS
    if (argc == 4)
        org_3dig(stack_a, &ps);

    // ORGANIZE 4 NUMBERS
    if (argc == 5)
        org_4dig(stack_a, stack_b, &ps);

    if (argc > 5)
    {
        int middle;
        int pos;
        i = 0;
        while (ps.bottom_a > 2)
        {
            middle = bubble_sort(stack_a, &ps);
            while (1)
            {
                while (stack_a[0] < middle)
                {
                    pb(stack_a, stack_b, &ps);
                    if (ps.top_b % 2 == 0)
                    {
                        if (stack_b[ps.top_b] < stack_b[ps.top_b + 1])
                            sb(stack_b, &ps);
                    }
                }
                pos = check_res(stack_a, &ps, middle);
                if (pos == -1)
                    break;
                if (pos < ps.bottom_a / 2)
                    ra(stack_a, &ps, 1);
                else if(pos >=  ps.bottom_a / 2)
                    rra(stack_a, &ps, 1);
            }
        }
        if (ps.bottom_a == 1)
        {
            if (stack_a[0] > stack_a[1])
                sa(stack_a, &ps);
        }
        else if(ps.bottom_a == 2)
            org_3dig(stack_a, &ps);
        
        while (ps.top_b <= ps.size)
        {
            pos = check_bigger(stack_b, &ps);
            middle = (ps.size) / 2;
            int dist = pos - ps.top_b;
            int me = stack_b[pos];
            while (stack_b[ps.top_b] != ps.big)
            {
                if (dist < middle)
                    rb(stack_b, &ps, 1);
                else
                    rrb(stack_b, &ps, 1);
            }
            pa(stack_b, stack_a, &ps);
        }

    }









    //pa(stack_b, stack_a, &ps);
    //pb(stack_a, stack_b, &ps);

    //sb(stack_b, &ps);
    //sa(stack_a, &ps);

    //rb(stack_b, &ps, 1);
    //ra(stack_a, &ps, 1);

    //rrb(stack_b, &ps, 1);
    //rra(stack_a, &ps, 1);
    




    j = 0;
    while (j < argc - 1)
    {
        if(stack_a[j] == 0)
            printf("      ");
        else
            printf("%-5d", stack_a[j]);
        if (stack_b[j] == 0)
            printf(". \n");
        else
            printf("%d\n", stack_b[j]);
        j++;
    }

    
    return (0);

}