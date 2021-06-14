CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

NAME	= push_swap
NAME_BONUS = checker
HEADER = push_swap.h
HEADER_BONUS = checker.h

SRCS = push_swap.c utils.c ps_functions1.c organize.c checkers.c sort_functions.c ps_functions2.c
SRCS_BONUS = main.c gnl.c gnl_bonus.c ps_functions1_bonus.c ps_functions2_bonus.c checkers_bonus.c utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : 
	gcc $(SRCS) $(FLAGS) -o $(NAME)

bonus:
	gcc $(SRCS_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	 	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY:		all clean fclean re 