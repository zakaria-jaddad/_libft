#include "../include/test.h"
#include <string.h>

typedef struct test
{
  char *desc;
  char *s;
  size_t expected_output;
} ft_strlen_test;

static int run_tests(ft_strlen_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    size_t result = ft_strlen(tests->s);
    if (result != tests->expected_output)
    {
      printf(" " RED " %s Expected \"%zu\" output \"%zu\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK
             " %s Expected \"%zu\" output \"%zu\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
    }
    tests++;
  }
  return error;
}

int ft_strlen_tests(void)
{
  ft_strlen_test tests[] = {
      {
          .desc = "ft_strlen(\"Hello, world\\n\")",
          .s = "Hello, world\n",
          .expected_output = strlen("Hello, world\n"),
      },
      {
          .desc = "ft_strlen(\"\")",
          .s = "",
          .expected_output = strlen(""),
      },
      {
          .desc = "ft_strlen(\"\\0\")",
          .s = "\0",
          .expected_output = strlen("\0"),
      },
      {
          .desc = "ft_strlen(\"\\177\")",
          .s = "\177",
          .expected_output = strlen("\177"),
      },
      {
          .desc = "ft_strlen(\"123\")",
          .s = "123",
          .expected_output = strlen("123"),
      },

      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
