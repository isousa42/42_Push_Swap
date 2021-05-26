#include "push_swap.h"

void    sa(int *stack_a, t_ps *ps)
{
    int temp;

    temp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = temp;
    printf("sa\n");
}

void    ra(int *stack_a, t_ps *ps)
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
    printf("ra\n");
}

void    rra(int *stack_a, t_ps *ps)
{
    int temp;
    int i;

}

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
    // SET ARRAY TO NULL
    while (j < argc - 1)
    {
        stack_a[j] = 0;
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


    //ra(stack_a, &ps);
    j = 0;
    while (j < argc - 1)
    {
        printf("%d\n", stack_a[j]);
        j++;
    }

    
    return (0);

}