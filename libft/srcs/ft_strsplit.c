/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:35:53 by dnelson           #+#    #+#             */
/*   Updated: 2017/06/15 13:03:46 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <strings.h>

static size_t	word_count(char *str, char c)
{
	size_t		i;
	size_t		words;
	int			toggle;

	i = 0;
	words = 0;
	toggle = 1;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (toggle == 1 && str[i] != c)
		{
			toggle = 0;
			words++;
		}
		else if (toggle == 0 && str[i] == c)
			toggle = 1;
		i++;
	}
	return (words + 1);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		j;
	size_t		k;
	char		**array;

	if (!s)
		return (NULL);
	k = 0;
	if (!(array = (char**)malloc(sizeof(char*) * (word_count((char*)s, c)))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			array[k] = ft_strnew(ft_strlenc((char*)s, c));
			while (*s && *s != c)
				array[k][j++] = *s++;
			array[k++][j] = '\0';
		}
	}
	array[k] = NULL;
	return (array);
}
