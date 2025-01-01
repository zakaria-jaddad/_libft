#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *s1;
  char *s2;
  char *expected_output;
} ft_strjoin_test;

static int run_tests(ft_strjoin_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char *result = ft_strjoin(tests->s1, tests->s2);

    if (strcmp(result, tests->expected_output) != 0)
    {
      printf(" " RED " %s Expected \"%s\", got \"%s\"\n", tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
      printf(" " GREEN CHECKMARK " %s Expected \"%s\", got \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);

    tests++;
    free(result);
  }
  return error;
}

int ft_strjoin_tests(void)
{
  ft_strjoin_test tests[] = {
      {

          .desc = "ft_strjoin(\"\", \"\")",
          .s1 = "",
          .s2 = "",
          .expected_output = "",
      },
      {
          .desc = "ft_strjoin(\"Hello\", \"\")",
          .s1 = "Hello",
          .s2 = "",
          .expected_output = "Hello",
      },
      {
          .desc = "ft_strjoin(\"Hello\", \" World\")",
          .s1 = "Hello",
          .s2 = " World",
          .expected_output = "Hello World",
      },
      {
          .desc = "ft_strjoin(\"\", \"World\")",
          .s1 = "",
          .s2 = "World",
          .expected_output = "World",
      },
      {
          .desc = "ft_strjoin(\"Hello\", \"World\")",
          .s1 = "Hello",
          .s2 = "World",
          .expected_output = "HelloWorld",
      },
      {
          .desc = 0,
      },
  };

  return run_tests(tests);
}
