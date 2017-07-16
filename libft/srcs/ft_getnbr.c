/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:05:18 by dnelson           #+#    #+#             */
/*   Updated: 2017/04/03 10:07:57 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(char *str)
{
	int		nbr;

	nbr = 0;
	if (str != NULL && str[0] == '-')
		return (-ft_getnbr(&str[1]));
	while ((*str >= '0') && (*str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr);
}
