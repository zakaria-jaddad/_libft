/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 03:27:58 by zajaddad          #+#    #+#             */
/*   Updated: 2024/10/29 04:46:26 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

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

	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (*s)
		*str++ = *s++;
	*str = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		word_length;
	int		i;
	char	**ptr;
	char	*word;

	words = count_words(s, c);
	i = 0;
	if (s == NULL)
		return (NULL);
	ptr = (char **) malloc(sizeof(char *) * (words + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < words)
	{
		word = get_next_word(s, c, (i + 1));
		word_length = strlen_dial_l3bar(word, c);
		ptr[i] = (char *) malloc(word_length + 1);
		if (ptr == NULL)
			return (NULL);
		ptr[i++] = strdup_dial_l3bar(word, word_length);
	}
	ptr[i] = NULL;
	return (ptr);
}
