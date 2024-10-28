/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:10:58 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/27 15:57:37 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return 0;
	n--;	
	while (*s1 && *s2 && *s1 == *s2 && n-- > 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

