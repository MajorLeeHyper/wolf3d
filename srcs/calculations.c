/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:40:39 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 17:44:03 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_step_and_side(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

void	digital_differential_analysis(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->worldmap[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
}

void	distance_to_wall(t_env *env)
{
	if (env->side == 0)
	{
		env->perwalldist = (env->mapx - env->rayposx +
				(1 - env->stepx) / 2) / env->raydirx;
	}
	else
	{
		env->perwalldist = (env->mapy - env->rayposy + (1 - env->stepy) / 2) /
			env->raydiry;
	}
}

void	wall_height(t_env *env)
{
	env->lineheight = (int)(2 * WIN_Y / env->perwalldist);
	env->drawstart = -env->lineheight / 2 + WIN_Y / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + WIN_Y / 2;
	if (env->drawend >= WIN_Y)
		env->drawend = WIN_Y -1;
}
