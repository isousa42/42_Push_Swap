#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_ps
{
	int top_b;
    int bottom_a;
    int size;
    int pos;
    int chunks;

}		t_ps;

void    print(int *stack_a, int *stack_b, int size);
int	    ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int     check_dup(char **argv);
void    init(t_ps *ps, int *stack_a, int *stack_b, char **argv);
void    org_3dig(int *stack_a, t_ps *ps);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     check_order(int *stack_a, t_ps *ps);

void    sa(int *stack_a, t_ps *ps, int control);
void    ra(int *stack_a, t_ps *ps, int control);
void    rra(int *stack_a, t_ps *ps, int control);
void    pb(int *stack_a, int *stack_b, t_ps *ps);
void    sb(int *stack_b, t_ps *ps, int control);
void    rb(int *stack_b, t_ps *ps, int control);
void    rrb(int *stack_b, t_ps *ps, int control);
void    pa(int *stack_b, int *stack_a, t_ps *ps);
int     check_digit(char **argv);
int     ft_isdigit(int c);
int     check_bigger(int *stack, t_ps *ps);
int     check_res(int *stack_a, t_ps *ps, int middle);
void    sort(int *array, int size);
int    bubble_sort(int *stack, t_ps *ps);
void    org_stack_a(int *stack_a, int *stack_b, t_ps *ps);
void    org_stack_b(int *stack_a, int *stack_b, t_ps *ps);
void    init_struct(t_ps *ps);
int		select_middle(int *array, t_ps *ps, int temp, int middle);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	check_init(char **argv, t_ps *ps, int *stack_a, int *stack_b);