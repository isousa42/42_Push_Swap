#include "push_swap.h"

void    organize_a(int *stack_a, int *stack_b, t_ps *ps)
{
    int middle;
    int pos;

    middle = bubble_sort(stack_a, ps);
    while (stack_a[0] < middle)
        pb(stack_a, stack_b, ps);
    //printf("AQUI");
    while (check_res(stack_a, ps, middle) && ps->bottom_a >= 2)
    {
        //printf("MID = %d\n", middle);
        if (ps->pos < ps->bottom_a / 2)
            ra(stack_a, ps, 1);
        else
            rra(stack_a, ps, 1);
        while (stack_a[0] < middle)
            pb(stack_a, stack_b, ps);
    }
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

    j = 0;
    while (j < argc)
    {
        if (stack_a[j] == 0)
        {
            stack_a[j] = 1;
        }
        j++;
    }


    // ORGANIZE 2 NUMBERS
    if (argc == 3)
    {
        if (stack_a[0] > stack_a[1])
            sa(stack_a, &ps, 1);
    }

    // ORGANIZE 3 NUMBERS
    if (argc == 4)
        org_3dig(stack_a, &ps);

    // ORGANIZE 4 NUMBERS
    if (argc == 5)
        org_4dig(stack_a, stack_b, &ps);

    if (argc > 5)
    {
        int pos;
        int middle;
        int dist;
        while (ps.bottom_a > 2)
            organize_a(stack_a, stack_b, &ps);
        org_3dig(stack_a, &ps);
        while (ps.top_b <= ps.size)
        {
            pos = check_bigger(stack_b, &ps);
            middle = ps.size / 2;
            dist = pos - ps.top_b;
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
    




    // j = 0;
    // while (j < argc - 1)
    // {
    //     if(stack_a[j] == 0)
    //         printf("      ");
    //     else
    //         printf("%-5d", stack_a[j]);
    //     if (stack_b[j] == 0)
    //         printf(". \n");
    //     else
    //         printf("%d\n", stack_b[j]);
    //     j++;
    // }

    
    return (0);

}