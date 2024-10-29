#include "../include/test.h"
#include <string.h>

typedef struct test
{
  char *desc;
  char *s;
  unsigned int start;
  size_t len;
  char *expected_output;
} ft_calloc_test;

static int run_tests(ft_calloc_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char *result = ft_substr(tests->s, tests->start, tests->len);
    if (strcmp(tests->expected_output, result))
    {
      printf(" " RED " %s Expected \"%s\" output \"%s\"\n" DEFAULT, tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);
    }

    free(result);
    tests++;
  }
  return (error);
}

int ft_substr_tests(void)
{
  ft_calloc_test tests[] = {
      {
          .desc = "ft_substr(\"Bonjour comment ca va?\", 5, 8)",
          .s = "Bonjour comment ca va?",
          .start = 5,
          .len = 8,
          .expected_output = "ur comme",
      },
      {
          .desc =
              "ft_substr(\"Bonjour comment ca va ara chi bouyssa?\", 0, 42000)",
          .s = "Bonjour comment ca va ara chi bouyssa?",
          .start = 0,
          .len = 42000,
          .expected_output = "Bonjour comment ca va ara chi bouyssa?",
      },
      {
          .desc = "ft_substr(\"alo\", 1, 1)",
          .s = "alo",
          .start = 1,
          .len = 1,
          .expected_output = "l",
      },
      {
          .desc = "ft_substr(\"alo\", 0, 0)",
          .s = "alo",
          .start = 0,
          .len = 0,
          .expected_output = "",
      },
      {
          .desc = "ft_substr(\"alo\", 1, 0)",
          .s = "alo",
          .start = 1,
          .len = 0,
          .expected_output = "",
      },
      {
          .desc = "ft_substr(\"alo\", 0, 1)",
          .s = "alo",
          .start = 0,
          .len = 1,
          .expected_output = "a",
      },
      {
          .desc = "ft_substr(\"hello\", 100, 1)",
          .s = "hello",
          .start = 100,
          .len = 1,
          .expected_output = "",
      },
      {
          .desc = 0,
      },
  };

  return (run_tests(tests));
}
