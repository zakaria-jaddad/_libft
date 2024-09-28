MAKE = make
CC 	= gcc
NAME 	= libft.a
CFLAGS 	= -Wall -Werror -Wextra -o
HEADER 	= libft.h
SRC 	= ft_memset.c \
	  ft_strnstr.c
OBJ 	= $(SRC:.c=.o)

TEST_DIR = tests/


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $< -c $(CFLAGS) $@

clean:
	rm -rf  $(OBJ)

fclean: clean
	rm -rf  $(NAME)
	rm -rf main

re: fclean $(NAME) 

main: re
	$(CC) main.c -L. -lft $(CFLAGS) $@

.PHONEY: clean fclean re main all $(NAME)
