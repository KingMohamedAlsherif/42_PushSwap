CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = main.c utils.c split.c check_errors.c sorting.c utils2.c swap.c rotate.c rev_rotate.c push.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re