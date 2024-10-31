#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *s;
  int c;
  char *expected_output;
} ft_strrchr_test;

static int run_tests(ft_strrchr_test *tests)
{
  int error = 0;
  while (tests->desc)
  {

    char *result = ft_strrchr(tests->s, tests->c);
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

int ft_strrchr_tests(void)
{
  ft_strrchr_test tests[] = {
      {
          .desc = "ft_strrchr(\'Bonjour\', 'B')",
          .s = "Bonjour",
          .c = 'B',
          .expected_output = strrchr("Bonjour", 'B'),
      },
      {
          .desc = "ft_strrchr(\'Bonjour\', 's')",
          .s = "Bonjour",
          .c = 's',
          .expected_output = strrchr("Bonjour", 's'),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
