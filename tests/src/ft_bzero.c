#include "../include/tests.h"


Test(ft_bzero, Test_01)
{
	char	ft_bzero_str[10] = "hello";
	char	bzero_str[10] = "hello";
	int		n;

	n = 5;
	ft_bzero(ft_bzero_str, n);
	bzero(bzero_str, n);
	cr_assert_str_eq(bzero_str, ft_bzero_str);
}
