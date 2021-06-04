#include "push.h"

int     check_small(int *stack, t_ps *ps)
{
    int i = 1;
    int j;
    int smaller = stack[0];
    int pos = 0;

    while (i < ps->size)
    {
        //printf("%d\n", ps->size);
        if (stack[i] == 0)
        {
            i++;
            continue;
        }
        if (stack[i] < smaller)
        {
            smaller = stack[i];
            pos = i;
        }
        i++;
    }
    stack[pos] = 255;
    //printf("POS = %d\n", pos);
    //printf("SMALL = %d\n", smaller);
    return (pos);
}

int    create_index(t_ps *ps, int *stack_a)
{
    int index[ps->size];
    int copy[ps->size];
    int i = 0;

    while (i < ps->size)
    {
        copy[i] = stack_a[i];
        i++;
    }
    i = 0;
    while (i < ps->size)
    {
        index[i] = check_small(copy, ps);
        i++;
    } 

    i = 0;
    while (i < ps->size)
    {
        printf("%d\n", index[i]);
        i++;
    }


    return (check_small(stack_a, ps));

}

int main(int argc, char **argv)
{
    t_ps ps;
    ps.size = argc - 1;
    int stack_a[ps.size];
    int stack_b[ps.size];

    init(&ps, stack_a, stack_b, argv);
    //print(stack_a, stack_b, ps.size);

    if (argc == 4)
        org_3dig(stack_a, &ps);
    //print(stack_a, stack_b, ps.size);

    create_index(&ps, stack_a);
    
    return (0);
}




//   5   0  4
//   3   1  2
//   2   2  1
//   1   3  0
//   4   4  3