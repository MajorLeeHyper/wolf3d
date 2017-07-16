/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:19:52 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/01 14:31:46 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strlen(s1);
	j = 0;
	new = (char*)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = s1[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
