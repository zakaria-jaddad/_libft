/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:19:38 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/22 17:25:35 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char tmp_c = (unsigned char)c;
	if (tmp_c >= 'A' && tmp_c <= 'Z')
		return (tmp_c + 32);
     return (tmp_c);
}
