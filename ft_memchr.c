/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:39:26 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/28 14:22:01 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void 	*ft_memchr(const void *s, int c, size_t n)
{
	char *tmp;

	tmp = (char *)s;
	while(n--)
	{
		if (*tmp == (unsigned char) c)
			return ((void *) tmp);
		tmp++;
	}
	return (NULL);
}

