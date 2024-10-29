#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *s;
  int c;
  char **expected_output;
} ft_split_test;

static int run_tests(ft_split_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char **result = ft_split(tests->s, tests->c);
    tests++;
  }

  return (error);
}

int ft_split_tests(void)
{
  ft_split_test tests[] = {
      {
          .desc = "ft_split(\",,hello,world,,\", \',\')",
          .s = ",,hello,world,,",
          .c = ',',
          .expected_output = (char *[3]) {"hello", "world", 0},
      },
      {
          .desc = 0,
      },
  };

  return run_tests(tests);
}
