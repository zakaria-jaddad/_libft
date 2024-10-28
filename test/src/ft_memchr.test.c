#include "../include/test.h"

typedef struct test
{
  char *desc;
  const char *s;
  int c;
  size_t n;
  char *expected_output;
} ft_memchr_test;

static int run_tests(ft_memchr_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    char *result = ft_memchr(tests->s, tests->c, tests->n);
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

int ft_memchr_tests(void)
{
  ft_memchr_test tests[] = {
      {
          .desc = "ft_memchr(\'Hello, World\', 'H', 0)",
          .s = "Hello, World",
          .c = 'H',
          .n = 0,
          .expected_output = memchr("Hello, World", 'H', 0),
      },
      {
          .desc = "ft_memchr(\'Hello, World\', 'H', 1)",
          .s = "Hello, World",
          .c = 'H',
          .n = 1,
          .expected_output = memchr("Hello, World", 'H', 1),
      },
      {
          .desc = "ft_memchr(\"1337 42\", '7', strlen(\"1337 42\"))",
          .s = "1337 42",
          .c = '7',
          .n = strlen("1337 42"),
          .expected_output = memchr("1337 42", '7', strlen("1337 42")),
      },
      {
          .desc = "ft_memchr(\"hello, world\", 0, strlen(\"Hello, World\"))",
          .s = "Hello, World",
          .c = 0,
          .n = strlen("Hello, World"),
          .expected_output = memchr("hello, world", 0, strlen("Hello, World")),
      },
      {
          .desc = "ft_memchr(\"hello, world\", 0, 0)",
          .s = "Hello, World",
          .c = 0,
          .n = 0,
          .expected_output = memchr("hello, world", 0, 0),
      },
      {
          .desc = "ft_memchr(\"\", \'h\', 10)",
          .s = "",
          .c = 'h',
          .n = 1,
          .expected_output = memchr("", 'h', 1),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
