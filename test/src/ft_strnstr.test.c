#include "../include/test.h"

typedef struct test
{
  char *desc;
  const char *haystack;
  const char *needle;
  size_t len;
  char *expected_output;
} ft_strnstr_test;

static int run_tests(ft_strnstr_test *tests)
{
  int error = 0;
  while (tests->desc)
  {
    char *result = ft_strnstr(tests->haystack, tests->needle, tests->len);
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

int ft_strnstr_tests(void)
{
  ft_strnstr_test tests[] = {
      {
          .desc = "ft_strnstr(\"aaabcabcd\", \"aabc\", 0)",
          .haystack = "aaabcabcd",
          .needle = "aabc",
          .len = 0,
          .expected_output = strnstr("aaabcabcd", "aabc", 0),
      },
      {
          .desc = "ft_strnstr(\"aaabcabcd\", \"aabc\", -1)",
          .haystack = "aaabcabcd",
          .needle = "aabc",
          .len = -1,
          .expected_output = strnstr("aaabcabcd", "aabc", -1),
      },
      {
          .desc = "ft_strnstr(\"aaabcabcd\", \"a\", -1)",
          .haystack = "aaabcabcd",
          .needle = "a",
          .len = -1,
          .expected_output = strnstr("aaabcabcd", "a", -1),
      },
      {
          .desc = "ft_strnstr(\"aaabcabcd\", \"c\", -1)",
          .haystack = "aaabcabcd",
          .needle = "c",
          .len = -1,
          .expected_output = strnstr("aaabcabcd", "c", -1),
      },
      {
          .desc = "ft_strnstr(\"\", \"\", -1)",
          .haystack = "",
          .needle = "",
          .len = -1,
          .expected_output = strnstr("", "", -1),
      },
      {
          .desc = "ft_strnstr(\"\", \"hello\", 300)",
          .haystack = "",
          .needle = "hello",
          .len = 300,
          .expected_output = strnstr("", "hello", 300),
      },
      {
          .desc = "ft_strnstr(\"Hello World\", \"llo\", 4)",
          .haystack = "Hello World",
          .needle = "llo",
          .len = 4,
          .expected_output = strnstr("Hello World", "llo", 4),
      },
      {
          .desc = "ft_strnstr(\"A\", \"A\", 2)",
          .haystack = "A",
          .needle = "A",
          .len = 2,
          .expected_output = strnstr("A", "A", 2),
      },
      {
          .desc = "ft_strnstr(\"is there a nyacat ?\", \"is there a nyacat "
                  "?\", strlen(\"is there a nyacat ?\"))",
          .haystack = "is there a nyacat ?",
          .needle = "is there a nyacat ?",
          .len = strlen("is there a nyacat ?"),
          .expected_output =
              strnstr("is there a nyacat ?", "is there a nyacat ?",
                      strlen("is there a nyacat ?")),
      },

      {
          .desc = 0,
      },
  };
  return run_tests(tests);
}
