#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *src;
  char *expected_output;
} ft_strdup_test;

static int run_tests(ft_strdup_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char *result = ft_strdup(tests->src);

    if (tests->src == NULL && result != NULL)
    {
      printf(" " RED " %s Expected NULL, got \"%s\"\n" DEFAULT, tests->desc,
             result);
      error++;
    }
    else if (tests->src == NULL && result == NULL)
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%s\", got \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
    }
    else if (strcmp(result, tests->expected_output) != 0)
    {
      printf(" " RED " %s Expected \"%s\", got \"%s\"\n" DEFAULT, tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
      printf(" " GREEN CHECKMARK " %s Expected \"%s\", got \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);

    free(result);
    tests++;
  }
  return (error);
}

int ft_strdup_tests(void)
{
  ft_strdup_test tests[] = {
      {
          .desc = "ft_strdup(\"\")",
          .src = "",
          .expected_output = strdup(""),
      },
      {
          .desc = "ft_strdup(\"test\")",
          .src = "test",
          .expected_output = strdup("test"),
      },
      {
          .desc = "ft_strdup("
                  "\"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456"
                  "7890!@#$%^&*()\")",
          .src = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"
                 "0!@#$%^&*()",

          .expected_output =
              strdup("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVW"
                     "XYZ1234567890!@#$%^&*()"),
      },
      {
          .desc = "ft_strdup(\"test\\0tesut\")",
          .src = "test\0test",
          .expected_output = strdup("test\0test"),
      },
      {
          .desc = 0,
      }};

  return (run_tests(tests));
}
