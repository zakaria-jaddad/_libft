#include "../include/test.h"
#include <string.h>

typedef struct test
{
  char *desc;
  int c;
  char *expected_output;
} ft_itoa_test;

static int run_tests(ft_itoa_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    char *result = ft_itoa(tests->c);
    if (strcmp(result, tests->expected_output))
    {
      printf(" " RED " %s Expected \"%s\" output \"%s\"\n" DEFAULT, tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
    }
    tests++;
  }
  return error;
}

int ft_itoa_tests(void)
{
  ft_itoa_test tests[] = {
      {
          .desc = "ft_itoa(50)",
          .c = 50,
          .expected_output = "50",
      },
      {
          .desc = "ft_itoa(-2147483648)",
          .c = -2147483648,
          .expected_output = "-2147483648",
      },
      {
          .desc = "ft_itoa(0)",
          .c = 0,
          .expected_output = "0",
      },
      {
          .desc = "ft_itoa(2147483647)",
          .c = 2147483647,
          .expected_output = "2147483647",
      },
      {
          .desc = "ft_itoa(500)",
          .c = 500,
          .expected_output = "500",
      },
      {
          .desc = "ft_itoa(-500)",
          .c = -500,
          .expected_output = "-500",
      },
      {
          .desc = "ft_itoa(-0)",
          .c = -0,
          .expected_output = "0",
      },
      {
          .desc = "ft_itoa(-1)",
          .c = -1,
          .expected_output = "-1",
      },
      {
          .desc = "ft_itoa(1)",
          .c = 1,
          .expected_output = "1",
      },

      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
