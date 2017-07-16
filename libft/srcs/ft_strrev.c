/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:24:50 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/03 15:25:27 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	size_t	i;
	size_t	size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	size -= 1;
	while (i < size)
	{
		temp = str[size];
		str[size] = str[i];
		str[i] = temp;
		i++;
		size--;
	}
	return (str);
}
