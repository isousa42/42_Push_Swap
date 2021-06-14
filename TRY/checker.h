#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_ps
{
	int	top_b;
	int	bottom_a;
	int	size;
}		t_ps;

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *src);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

void	sa(int *stack_a, t_ps *ps);
void	ra(int *stack_a, t_ps *ps);
void	rra(int *stack_a, t_ps *ps);
void	pb(int *stack_a, int *stack_b, t_ps *ps);
void	sb(int *stack_b, t_ps *ps);
void	rb(int *stack_b, t_ps *ps);
void	rrb(int *stack_b, t_ps *ps);
void	pa(int *stack_b, int *stack_a, t_ps *ps);

void	init(t_ps *ps, int *stack_a, int *stack_b, char **argv);
void	check_init(char **argv, t_ps *ps, int *stack_a, int *stack_b);
int		check_order(int *stack_a, t_ps *ps);
int		check_dup(char **argv);
int		check_digit(char **argv);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	select_function(char *line, t_ps *ps, int *stack_a, int *stack_b);

#endif
