#ifndef TEST_H
#define TEST_H

#include "../../libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define GREEN "\033[38;5;84m"
#define RED "\033[38;5;197m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"

int ft_isalpha_tests(void);
int ft_isdigit_tests(void);
int ft_isalnum_tests(void);
int ft_isascii_tests(void);
int ft_isprint_tests(void);
int ft_strlen_tests(void);
int ft_memset_tests(void);
int ft_bzero_tests(void);
int ft_memcpy_tests(void);
int ft_memmove_tests(void);
int ft_strlcpy_tests(void);
int ft_strlcat_tests(void);
int ft_toupper_tests(void);
int ft_tolower_tests(void);
int ft_strchr_tests(void);
int ft_strrchr_tests(void);
int ft_strncmp_tests(void);
int ft_memchr_tests(void);
int ft_memcmp_tests(void);
int ft_strnstr_tests(void);
int ft_atoi_tests(void);
int ft_calloc_tests(void);
int ft_strdup_tests(void);
int ft_substr_tests(void);
int ft_strjoin_tests(void);
int ft_strtrim_tests(void);
int ft_split_tests(void);
int ft_itoa_tests(void);

#endif
