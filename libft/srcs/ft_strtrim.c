/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:35:26 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/07 12:11:35 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	ssize_t	i;
	ssize_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		len--;
		i++;
	}
	if (len < 0)
		len = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	s += i;
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
