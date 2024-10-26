#include "../include/test.h"

typedef struct test
{
  char *desc;
  int s;
  int expected_output;
} ft_isascii_test;

static int run_tests(ft_isascii_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isascii(tests->s);
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

int ft_isascii_tests(void)
{
  ft_isascii_test tests[] = {
      {
          .desc = "ft_isascii(\'A\')",
          .s = 'A',
          .expected_output = isascii('A'),
      },
      {
          .desc = "ft_isascii(0)",
          .s = 0,
          .expected_output = isascii(0),
      },
      {
          .desc = "ft_isascii(\'Z\')",
          .s = 'Z',
          .expected_output = isascii('Z'),
      },
      {
          .desc = "ft_isascii(\'a\')",
          .s = 'a',
          .expected_output = isascii('a'),
      },
      {
          .desc = "ft_isascii(\'z\')",
          .s = 'z',
          .expected_output = isascii('z'),
      },
      {
          .desc = "ft_isascii(127)",
          .s = 127,
          .expected_output = isascii(127),
      },
      {
          .desc = "ft_isascii(400000)",
          .s = 400000,
          .expected_output = isascii(400000),
      },
      {
          .desc = "ft_isascii(-1)",
          .s = -1,
          .expected_output = 0,
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
