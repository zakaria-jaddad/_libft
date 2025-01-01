MAKE	= make
MAKE_ARGS = --no-print-directory

CC 	= gcc

SRC_DIR = src
SRC	= $(shell find $(SRC_DIR) -type f -name "*.c")

UTIL_DIR = util
UTIL	= $(shell find $(UTIL_DIR) -type f -name "*.c")

INCLUDE_DIR = include
INCLUDE	= $(shell find $(INCLUDE_DIR) -type f -name "*.h")

BIN_DIR = bin
OBJ = $(SRC:.c=.o) $(UTIL:.c=.o)

NAME = libft_test

LIBFT_DIR = ..
LIBFT_TEST_DIR = .

CFALGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)
LFLAGS = -L$(LIBFT_DIR) -lft 

HEADER = test.h

all: $(NAME)

$(NAME): libft_re $(OBJ)
	@echo "ya linkiniiiiii..... $@"
	$(CC) $(NAME).c $(wildcard $(BIN_DIR)/*.o) $(LFLAGS) -o $@
	./$(NAME)

%.o: %.c
	$(CC) $< $(CFALGS) -c -o $(BIN_DIR)/$(notdir $@)

re: $(NAME)

fclean: libft_fclean
	rm -rf $(NAME) $(BIN_DIR)/* 

libft_all:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) all

libft_fclean:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) fclean

libft_re:
	@$(MAKE) $(MAKE_ARGS) -s -C $(LIBFT_DIR) re

