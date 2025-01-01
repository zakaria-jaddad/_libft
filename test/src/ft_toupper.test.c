#include "../include/test.h"

typedef struct test
{
  char *desc;
  int c;
  int expected_output;
} ft_toupper_test;

static int run_tests(ft_toupper_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_toupper(tests->c);
    if (result != tests->expected_output)
    {
      printf(" " RED " %s Expected \"%d\" output \"%d\"\n" DEFAULT, tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%d\" output \"%d\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
    }
    tests++;
  }
  return error;
}

int ft_toupper_tests(void)
{
  ft_toupper_test tests[] = {
      {
          .desc = "ft_toupper(\'H\')",
          .c = 'H',
          .expected_output = toupper('H'),
      },
      {
          .desc = "ft_toupper(\'h\')",
          .c = 'h',
          .expected_output = toupper('h'),
      },
      {
          .desc = "ft_toupper(\"1\")",
          .c = '1',
          .expected_output = toupper('1'),
      },
      {
          .desc = "ft_toupper(\"\\0\")",
          .c = 0,
          .expected_output = toupper(0),
      },
      {
          .desc = "ft_toupper(\"\\177\")",
          .c = 177,
          .expected_output = toupper(177),
      },
      {
          .desc = "ft_toupper(123)",
          .c = 123,
          .expected_output = toupper(123),
      },
      {
          .desc = "ft_toupper(-150)",
          .c = -150,
          .expected_output = toupper(-150),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
