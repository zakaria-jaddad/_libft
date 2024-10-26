/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:27:03 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/22 17:25:48 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char tmp_c = (unsigned char)c;
	if (tmp_c >= 'a' && tmp_c <= 'z')
		return (tmp_c - 32);
     return (tmp_c);
}
