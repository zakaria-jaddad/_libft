/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:42:34 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:03 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = (char *) malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	ft_memcpy(substr, &s[start], len);
	/* while (s[start] && len--) */
	/* 	substr[i++] = s[start++]; */
	substr[len] = 0;
	return (substr);
}
