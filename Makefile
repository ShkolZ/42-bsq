NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		garbage.c \
		parse.c \
		helpers.c \
		square.c \
		output.c \
		error.c

OBJS = $(SRCS:.c=.o)

HEADERS = bsq.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re