CC 	= gcc
SRC 	= ft_strlen.c
OBJ 	= $(SRC:.c=.o)
NAME 	= libft.a
CFLAGS 	= -Wall -Werror -Wextra -o
HEADER 	= libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $< -c $(CFLAGS) $@

clean: 
	rm -rf  $(OBJ)

fclean: clean 
	rm -rf  $(NAME)

re: fclean $(NAME) 

.PHONEY: 
