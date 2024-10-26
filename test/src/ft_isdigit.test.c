#include "../include/test.h"

typedef struct test
{
  char *desc;
  int c;
  int expected_output;
} ft_isdigit_test;

static int run_tests(ft_isdigit_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_isdigit(tests->c);
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

int ft_isdigit_tests(void)
{
  ft_isdigit_test tests[] = {
      {
          .desc = "ft_isdigit('0')",
          .c = '0',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('1')",
          .c = '1',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('2')",
          .c = '2',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('3')",
          .c = '4',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('4')",
          .c = '4',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('5')",
          .c = '5',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('6')",
          .c = '6',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('7')",
          .c = '7',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('8')",
          .c = '8',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('9')",
          .c = '9',
          .expected_output = 1,
      },
      {
          .desc = "ft_isdigit('\\0')",
          .c = '\0',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit('A')",
          .c = 'A',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit('~')",
          .c = '~',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit('*')",
          .c = '*',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit(4000)",
          .c = 4000,
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit('\\n')",
          .c = '\n',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit('\\t')",
          .c = '\t',
          .expected_output = 0,
      },
      {
          .desc = "ft_isdigit(-1)",
          .c = -1,
          .expected_output = 0,
      },
      {
          .desc = 0,
      },
  };
  run_tests(tests);
  return 0;
}
