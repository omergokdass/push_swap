NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	stack_utils.c \
	rules0.c \
	rules1.c \
	rules2.c \
	rules3.c \
	parse_input.c \
	small_sort.c

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
	rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
