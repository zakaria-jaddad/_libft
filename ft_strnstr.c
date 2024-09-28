#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	i;
	int		j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		j = 0;
		while (needle[j] && *haystack == needle[j])
		{
			j++;
			haystack++;
		}
		if (needle[j] == 0 && i + (j - 1) < len)
			return ((char *)haystack - j);
		haystack = haystack - j;
		haystack++;
		i++;
	}
	return (0);
}
