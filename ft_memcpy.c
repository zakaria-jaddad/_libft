/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:40:42 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/30 12:59:07 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void 	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	unsigned char		*src_tmp;

	dst_tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
