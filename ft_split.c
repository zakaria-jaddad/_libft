/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:27:58 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/31 12:29:12 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	size_t	counter;
	int		word_flag;

	word_flag = 1;
	counter = 0;
	while (*s)
	{
		if (word_flag && *s != c)
		{
			counter++;
			word_flag = 0;
		}
		else if (*s == c)
			word_flag = 1;
		s++;
	}
	return (counter);
}

static char	*get_next_word(char const *s, char c, int index)
{
	int	counter;
	int		word_flag;

	word_flag = 1;
	counter = 0;
	while (*s)
	{
		if (word_flag && *s != c)
		{
			counter++;
			if (counter == index)
				return ((char *) s);
			word_flag = 0;
		}
		else if (*s == c)
			word_flag = 1;
		s++;
	}
	return (NULL);
}

static int	strlen_dial_l3bar(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s++ != c)
		length++;
	return (length);
}

static char	*strdup_dial_l3bar(char const *s, size_t len)
{
	char	*str;
	int		i;

	str = (char *) malloc(len + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i] && len--)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
static void free_leaks(char **ptr, int index)
{
	int	i;

	i = 0;
	while (i < index) 
		free(ptr[i++]);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		word_length;
	int		i;
	char	**ptr;
	char	*word;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	i = 0;
	ptr = (char **) malloc(sizeof(char *) * (words + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < words)
	{
		word = get_next_word(s, c, (i + 1));
		word_length = strlen_dial_l3bar(word, c);
		ptr[i] = (char *) malloc(word_length + 1);
		if (ptr[i] == NULL)
		{
			free_leaks(ptr, i);
			return (NULL);
		}
		ptr[i++] = strdup_dial_l3bar(word, word_length);
	}
	ptr[i] = NULL;
	return (ptr);
}

int main(int argc, char *argv[])
{
	char *hello = "hello,also,also";
	char **boo = ft_split(hello, ',');

	
	int i = 0;
	while (boo[i] != NULL)
	{
		printf("%s\n", boo[i++]);
	}
	return EXIT_SUCCESS;
}
