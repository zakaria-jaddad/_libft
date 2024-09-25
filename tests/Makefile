MAKE = make
MAKE_ARGS = --no-print-directory

CC 	= gcc

SRC_DIR	= src
SRC	= $(shell find $(SRC_DIR) -type f -name "*.c")

INCLUDE_DIR = include
INCLUDE	= $(shell find $(INCLUDE_DIR) -type f name "*.h")

BIN_DIR = bin
OBJ 	= $(SRC:.c=.o)

NAME 	= libft_test

CFLAGS 	= -Wall -Werror -Wextra -I$(INCLUDE_DIR)
LFLAGS	= -lcriterion -L$(LIBFT_DIR) -lft -I/opt/homebrew/include/criterion/ -L /opt/homebrew/lib/
 

HEADER 	= tests.h 

LIBFT_DIR = ..

all: libft_re $(NAME)

$(NAME): $(OBJ)
	@echo "Test: Linking: $@"
	$(CC) $(wildcard $(BIN_DIR)/*.o) $(LFLAGS) -o $@ 


%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $(BIN_DIR)/$(notdir $@)

re: $(NAME)

libft_all:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) all

libft_fclean:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) fcleank

libft_re:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) re
