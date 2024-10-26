#include "../include/test.h"
#include "../include/util.h"

typedef struct test
{
  char *desc;
  char *b;
  char *bzero_b;
  size_t n;
  unsigned char *expected_output;
} ft_bzero_test;

static int run_tests(ft_bzero_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    ft_bzero(tests->b, tests->n);
    if (memcmp(tests->b, tests->bzero_b, tests->n))
    {
      printf(" " RED " %s Expected ", tests->desc);
      print_byte_red(tests->bzero_b, tests->n);
      printf("output ");
      print_byte_red(tests->b, tests->n);
      printf("\n");
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected ", tests->desc);
      print_byte_green(tests->bzero_b, tests->n);
      printf("output ");
      print_byte_green(tests->b, tests->n);
      printf("\n");
    }
    tests++;
  }
  return error;
}

int ft_bzero_tests(void)
{
  char bzero_b[10][100] = {
      "a",
      {0, 0, 0, 0},
      {255, -1, -3, 0},
      {255, -1, -3, 0, 'A', 30, -128},
  };

  char b[10][100] = {
      "a",
      {0, 0, 0, 0},
      {255, -1, -3, 0},
      {255, -1, -3, 0, 'A', 30, -128},
  };
  ft_bzero_test tests[] = {
      {
          .desc = "ft_bzero(\"a\", 1)",
          .b = b[0],
          .bzero_b = bzero_b[0],
          .n = 1,
          .expected_output = bzero(bzero_b[0], 1),
      },
      {
          .desc = "ft_bzero({0, 0, 0, 0}, 1)",
          .b = b[1],
          .bzero_b = bzero_b[1],
          .n = 1,
          .expected_output = bzero(bzero_b[1], 1),
      },
      {
          .desc = "ft_bzero({255, -1, -3, 0}, 4)",
          .b = b[2],
          .bzero_b = bzero_b[2],
          .n = 4,
          .expected_output = bzero(bzero_b[2], 4),
      },
      {
          .desc = "ft_bzero({255, -1, -3, 0, 'A', 30, -128}, 10)",
          .b = b[3],
          .bzero_b = bzero_b[3],
          .n = 10,
          .expected_output = bzero(bzero_b[3], 10),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
