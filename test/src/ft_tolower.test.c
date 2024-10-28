#include "../include/test.h"

typedef struct test
{
  char *desc;
  int c;
  int expected_output;
} ft_tolower_test;

static int run_tests(ft_tolower_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_tolower(tests->c);
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

int ft_tolower_tests(void)
{
  ft_tolower_test tests[] = {
      {
          .desc = "ft_tolwer(\'H\')",
          .c = 'H',
          .expected_output = tolower('H'),
      },
      {
          .desc = "ft_tolwer(\'h\')",
          .c = 'h',
          .expected_output = tolower('h'),
      },
      {
          .desc = "ft_tolwer(\"1\")",
          .c = '1',
          .expected_output = tolower('1'),
      },
      {
          .desc = "ft_tolwer(\"\\0\")",
          .c = 0,
          .expected_output = tolower(0),
      },
      {
          .desc = "ft_tolwer(\"\\177\")",
          .c = 177,
          .expected_output = tolower(177),
      },
      {
          .desc = "ft_tolwer(123)",
          .c = 123,
          .expected_output = tolower(123),
      },
      {
          .desc = "ft_tolwer(-150)",
          .c = -150,
          .expected_output = tolower(-150),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
