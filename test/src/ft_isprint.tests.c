#include "../include/test.h"

typedef struct test
{
  char *desc;
  int s;
  int expected_output;
} ft_isprint_test;

static int run_tests(ft_isprint_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isprint(tests->s);
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

int ft_isprint_tests(void)
{
  ft_isprint_test tests[] = {
      {
          .desc = "ft_isprint(\'A\')",
          .s = 'A',
          .expected_output = isprint('A'),
      },
      {
          .desc = "ft_isprint(\' \')",
          .s = ' ',
          .expected_output = isprint(' '),
      },
      {
          .desc = "ft_isprint(\'\\n\')",
          .s = '\n',
          .expected_output = isprint('\n'),
      },
      {
          .desc = "ft_isprint(\'0\')",
          .s = '0',
          .expected_output = isprint('0'),
      },
      {
          .desc = "ft_isprint(0)",
          .s = 0,
          .expected_output = isprint(0),
      },
      {
          .desc = "ft_isprint(-1)",
          .s = -1,
          .expected_output = isprint(-1),
      },
      {
          .desc = "ft_isprint(177)",
          .s = 177,
          .expected_output = isprint(177),
      },
      {
          .desc = "ft_isprint(40000)",
          .s = 40000,
          .expected_output = isprint(40000),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
