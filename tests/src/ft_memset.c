#include "../include/tests.h"

Test(ft_memset, Test_01)
{
	char			str[10] = "hello\n";
	unsigned int	n;
	char			*ptr;

	n = sizeof(char) * 4;
	ptr = ft_memset(str, 'h', n);
	cr_assert(ptr[0] == 'h');
	cr_assert(ptr[1] == 'h');
	cr_assert(ptr[2] == 'h');
	cr_assert(ptr[3] == 'h');
	cr_assert(ptr[4] != 'h');
}

Test(ft_memset, Test_02)
{
	char			ft_str[10] = "hello\n";
	char			str[10] = "hello\n";
	unsigned int	n;

	n = sizeof(char) * 4;
	cr_assert_str_eq(ft_memset(ft_str, 'h', n), memset(str, 'h', n));
}

Test(ft_memset, Test_03)
{
	char			str[10] = "hello\n";
	unsigned int	n;

	n = sizeof(char) * 0;
	cr_assert_str_eq(ft_memset(str, 'h', n), str);
}

Test(ft_memset, Test_04)
{
	char			str[10] = "hello\n";
	unsigned int	n;
	char			*ptr;

	n = sizeof(char) * strlen(str);
	ptr = ft_memset(str, 0, n);
	cr_assert_eq(ptr[0], 0);
	cr_assert_eq(ptr[1], 0);
	cr_assert_eq(ptr[2], 0);
	cr_assert_eq(ptr[3], 0);
	cr_assert_eq(ptr[4], 0);
	cr_assert_eq(ptr[5], 0);
}

Test(ft_memset, Test_05)
{
	char			str[10] = "hello\n";
	unsigned int	n;
	char			*ptr;

	n = sizeof(char) * (strlen(str) + 42);
	ptr = ft_memset(str, 0, n);
	cr_assert_eq(ptr[0], 0);
	cr_assert_eq(ptr[1], 0);
	cr_assert_eq(ptr[2], 0);
	cr_assert_eq(ptr[3], 0);
	cr_assert_eq(ptr[4], 0);
	cr_assert_eq(ptr[5], 0);
}

Test(ft_memset, Test_06)
{
	char			str[10] = "";
	unsigned int	n;
	char			*ptr;

	n = sizeof(char) * (strlen(str) + 42);
	ptr = ft_memset(str, 0, n);
	cr_assert_eq(ptr[0], '\0');
}

Test(ft_memset, Test_07)
{
	char			str[10] = "";
	unsigned int	n;

	n = sizeof(char) * 42;
	cr_assert_str_eq(ft_memset(str, 0, n), "");
}

Test(ft_memset, Test_08)
{
	char	str[10] = "hello\n";
	int		n;

	n = -3;
	cr_assert_str_eq(ft_memset(str, 0, n), str);
}
