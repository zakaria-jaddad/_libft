#include "../include/test.h"

typedef struct test
{
  char *desc;
  int c;
  int expected_output;
} ft_isprint_test;

static int run_tests(ft_isprint_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isprint(tests->c);
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
          .c = 'A',
          .expected_output = isprint('A'),
      },
      {
          .desc = "ft_isprint(\' \')",
          .c = ' ',
          .expected_output = isprint(' '),
      },
      {
          .desc = "ft_isprint(\'\\n\')",
          .c = '\n',
          .expected_output = isprint('\n'),
      },
      {
          .desc = "ft_isprint(\'0\')",
          .c = '0',
          .expected_output = isprint('0'),
      },
      {
          .desc = "ft_isprint(0)",
          .c = 0,
          .expected_output = isprint(0),
      },
      {
          .desc = "ft_isprint(-1)",
          .c = -1,
          .expected_output = isprint(-1),
      },
      {
          .desc = "ft_isprint(177)",
          .c = 177,
          .expected_output = isprint(177),
      },
      {
          .desc = "ft_isalpha(-150)",
          .c = -150,
          .expected_output = 0,
      },
      {
          .desc = "ft_isprint(40000)",
          .c = 40000,
          .expected_output = isprint(40000),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
