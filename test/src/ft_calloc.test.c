#include "../include/test.h"
#include "../include/util.h"
#include <limits.h>

typedef struct test
{
  char *desc;
  size_t count;
  size_t size;
  char *expected_output;
} ft_calloc_test;

static int run_tests(ft_calloc_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    int len = tests->size * tests->count;
    char *result = ft_calloc(tests->size, tests->count);
    if (result == NULL)
    {
      if (tests->expected_output == NULL)
      {
        printf(" " GREEN CHECKMARK
               " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
               tests->desc, tests->expected_output, result);
      }
      else
      {
        printf(" " RED " %s Expected \"%s\" output \"%s\"\n" DEFAULT,
               tests->desc, tests->expected_output, result);
      }
    }
    else
    {
      if (memcmp(tests->expected_output, result, len))
      {
        printf(" " RED " %s Expected ", tests->desc);
        print_byte_red(tests->expected_output, len);
        printf(" output ");
        print_byte_red(result, len);
        printf("\n");
        error++;
      }
      else
      {
        printf(" " GREEN CHECKMARK " %s Expected ", tests->desc);
        print_byte_green(tests->expected_output, len);
        printf("output ");
        print_byte_green(result, len);
        printf("\n");
      }
    }
    free(result);
    tests++;
  }
  return (error);
}

int ft_calloc_tests(void)
{
  ft_calloc_test tests[] = {
      {
          .desc = "ft_calloc(sizeof(int), 3)",
          .size = sizeof(int),
          .count = 3,
          .expected_output = calloc(sizeof(int), 3),
      },
      {
          .desc = "ft_calloc(sizeof(double), 3)",
          .size = sizeof(double),
          .count = 2,
          .expected_output = calloc(sizeof(double), 2),
      },
      {
          .desc = 0,
      },
  };

  return (run_tests(tests));
}
