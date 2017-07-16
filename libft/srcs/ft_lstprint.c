/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:36:25 by dnelson           #+#    #+#             */
/*   Updated: 2016/12/14 11:39:33 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*to_print;

	to_print = lst;
	while (to_print != NULL)
	{
		ft_putstr((char*)to_print->content);
		to_print = to_print->next;
	}
}
