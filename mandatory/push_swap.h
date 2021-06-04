#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h> 

typedef struct s_stack
{
	int		*stackA;
	int		*stackB;
	int		size;
	int		pos;
	int		chunk;
}			t_stack;

/* comand functions */
void	sa(t_stack *stackA, int print);
void	sb(t_stack *stackB, int print);
void	ss(t_stack *stackA, int print);
void	ra(t_stack *stackA, int print);
void	rb(t_stack *stackB, int print);
void	rr(t_stack *stackA, int print);
void	rra(t_stack *stackA, int print);
void	rrb(t_stack *stackB, int print);
void	rrr(t_stack *stackA, int print);
void	pb(t_stack *stack, int print);
void	pa(t_stack *stack, int print);

/* organize functions */
void	organize_3(t_stack *stack);
void	organize_b(t_stack *stack);
void	organize_a(t_stack *stack, int middle);

/* find functions */
int		find_botton(t_stack *stack);
int		find_top_b(t_stack *stack);
int		find_big(t_stack *stack);
int		find_small(t_stack *stack);
int		find_new_size(t_stack *stack);
int		find_new_size_b(t_stack *stack);

/* utils */
int		has_less(t_stack *stack, int middle);
int		midle_number(t_stack *stack);
int		middle_move(t_stack *stack);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_sort(int size, int *array);
int		ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_isdigit(int c);
int		ft_lenofnum_bonus(int n);
char	*ft_itoa(int n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/* check_errors */
int		if_order(t_stack *stack);
int		check_double(char **argv);
int		check_caracters(char **argv);

#endif
