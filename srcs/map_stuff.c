/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:25:52 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/18 09:45:55 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_allocation(t_env *env)
{
	int		i;

	i = -1;
	env->worldmap = (int**)malloc(sizeof(int*) * 24);
	while (++i < 24)
		env->worldmap[i] = (int*)malloc(sizeof(int) * 24);
}

void	wall_placer(int x, int y, t_env *env)
{
	//need to adjust to make custom map
	if (x == 0)
		env->worldmap[x][y] = 2;
	else if (y == 0)
		env->worldmap[x][y] = 1;
	else if (x == 23 || y == 23)
		env->worldmap[x][y] = 1;
	else if (x == 15 && y >= 6 && y <= 16)
	{
		if ( y == 11)
			env->worldmap[x][y] = 0;
		else
			env->worldmap[x][y] = 3;
	}
	else if (y == 6 && x >= 9 && x <= 16)
		env->worldmap[x][y] = 3;
	else if (y == 16 && x >= 16 && x <= 22)
		env->worldmap[x][y] = 3;
	else
		env->worldmap[x][y] = 0;
}

void	map_builder(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			wall_placer(x, y, env);
			y++;
		}
		x++;
	}
}
