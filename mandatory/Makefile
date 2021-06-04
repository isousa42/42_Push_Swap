CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRCS = cmds.c cmds2.c main.c sort.c organize.c finds.c utils.c utils2.c check_error.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: 
	rm -rf $(OBJS) $(NAME)

re: fclean all
