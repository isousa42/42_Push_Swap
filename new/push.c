#include "push.h"


// size = argc - 1 (ALWAYS) = Size of the array
// bottom_a = size - 1 (CHANGABLE) = Pos of the last element in stack A
// top_b = size (CHANGABLE) = Pos top of Stack B. Starts at size because it is empty

int    bubble_sort_chunk(int *stack, t_ps *ps)
{
    int middle;
    int mid_pos;
    int array[ps->size];
    int temp;
    int i;
    int j;

    i = 0;
    while (i < ps->size)
    {
        array[i] = stack[i];
        i++;
    }
    i = 0;
    while(i < ps->size)
    {
        if (array[i] > array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
        i++;
    }
    ps->chunks = ps->chunks + (ps->size / 10);
    middle = array[ps->chunks];
    return (middle);
}

int    bubble_sort(int *stack, t_ps *ps)
{
    int middle;
    int mid_pos;
    int array[ps->bottom_a + 1];
    int temp;
    int i;
    int j;

    i = 0;
    while (i <= ps->bottom_a)
    {
        array[i] = stack[i];
        i++;
    }
    i = 0;
    while(i < ps->bottom_a + 1)
    {
        if (array[i] > array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
        i++;
    }
    mid_pos = (ps->bottom_a + 1) / 2;
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
		{
			ps->pos = i;
			return (1);
		}
        i++;
    }
    return (0);
}

int     check_bigger(int *stack, t_ps *ps)
{
    int i = ps->top_b;
    int big = -2147483647;
    while (i < ps->size)
    {
        if (big < stack[i])
            big = stack[i];
        i++;
    }
    i = ps->top_b;
    while (i < ps->size)
    {
        if (big == stack[i])
            return (i);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_ps ps;
    ps.size = argc - 1;
    int stack_a[ps.size];
    int stack_b[ps.size];

    int middle;
    init(&ps, stack_a, stack_b, argv);
    //print(stack_a, stack_b, ps.size);

    if (argc == 4)
        org_3dig(stack_a, &ps);
    if (argc >= 5)
    {
        while (ps.bottom_a > 2)
        {
            if (argc <= 102)
                middle = bubble_sort(stack_a, &ps);
            else
                middle = bubble_sort_chunk(stack_a, &ps);
            while (stack_a[0] < middle)
		        pb(stack_a, stack_b, &ps);
            while (check_res(stack_a, &ps, middle))
            {
                while (stack_a[0] < middle)
		            pb(stack_a, stack_b, &ps);
                if (ps.pos > (ps.bottom_a + 1) / 2)
                    rra(stack_a, &ps, 1);
                else
                    ra(stack_a, &ps, 1);
                while (stack_a[0] < middle)
		            pb(stack_a, stack_b, &ps);
            }
        }
        org_3dig(stack_a, &ps);
        while (ps.top_b < ps.size)
        {
            if (stack_b[ps.top_b + 1] == stack_b[check_bigger(stack_b, &ps)] && (ps.size - ps.top_b) > 3)
                sb(stack_b, &ps, 1);
            int size = ps.size - ps.top_b;
            size = size / 2;
            int dist = (check_bigger(stack_b, &ps) - (ps.top_b - 1));
            while (stack_b[ps.top_b] != stack_b[check_bigger(stack_b, &ps)])
            {
                if (dist > size)
                    rrb(stack_b, &ps, 1);
                else
                    rb(stack_b, &ps, 1);
            }
            pa(stack_b, stack_a, &ps);
        }
    }
   //print(stack_a, stack_b, ps.size);


    
    return (0);
}




