/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:48:37 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/07 12:01:15 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(char *str, int count, int neg, long num)
{
	int		i;

	i = count + 1;
	while (count >= 0)
	{
		if (num > 9)
		{
			str[count] = (num % 10) + '0';
			num /= 10;
		}
		else
		{
			if (neg == -1)
			{
				str[1] = num + '0';
				str[i] = '\0';
				return (str);
			}
			else
				str[count] = num + '0';
		}
		count--;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	int		neg;
	long	num;

	num = (long)n;
	neg = (num >= 0 ? 1 : -1);
	count = ft_digits(num);
	if (neg == 1)
		str = ft_strnew(count);
	else
	{
		if (!(str = ft_strnew(count + 1)))
			return (NULL);
		count++;
		str[0] = '-';
	}
	if (!str)
		return (NULL);
	num = num * neg;
	count -= 1;
	return (ft_convert(str, count, neg, num));
}
