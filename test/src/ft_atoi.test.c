#include "../include/test.h"
#include <i386/limits.h>
#include <stdlib.h>

typedef struct test
{
  char *desc;
  const char *s;
  int expected_output;
} ft_atoi_test;

static int run_tests(ft_atoi_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_atoi(tests->s);
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

int ft_atoi_tests(void)
{
  ft_atoi_test tests[] = {
      {
          .desc = "ft_atoi(\"2147483647\")",
          .s = "2147483647",
          .expected_output = atoi("2147483647"),
      },
      {
          .desc = "ft_atoi(\"-2147483648\")",
          .s = "-2147483648",
          .expected_output = atoi("-2147483648"),
      },
      {
          .desc = "ft_atoi(\"-2147483648\")",
          .s = "2147483648",
          .expected_output = atoi("-2147483648"),
      },
      {
          .desc = "ft_atoi(\"2147483647\")",
          .s = "-2147483649",
          .expected_output = atoi("2147483647"),
      },
      {
          .desc = "ftatoi(\"-\")",
          .s = "-",
          .expected_output = atoi("-"),
      },
      {
          .desc = "ft_atoi(\"12 34\")",
          .s = "12 34",
          .expected_output = atoi("12 34"),
      },
      {
          .desc = "atoi(\"   -12 34\")",
          .s = "   -12 34",
          .expected_output = atoi("   -12 34"),
      },
      {
          .desc = "ft_atoi(\"abc123\")",
          .s = "abc123",
          .expected_output = atoi("abc123"),
      },
      {
          .desc = "atoi(\"123abc+\")",
          .s = "123abc+",
          .expected_output = atoi("123abc+"),
      },
      {
          .desc = "ft_atoi(\"   - 0000\")",
          .s = "   - 0000",
          .expected_output = atoi("   - 0000"),
      },
      {
          .desc = "ft_atoi(\"--123\")",
          .s = "--123",
          .expected_output = atoi("--123"),
      },
      {
          .desc = "ft_atoi(\"++123\")",
          .s = "++123",
          .expected_output = atoi("++123"),
      },
      {
          .desc = "ft_atoi(\"+-123\")",
          .s = "+-123",
          .expected_output = atoi("+-123"),
      },
      {
          .desc = "ft_atoi(\"18446744073709551615\")",
          .s = "18446744073709551615",
          .expected_output = atoi("18446744073709551615"),
      },
      {
          .desc = "ft_atoi(\"1844674407370955161\")",
          .s = "1844674407370955161",
          .expected_output = atoi("1844674407370955161"),
      },
      {
          .desc =
              "ft_atoi("
              "\"18446744073709551615000000000000000000000000000000000000\")",
          .s = "18446744073709551615000000000000000000000000000000000000",
          .expected_output =
              atoi("18446744073709551615000000000000000000000000000000000000"),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
