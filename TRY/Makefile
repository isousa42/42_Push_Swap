CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

NAME	= push_swap
HEADER = push_swap.h

SRCS = push_swap.c utils.c ps_functions1.c organize.c checkers.c sort_functions.c ps_functions2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : 
	gcc $(SRCS) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	 	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re 