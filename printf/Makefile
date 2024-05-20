NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr.c

OBJECTS = $(SRC:%.c=%.o)

HEADER = printf.h
cc = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

#metodo implicito
%.o:%.c 	$(HEADER) Makefile
			$(CC) $(FLAGS) -c $< -o $@

#mis metodos
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean