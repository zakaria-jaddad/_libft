#include "../include/util.h"

void print_byte_red(void *b, size_t len)
{
  unsigned char *mem_ptr = b;
  for (size_t i = 0; i < len; i++)
    printf(RED "%u ", mem_ptr[i]);
}

void print_byte_green(void *b, size_t len)
{
  unsigned char *mem_ptr = b;
  for (size_t i = 0; i < len; i++)
    printf(GREEN "%u ", mem_ptr[i]);
}
