#include "../include/tests.h"

Test(ft_strnstr, Test_01)
{
	cr_assert(ft_strnstr("aaabcabcd", "aabc", 0) == NULL);
}

Test(ft_strnstr, Test_02)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "aabc", -1), "aabcabcd");
}

Test(ft_strnstr, Test_03)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "a", -1), "aaabcabcd");
}

Test(ft_strnstr, Test_04)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "c", -1), "cabcd");
}

Test(ft_strnstr, Test_05)
{
	cr_assert_str_eq(ft_strnstr("", "", -1), "");
}

Test(ft_strnstr, Test_06)
{
	cr_assert_str_eq(ft_strnstr("", "", 0), "");
}

Test(ft_strnstr, Test_07)
{
	cr_assert(ft_strnstr("", "coucou", -1) == NULL);
}

Test(ft_strnstr, Test_08)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "aaabc", 5), "aaabcabcd");
}

Test(ft_strnstr, Test_09)
{
	cr_assert(ft_strnstr("", "12345", 5) == NULL);
}

Test(ft_strnstr, Test_10)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "abcd", 9), "abcd");
}

Test(ft_strnstr, Test_11)
{
	cr_assert(ft_strnstr("aaabcabcd", "abcd", 2) == NULL);
}

Test(ft_strnstr, Test_12)
{
	cr_assert_eq(ft_strnstr("aaabcabcd", "cd", 8), NULL);
}

Test(ft_strnstr, Test_13)
{
	cr_assert_str_eq(ft_strnstr("aaabcabcd", "a", 1), "aaabcabcd");
}

Test(ft_strnstr, Test_14)
{
	cr_assert(ft_strnstr("1", "a", 1) == NULL);
}

Test(ft_strnstr, Test_15)
{
	cr_assert(ft_strnstr("22", "b", 2) == NULL);
}

Test(ft_strnstr, Test_16)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "", -599), "Hello World");
}

Test(ft_strnstr, Test_17)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "", 0), "Hello World");
}

Test(ft_strnstr, Test_18)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "H", 1), "Hello World");
}

Test(ft_strnstr, Test_19)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "H", 300), "Hello World");
}

Test(ft_strnstr, Test_20)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "ll", 300), "llo World");
}

Test(ft_strnstr, Test_21)
{
	cr_assert(ft_strnstr("Hello World", "ll", 1) == NULL);
}

Test(ft_strnstr, Test_22)
{
	cr_assert(ft_strnstr("Hello World", "llo", 4) == NULL);
}

Test(ft_strnstr, Test_23)
{
	cr_assert_str_eq(ft_strnstr("Hello World", "llo", 5), "llo World");
}

Test(ft_strnstr, Test_24)
{
	cr_assert(ft_strnstr("Hello World", "H", 0) == NULL);
}
