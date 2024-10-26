#include "../include/test.h"

typedef struct test
{
  char *desc;
  int s;
  int expected_output;
} ft_isalpha_test;

static int run_tests(ft_isalpha_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isalpha(tests->s);
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

int ft_isalpha_tests(void)
{
  ft_isalpha_test tests[] = {
      {
          .desc = "ft_isalpha(\'A\')",
          .s = 'A',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalpha(\'Z\')",
          .s = 'Z',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalpha('W')",
          .s = 'W',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalpha('w')",
          .s = 'w',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalpha(\'a\')",
          .s = 'a',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalpha(0)",
          .s = 0,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalpha(200)",
          .s = 200,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalpha(127)",
          .s = 127,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalpha(4000)",
          .s = 4000,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalpha(-1)",
          .s = -1,
          .expected_output = 0,
      },
      {
          .desc = 0,
      },
  };
  run_tests(tests);
  return 0;
}
