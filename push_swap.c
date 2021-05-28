#include "push_swap.h"

int main(int argc, char **argv)
{
    int     stack_a[argc - 1];
    int     stack_b[argc - 1];
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
        i++;
        j++;
    }
    // CHECK ERROR
    if (check_duplicates(stack_a, argc - 1) == -1)
    {
        printf("ERROR = DUPLICATES!");
        exit(0);
    }

    if (argc == 3)
    {
        if (stack_a[0] > stack_a[1])
            sa(stack_a, &ps);
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