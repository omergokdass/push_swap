NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	stack_utils.c \
	rules/rules0.c \
	rules/rules1.c \
	rules/rules2.c \
	rules/rules3.c \
	sort_small.c \
	parse_input.c \
	main.c
LIBFT = libft/libft.a
INCLUDE = -Iinclude -Ilibft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
