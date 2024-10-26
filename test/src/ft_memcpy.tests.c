#include "../include/test.h"
#include "../include/util.h"
#include <stdio.h>

typedef struct test
{
  char *desc;
  const char *src;
  char *dst;
  const char *memcpy_src;
  char *memcpy_dst;
  size_t n;
  void *expected_output;
} ft_memmove_test;

static int run_tests(ft_memmove_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    ft_memcpy(tests->dst, tests->src, tests->n);
    if (memcmp(tests->memcpy_dst, tests->dst, tests->n))
    {
      printf(" " RED " %s Expected ", tests->desc);
      print_byte_red(tests->memcpy_dst, tests->n);
      printf(" output ");
      print_byte_red(tests->dst, tests->n);
      printf("\n");
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected ", tests->desc);
      print_byte_green(tests->memcpy_dst, tests->n);
      printf("output ");
      print_byte_green(tests->dst, tests->n);
      printf("\n");
    }
    tests++;
  }
  return error;
}

int ft_memcpy_tests(void)
{
  char src[10][100] = {
      "abce\xff", {0, 0, 0, 0}, "hello, World", {255, 'b', 3, 0, 'A', 30, 128},
      "",
  };
  char dst[10][100] = {};

  char memcpy_src[10][100] = {
      "abce\xff", {0, 0, 0, 0}, "hello, World", {255, 'b', 3, 0, 'A', 30, 128},
      "",
  };
  char memspy_dst[10][100] = {};

  ft_memmove_test tests_no_overlp[] = {
      {
          .desc = "ft_memcpy(\"abce\xff\", \"\", 10)",
          .src = src[0],
          .dst = dst[0],
          .n = 10,
          .memcpy_src = memcpy_src[0],
          .memcpy_dst = memspy_dst[0],
          .expected_output = memcpy(memspy_dst[0], memcpy_src[0], 10),
      },
      {
          .desc = "ft_memcpy({0, 0, 0, 0}, {0, 0, 0, 0}, 4)",
          .src = src[1],
          .dst = dst[1],
          .memcpy_src = memcpy_src[1],
          .memcpy_dst = memspy_dst[1],
          .n = 4,
          .expected_output = memcpy(memspy_dst[1], memcpy_src[1], 4),
      },
      {
          .desc = "ft_memcpy(\"\", \"\", 1)",
          .src = src[4],
          .dst = dst[4],
          .memcpy_src = memcpy_src[4],
          .memcpy_dst = memspy_dst[4],
          .n = 1,
          .expected_output = memcpy(memspy_dst[4], memcpy_src[4], 1),
      },
      {
          .desc = 0,
      },
  };

  return run_tests(tests_no_overlp);
}
