NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = 	ft_printf.c \
		ft_length.c \
		ft_words.c \
		ft_numbers.c \
		ft_printnumbers.c \
		ft_printwords.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
