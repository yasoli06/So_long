NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBMLX = ./mlx
LIBFT = ./libft
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
HEADER = so_long.h
RM = rm -f


%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

all: libft/libft.a $(LIBMLX)/ mlx/libmlx.a $(NAME)

libft/libft.a:
	make -C ./libft

$(LIBMLX)libmlx/libmlx.a:
	make -C ./mlx

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(FLAGS) $(OBJECTS) -L $(LIBFT) -lft -L $(LIBMLX) -lmlx $(MLX_FLAGS) -o $(NAME

clean:
	$(RM) $(OBJECTS)

fclean: clean
	make clean $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

	
