#include "../include/test.h"
#include "../include/util.h"

typedef struct test
{
  char *desc;
  char *b;
  char *memset_b;
  int c;
  size_t len;
  void *expected_output;
} ft_memset_test;

static int run_tests(ft_memset_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    ft_memset(tests->b, tests->c, tests->len);
    if (memcmp(tests->b, tests->memset_b, tests->len))
    {
      printf(" " RED " %s Expected ", tests->desc);
      print_byte_red(tests->memset_b, tests->len);
      printf("output ");
      print_byte_red(tests->b, tests->len);
      printf("\n");
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected ", tests->desc);
      print_byte_green(tests->memset_b, tests->len);
      printf("output ");
      print_byte_green(tests->b, tests->len);
      printf("\n");
    }
    tests++;
  }
  return error;
}

int ft_memset_tests(void)
{
  char memset_b[10][100] = {
      "a",
      {0, 0, 0, 0},
      {255, -1, -3, 0},
      {255, -1, -3, 0, 'A', 30, -128},
      {0x20, 0x50, 0x30, 0x10, 'A', 0xff, 0b10101101},
  };

  char b[10][100] = {
      "a",
      {0, 0, 0, 0},
      {255, -1, -3, 0},
      {255, -1, -3, 0, 'A', 30, -128},
      {0x20, 0x50, 0x30, 0x10, 'A', 0xff, 0b10101101},
  };

  ft_memset_test tests[] = {
      {
          .desc = "ft_memset(\"a\", 'c', 1)",
          .b = b[0],
          .memset_b = memset_b[0],
          .c = 'c',
          .len = 1,
          .expected_output = memset(memset_b[0], 'c', 1),
      },
      {
          .desc = "ft_memset({0, 0, 0, 0}, 'A', 1)",
          .b = b[1],
          .memset_b = memset_b[1],
          .c = 'A',
          .len = 1,
          .expected_output = memset(memset_b[1], 'A', 1),
      },
      {
          .desc = "ft_memset({255, -1, -3, 0}, -20, 4)",
          .b = b[2],
          .memset_b = memset_b[2],
          .c = -20,
          .len = 4,
          .expected_output = memset(memset_b[2], -20, 4),
      },
      {
          .desc = "ft_memset({255, -1, -3, 0, 'A', 30, -128}, -20, 10)",
          .b = b[3],
          .memset_b = memset_b[3],
          .c = -20,
          .len = 10,
          .expected_output = memset(memset_b[3], -20, 10),
      },
      {
          .desc = "ft_memset({0x20, 0x50, 0x30, 0x10, 'A', 0xff, 0b10101101}, "
                  "0xff, 10)",
          .b = b[4],
          .memset_b = memset_b[4],
          .c = 0xff,
          .len = 10,
          .expected_output = memset(memset_b[4], 0xff, 10),
      },
      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
