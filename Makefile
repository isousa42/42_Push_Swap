CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

NAME	= push_swap
HEADER = push_swap.h

SRCS = push_swap.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : 
	gcc $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	 	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re 