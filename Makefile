NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MFLAGS = -framework OpenGL -framework AppKit
RM = rm -rf

LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

SRCS = 	so_long.c get_map.c check_map.c get_images.c game.c gnl/get_next_line.c gnl/get_next_line_utils.c utils.c free.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx


$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(SRCS) -o $(NAME) -L ./minilibx -lmlx -L ./libft -lft $(MFLAGS) -g


clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx
	@$(RM) $(NAME)
	
re: fclean all
