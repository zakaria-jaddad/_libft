/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:33:45 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/31 23:26:21 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else 
		last->next = new;
		
}