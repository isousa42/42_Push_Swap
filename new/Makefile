CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

NAME	= push
HEADER = push.h

SRCS = push.c utils.c functions.c organize.c

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