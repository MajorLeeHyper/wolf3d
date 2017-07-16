/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 08:15:18 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/08 11:41:12 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **arr)
{
	ft_putchar('[');
	if (*arr)
		ft_putstr(*arr++);
	while (*arr)
	{
		ft_putchar(',');
		ft_putchar(' ');
		ft_putstr(*arr++);
	}
	ft_putchar(']');
}
