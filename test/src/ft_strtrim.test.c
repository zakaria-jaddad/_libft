#include "../include/test.h"

typedef struct test
{
  char *desc;
  char *s1;
  char *set;
  char *expected_output;
} ft_strtrim_test;

static int run_tests(ft_strtrim_test *tests)
{
  int error = 0;

  while (tests->desc)
  {
    char *result = ft_strtrim(tests->s1, tests->set);

    if (strcmp(result, tests->expected_output) != 0)
    {
      printf(" " RED " %s Expected \"%s\", got \"%s\"\n", tests->desc,
             tests->expected_output, result);
      error++;
    }
    else
      printf(" " GREEN CHECKMARK " %s Expected \"%s\", got \"%s\"\n" DEFAULT,
             tests->desc, tests->expected_output, result);

    tests++;
    free(result);
  }
  return error;
}

int ft_strtrim_tests(void)
{
  ft_strtrim_test tests[] = {
      {
          .desc = "ft_strtrim(\"ababaaaYa trmiiiniiiibbaaabba\", \"ab\")",
          .s1 = "ababaaaYa trmiiiniiiibbaaabba",
          .set = "ab",
          .expected_output = "Ya trmiiiniiii",
      },
      {
          .desc = "ft_strtrim(\"\", \"ab\")",
          .s1 = "",
          .set = "ab",
          .expected_output = "",
      },
      {
          .desc = "ft_strtrim(\"\", \"\")",
          .s1 = "",
          .set = "",
          .expected_output = "",
      },
      {
          .desc = "ft_strtrim(\"ababaaaYa trmiiiniiiibbaaabba\", \"\")",
          .s1 = "ababaaaYa trmiiiniiiibbaaabba",
          .set = "",
          .expected_output = "ababaaaYa trmiiiniiiibbaaabba",
      },
      {
          .desc = "ft_strtrim(\"\\n \\t lorem ipsum dolor sit amet    \\t \\t "
                  "\\n\", \"\\t \\n\")",
          .s1 = "\n \t lorem ipsum dolor sit amet    \t \t \n",
          .set = "\t \n",
          .expected_output = "lorem ipsum dolor sit amet",
      },

      {
          .desc = 0,
      },
  };

  return run_tests(tests);
}
