NAME = rush02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		garbage.c \
		parse.c \
		parse_helper.c \
		error_handle.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft_foo.h

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