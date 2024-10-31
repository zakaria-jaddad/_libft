#include "../include/test.h"
#include <stdio.h>
#include <string.h>

typedef struct test
{
  char *desc;
  char *s;
  int s_len;
  int c;
  char **expected_output;
} ft_split_test;

static int run_tests(ft_split_test *tests)
{
  int error = 0;
  int i;

  while (tests->desc)
  {
    int test = 0;
    char **result = ft_split(tests->s, tests->c);
    if (result == NULL || tests->expected_output == NULL)
    {
      if (tests->expected_output == NULL && result == NULL)
      {
        printf(" " GREEN CHECKMARK " %s Expected \"%s\" got \"%s\"\n",
               tests->desc, NULL, NULL);
      }
      else if (tests->expected_output != NULL && result == NULL)
      {
        printf(" " RED " %s Expected \"%s\" got ", tests->desc, NULL);
        for (i = 0; i < tests->s_len; i++)
          printf("\"%s\" ", result[i]);
        printf("\n");
        error++;
      }
      else
      {
        printf(" " RED " %s Expected ", tests->desc);
        for (i = 0; i < tests->s_len; i++)
          printf("\"%s\" ", tests->expected_output[i]);
        printf(" got ");
        for (i = 0; i < tests->s_len; i++)
          printf("\"%s\" ", result[i]);
        printf("\n");
        error++;
      }
      tests++;
      continue;
    }
    for (i = 0; i < tests->s_len - 1; i++)
    {
      if (strcmp(tests->expected_output[i], result[i]) != 0)
        test++;
    }
    if (result[i] != 0)
      test++;
    if (test)
    {
      printf(" " RED " %s Expected ", tests->desc);
      for (i = 0; i < tests->s_len; i++)
        printf("\"%s\" ", tests->expected_output[i]);
      printf(" got ");
      for (i = 0; i < tests->s_len; i++)
        printf("\"%s\" ", result[i]);
      printf("\n");
      error++;
    }
    else
    {
      printf(" " GREEN CHECKMARK " %s Expected ", tests->desc);
      for (i = 0; i < tests->s_len; i++)
        printf("\"%s\" ", tests->expected_output[i]);
      printf(" got ");
      for (i = 0; i < tests->s_len; i++)
        printf("\"%s\" ", result[i]);
      printf("\n");
    }

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
          .s_len = 3,
          .expected_output = (char *[3]) {"hello", "world", 0},
      },
      {
          .desc = "ft_split(\"\", 0)",
          .s = "",
          .c = 0,
          .s_len = 1,
          .expected_output = (char *[1]) {0},
      },
      {
          .desc = "ft_split(\"hello\", 0)",
          .s = "hello",
          .c = 0,
          .s_len = 2,
          .expected_output = (char *[2]) {"hello", 0},
      },
      {
          .desc = "ft_split(NULL, ' ')",
          .s = NULL,
          .c = ' ',
          .s_len = 0,
          .expected_output = NULL,
      },
      {
          .desc = "ft_split(\"Yaaaaaa splitini ablabalo\", 'a')",
          .s = "Yaaaaaa splitini ablabalo",
          .c = 'a',
          .s_len = 6,
          .expected_output =
              (char *[6]) {"Y", " splitini ", "bl", "b", "lo", 0},
      },
      {
          .desc = 0,
      },
  };

  return run_tests(tests);
}
