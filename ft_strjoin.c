/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:44:38 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/29 01:22:42 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char 	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *) malloc(len_s1 + len_s2 + 1);
	if (str == NULL)
		return (NULL);
	(void)ft_strlcpy(str, s1, len_s1 + 1);
	(void)ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}
