/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:12:52 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/02 10:00:37 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	smallen;
	size_t	i;
	size_t	i2;
	size_t	b;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	smallen = ft_strlen(little);
	while (big[i] != '\0' && len-- >= smallen)
	{
		i2 = i;
		b = 0;
		while (big[i2] == little[b])
		{
			i2++;
			b++;
			if (little[b] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
