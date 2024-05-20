#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = so_long

SRCS = main.c get_map.c check_map.c get_images.c game.c utils.c exit_free.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJECTS = $(SRCS:%.c=%.o)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
MLX = minilibx/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./
MFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit 
LIBFT_FLAGS = -L ./libft -lft
PRINTF_FLAGS = -L ./printf -lftprintf -I ./printf
RM = rm -rf

%.o: %.c Makefile so_long.h
	$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(PRINTF):
	@$(MAKE) -C ./printf

$(MLX):
	@$(MAKE) -C ./minilibx

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(MFLAGS) $(OBJECTS) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -o $(NAME)
	@echo "$(GREEN)SO_LONG DONE$(END)"

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./printf
	@$(MAKE) clean -C ./minilibx
	@$(RM) $(OBJECTS)
	@echo "$(RED)OBJECTS DELETED$(END)"
	
	
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./printf
	@$(MAKE) fclean -C ./minilibx
	@$(RM) $(NAME)
	@echo "$(RED)OBJECTS2 DELETED$(END)"
	
re: fclean all

.PHONY: all clean fclean re
