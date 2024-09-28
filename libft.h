#ifndef LIBFT_H
# define LIBFT_H

void	ft_bzero(void *s, int n);

/*
 * ft_memset writes len bytes of value c to string b,
 * c is (converted to an unsingned char).
 *
 * returns its first argument.
 */
void	*ft_memset(void *b, int c, int len);

/*
 * ft_strnstr locates the first accurrence of the needle
 * in the string haystack where not more than len characters
 * are searched
 *
 * Characters that appear after '\0' are not sreached.
 *
 * Return values: 
 *   if needle is empty string:
 *   -> haystack
 *
 *   if needle not found in haystack:
 *   -> NULL
 *
 *   if needle found in haystack:
 *   -> pointer to the first accurrence of needle
 */
char	*ft_strnstr(const char *haystack, const char *needle,
			unsigned int len);

#endif
