/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:26 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/31 17:58:57 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;	
	t_list	*p;

	t = *lst;
	p = *lst;
	while (p)
	{
		p = p->next;
		ft_lstdelone(t, del);
		t = p;
	}
	*lst = NULL;
}

