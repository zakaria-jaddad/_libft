/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:03:55 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/01 19:22:53 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*tmp_src;
	unsigned char		*tmp_dst;

	tmp_src = (const unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	if (tmp_dst == NULL && tmp_src == NULL)
		return (NULL);
	if (tmp_dst > tmp_src)
	{
		tmp_src += len;
		tmp_dst += len;
		while (len-- > 0)
			*--tmp_dst = *--tmp_src;
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
