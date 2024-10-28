#include "../include/test.h"

typedef struct test
{
  char *desc;
  char dest[40];
  char *src;
  size_t size;
  size_t expected_len;
  char *expected_output;
} ft_strlcpy_test;

static int run_tests(ft_strlcpy_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    size_t result_len = ft_strlcpy(tests->dest, tests->src, tests->size);
    if (result_len != tests->expected_len ||
        strcmp(tests->dest, tests->expected_output) != 0)
    {
      printf(" " RED
             " %s Expected \"%s\" (len %zu), got \"%s\" (len %zu)\n" DEFAULT,
             tests->desc, tests->expected_output, tests->expected_len,
             tests->dest, result_len);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK
             " %s Expected \"%s\" (len %zu), got \"%s\" (len %zu)\n" DEFAULT,
             tests->desc, tests->expected_output, tests->expected_len,
             tests->dest, result_len);
    }
    tests++;
  }
  return (error);
}

int ft_strlcpy_tests(void)
{
  ft_strlcpy_test tests[] = {
      {
          .desc = "ft_strlcpy(dest[10], \"World!\", 10)",
          .dest = {0},
          .src = "World!",
          .size = 10,
          .expected_len = 6,
          .expected_output = "World!",
      },
      {
          .desc = "ft_strlcpy(dest[10], \"Hello, World!\", 10)",
          .dest = {0},
          .src = "Hello, World!",
          .size = 10,
          .expected_len = 13,
          .expected_output = "Hello, Wo",
      },
      {
          .desc = "ft_strlcpy(dest[5], \"Hello, World!\", 5)",
          .dest = {0},
          .src = "Hello, World!",
          .size = 5,
          .expected_len = 13,
          .expected_output = "Hell",
      },
      {
          .desc = "ft_strlcpy(dest[10], \"\", 5)",
          .dest = {0},
          .src = "",
          .size = 5,
          .expected_len = 0,
          .expected_output = "",
      },
      {
          .desc = "ft_strlcpy(dest[1], \"Hello, World!\", 1)",
          .dest = {0},
          .src = "Hello, World!",
          .size = 1,
          .expected_len = 13,
          .expected_output = "",
      },
      {
          .desc = 0,
      },

  };
  return (run_tests(tests));
}
