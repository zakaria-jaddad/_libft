#include "../include/test.h"
#include <string.h>

typedef struct test
{
  char *desc;
  const void *s1;
  const void *s2;
  size_t n;
  int expected_output;
} ft_memcmp_test;

static int run_tests(ft_memcmp_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_memcmp(tests->s1, tests->s2, tests->n);
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

int ft_memcmp_tests(void)
{
  int s1[] = {10, 20};
  double s_double[][2] = {{13.37, 4.2}, {13.37, 4.3}};
  ft_memcmp_test tests[] = {
      {
          .desc = "ft_memcmp(\'Hello, World\', \'Hello, World\', "
                  "strlen(\"Hello, World\"))",
          .s1 = "Hello, World",
          .s2 = "Hello, World",
          .n = strlen("Hello, World"),
          .expected_output =
              memcmp("Hello, World", "Hello, World", strlen("Hello, World")),
      },
      {
          .desc = "ft_memcmp({10, 20}, {10, 20}, sizeof({10 ,20}))",
          .s1 = s1,
          .s2 = s1,
          .n = sizeof(s1),
          .expected_output = memcmp(s1, s1, sizeof(s1)),
      },
      {
          .desc = "ft_memcmp({13.37, 4.2}, {13.37, 4.2}, sizeof({13.37, 4.2}))",
          .s1 = s_double[0],
          .s2 = s_double[0],
          .n = sizeof(s_double[0]),
          .expected_output =
              memcmp(s_double[0], s_double[0], sizeof(s_double[0])),
      },
      {
          .desc = "ft_memcmp({13.37, 4.2}, {13.37, 4.3}, sizeof(double) * 2)",
          .s1 = s_double[0],
          .s2 = s_double[1],
          .n = sizeof(double) * 2,
          .expected_output =
              memcmp(s_double[0], s_double[1], sizeof(double) * 2),
      },
      {
          .desc = "ft_memcmp(\'\', \'\', 0)",
          .s1 = "",
          .s2 = "",
          .n = 0,
          .expected_output = memcmp("", "", 0),
      },
      {
          .desc = "ft_memcmp(\'\', \'\', 10)",
          .s1 = "",
          .s2 = "",
          .n = 10,
          .expected_output = memcmp("", "", 0),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
