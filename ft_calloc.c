/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:15:13 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/29 00:04:09 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t 		len;
	unsigned char	*ptr;

	len = count * size;
	if (len < 0)
		return (NULL);
	ptr = (unsigned char *) malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (len-- > 0)
		*(ptr + len) = 0;
	return (ptr);
}

