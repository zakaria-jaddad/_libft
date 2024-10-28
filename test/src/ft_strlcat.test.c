#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *src;
  char *dest;
  int size;
  char *expected_output;
} ft_strlcat_test;

static int run_tests(ft_strlcat_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char dest[strlen(tests->dest) + 1];
    strcpy(dest, tests->dest);

    ft_strlcat(dest, tests->src, tests->size);

    if (strcmp(dest, tests->expected_output) != 0)
    {
      printf(" " RED " %s Expected \"%s\" output \"%s\"\n" DEFAULT, tests->desc,
             tests->expected_output, dest);
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, dest);
    }
    tests++;
  }
  return error;
}

int ft_strlcat_tests(void)
{
  ft_strlcat_test tests[] = {
      {
          .desc = "ft_strlcat(\"1337 42\", \"Born to code\", 20)",
          .src = "Born to code",
          .dest = "1337 42",
          .size = 20,
          .expected_output = "1337 42Born to code",
      },
      {
          .desc = "ft_strlcat(\"\", \"\", 10)",
          .src = "",
          .dest = "",
          .size = 10,
          .expected_output = "",
      },
      {
          .desc = "ft_strlcat(\"\", \"hello\", 10)",
          .src = "hello",
          .dest = "",
          .size = 10,
          .expected_output = "hello",
      },
      {
          .desc = "ft_strlcat(\"1337 42\", \"Born to code\", 7)",
          .src = "Born to code",
          .dest = "1337 42",
          .size = 7,
          .expected_output = "1337 42",
      },
      {
          .desc = "ft_strlcat(\"Test\", \"Test\", 10)",
          .src = "Test",
          .dest = "Test",
          .size = 10,
          .expected_output = "TestTest",
      },
      {
          .desc = 0,
      },
  };

  return run_tests(tests);
}
