#include "../include/test.h"

typedef struct test
{
  char *desc;
  int s;
  int expected_output;
} ft_isalnum_test;

static int run_tests(ft_isalnum_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isalnum(tests->s);
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

/* character set '0' -> '9', 'a' -> 'z' and 'A' -> 'Z'.   */

int ft_isalnum_tests(void)
{
  ft_isalnum_test tests[] = {
      {
          .desc = "ft_isalnum(\'A\')",
          .s = 'A',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalnum(\'Z\')",
          .s = 'Z',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalnum(\'a\')",
          .s = 'a',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalnum(\'z\')",
          .s = 'z',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalnum(\'0\')",
          .s = '0',
          .expected_output = 1,
      },
      {
          .desc = "ft_isalnum(0)",
          .s = 0,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalnum(200)",
          .s = 200,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalpha(-150)",
          .s = -150,
          .expected_output = 0,
      },
      {
          .desc = "ft_isalnum(-1)",
          .s = -1,
          .expected_output = 0,
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
