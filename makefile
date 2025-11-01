NAME = so_long

SRC = src/so_long.c \
      src/parsing/map_reader.c \
      src/parsing/utils.c \
      src/parsing/map_parsing.c \
      src/parsing/path_check.c \
      src/error.c \
      src/libft/get_next_line.c \
      src/libft/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Isrc/libft -Isrc/get_next_line

LIBFT = src/libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C src/libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C src/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C src/libft

re: fclean all

.PHONY: all clean fclean re