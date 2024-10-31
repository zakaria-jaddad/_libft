/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:57:01 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/31 23:26:08 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		  void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);	
}

void *majiscule(void *ptr)
{
	char *tmp = (char *)ptr;
	while (*tmp)
	{
		*tmp -= 32;
		tmp++;
	}
	return ptr;
}

void handlini(void *ptr)
{
	free(ptr);
}

int main(void)
{
	char str_node_1[] = "hello";
	char str_node_2[] = "hola";
	char str_node_3[] = "hellllllo";

	t_list *node3 = (t_list *) malloc(sizeof(t_list));
	node3->content = str_node_3;
	node3->next = NULL;

	t_list *node2 = (t_list *) malloc(sizeof(t_list));
	node2->content = str_node_2;
	node2->next = node3;

	t_list *node1 = (t_list *) malloc(sizeof(t_list));
	node1->content = str_node_1;
	node1->next = node2;
	
	t_list *tmp = node1;
	while (tmp)
	{
		printf("%s -> ", (char *) tmp->content);
		tmp = tmp->next;
	}

	printf("\n================================\n");

	t_list *also = node1;
	t_list *boo = ft_lstmap(also, majiscule, handlini);
	while (boo)
	{
		printf("%s -> ", (char *) boo->content);
		boo = boo->next;
	}
	return EXIT_SUCCESS;
}

