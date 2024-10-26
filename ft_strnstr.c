/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:26:55 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/23 11:29:39 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == 0)
		return (char *) haystack;
	while (*haystack)
	{
		i = 0;
		while (needle[i] == haystack[i] && i < len)
			i++;
		if (needle[i] == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
