/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:59:41 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/02 10:23:25 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c2;
	char	*s2;

	i = 0;
	c2 = (char)c;
	s2 = (char*)s;
	while (*s2)
	{
		s2++;
		i++;
	}
	while (i > 0)
	{
		if (*s2 == c2)
			return (s2);
		s2--;
		i--;
	}
	if (s2[0] == c2)
		return (s2);
	return (NULL);
}
