#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *s;
  int c;
  char *expected_output;
} ft_strchr_test;

static int run_tests(ft_strchr_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    char *result = ft_strchr(tests->s, tests->c);
    if (result == NULL && tests->expected_output == NULL)
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
      tests++;
      continue;
    }
    else
    {
      if (strcmp(result, tests->expected_output) != 0)
      {
        printf(" " RED " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
               tests->desc, tests->expected_output, result);
        error++;
      }
      else
      {
        printf(" " GREEN CHECKMARK
               " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
               tests->desc, tests->expected_output, result);
      }
    }
    tests++;
  }
  return error;
}

int ft_strchr_tests(void)
{
  ft_strchr_test tests[] = {
      {
          .desc = "ft_strchr(\'Hello, World\')",
          .s = "Hello, World",
          .c = 'H',
          .expected_output = strchr("Hello, World", 'H'),
      },
      {
          .desc = "ft_strchr(\"1337 42\", '7')",
          .s = "1337 42",
          .c = '7',
          .expected_output = strchr("1337 42", '7'),
      },
      {
          .desc = "fe_strchr(\"hello, world\", 0)",
          .s = "Hello, World",
          .c = 0,
          .expected_output = strchr("hello, world", 0),
      },
      {
          .desc = "ft_strchr(\"\", \'h\')",
          .s = "",
          .c = 'h',
          .expected_output = strchr("", 'h'),
      },
      {
          .desc = "ft_strchr(\"\", 0)",
          .s = "",
          .c = 0,
          .expected_output = strchr("", 0),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
