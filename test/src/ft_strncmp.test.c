#include "../include/test.h"
#include <string.h>

typedef struct test
{
  char *desc;
  char *s1;
  char *s2;
  size_t n;
  int expected_output;
} ft_strncmp_test;

static int run_tests(ft_strncmp_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    int result = ft_strncmp(tests->s1, tests->s2, tests->n);

    if ((result < 0 && tests->expected_output >= 0) ||
        (result > 0 && tests->expected_output <= 0) ||
        (result == 0 && tests->expected_output != 0))
    {
      printf(RED " %s: expected %s, got %d\n" DEFAULT, tests->desc,
             (tests->expected_output < 0
                  ? "negative value"
                  : (tests->expected_output > 0 ? "positive value" : "0")),
             result);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s: expected %s, got %d\n" DEFAULT,
             tests->desc,
             (tests->expected_output < 0
                  ? "negative value"
                  : (tests->expected_output > 0 ? "positive value" : "0")),
             result);
    }
    tests++;
  }
  return error;
}

int ft_strncmp_tests(void)
{
  ft_strncmp_test tests[] = {
      {
          .desc = "strncmp(\"\", \"\", 1)",
          .s1 = "",
          .s2 = "",
          .n = 1,
          .expected_output = strncmp("", "", 1),
      },
      {
          .desc = "strncmp(\"Hello\", \"\", 3)",
          .s1 = "Hello",
          .s2 = "",
          .n = 3,
          .expected_output = strncmp("Hello", "", 3),
      },
      {
          .desc = "Comparing empty string with non-empty string",
          .s1 = "",
          .s2 = "World",
          .n = 4,
          .expected_output = -87,
      },
      {
          .desc = "Comparing same string with n = 0",
          .s1 = "Hello",
          .s2 = "Hello",
          .n = 0,
          .expected_output = 0,
      },
      {
          .desc = "strncmp(\"Hello\",\"hELLO\", 3)",
          .s1 = "Hello",
          .s2 = "hELLO",
          .n = 3,
          .expected_output = strncmp("Hello", "hELLO", 3),
      },
      {
          .desc = "Comparing strings with different character case",
          .s1 = "Hello",
          .s2 = "hELLO",
          .n = 4,
          .expected_output = -32,
      },
      {
          .desc = "Comparing strings with different character case",
          .s1 = "Hello",
          .s2 = "hELLO",
          .n = 5,
          .expected_output = -32,
      },
      {
          .desc = "Comparing same string with n > length of string",
          .s1 = "Hello",
          .s2 = "Hello",
          .n = 6,
          .expected_output = 0,
      },
      {
          .desc = "Comparing different string with n > length of string",
          .s1 = "Hello",
          .s2 = "World",
          .n = 6,
          .expected_output = -15,
      },
      {
          .desc = "Comparing different string with n > length of both strings",
          .s1 = "Hello",
          .s2 = "World",
          .n = 10,
          .expected_output = -15,
      },
      {
          .desc = "Comparing strings where n is smaller than s1",
          .s1 = "Hello",
          .s2 = "World",
          .n = 3,
          .expected_output = -15,
      },
      {
          .desc = "Comparing strings where n is smaller than s2",
          .s1 = "Hello",
          .s2 = "World",
          .n = 2,
          .expected_output = -1,
      },
      {
          .desc = "Comparing empty strings with n smaller than 1",
          .s1 = "",
          .s2 = "",
          .n = 0,
          .expected_output = 0,
      },
      {
          .desc = "Comparing empty string and non-empty string with n smaller "
                  "than 1",
          .s1 = "",
          .s2 = "Hello",
          .n = 0,
          .expected_output = 0,
      },
      {
          .desc = "Comparing non-empty string and empty string with n smaller "
                  "than 1",
          .s1 = "Hello",
          .s2 = "",
          .n = 0,
          .expected_output = 0,
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"Hello\", 0)",
          .s1 = "Hello",
          .s2 = "Hello",
          .n = 0,
          .expected_output = strncmp("Hello", "Hello", 0),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"World\", 0)",
          .s1 = "Hello",
          .s2 = "World",
          .n = 0,
          .expected_output = strncmp("Hello", "World", 0),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"Hello\", 10)",
          .s1 = "Hello",
          .s2 = "Hello",
          .n = 10,
          .expected_output = strncmp("Hello", "Hello", 10),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"World\", 10)",
          .s1 = "Hello",
          .s2 = "World",
          .n = 10,
          .expected_output = strncmp("Hello", "World", 10),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"WorldHello\", 2)",
          .s1 = "Hello",
          .s2 = "WorldHello",
          .n = 2,
          .expected_output = strncmp("Hello", "WorldHello", 2),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"WorldHello\", 5)",
          .s1 = "Hello",
          .s2 = "WorldHello",
          .n = 5,
          .expected_output = strncmp("Hello", "WorldHello", 5),
      },
      {
          .desc = "ft_strncmp(\"\", \"Hello\", 5)",
          .s1 = "",
          .s2 = "Hello",
          .n = 5,
          .expected_output = strncmp("", "Hello", 5),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"\", 5)",
          .s1 = "Hello",
          .s2 = "",
          .n = 5,
          .expected_output = strncmp("Hello", "", 5),
      },
      {
          .desc = "ft_strncmp(\"Hello\", \"Hellz\", 4)",
          .s1 = "Hello",
          .s2 = "Hellz",
          .n = 4,
          .expected_output = strncmp("Hello", "Hellz", 4),
      },
      {
          .desc = "ft_strncmp(\"test\\200\", \"test\\0\", 6)",
          .s1 = "test\200",
          .s2 = "test\0",
          .n = 6,
          .expected_output = ft_strncmp("test\200", "test\0", 6),
      },
      {
          .desc = 0,
      }};

  return run_tests(tests);
}
