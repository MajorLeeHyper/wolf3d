/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:38:06 by dnelson           #+#    #+#             */
/*   Updated: 2016/11/30 15:48:37 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	ia;
	size_t	b;

	i = 0;
	if (little[0] == '\0')
		return (char*)(big);
	while (big[i] != '\0')
	{
		ia = i;
		b = 0;
		while (big[ia] == little[b])
		{
			ia++;
			b++;
			if (little[b] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
