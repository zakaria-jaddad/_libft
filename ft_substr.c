/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:42:34 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/02 00:09:55 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*substr;
	int				i;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s_len < start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *) malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	ft_memcpy(substr, &s[start], len);
	substr[len] = 0;
	return (substr);
}
