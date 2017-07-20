/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:12:50 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/20 13:11:22 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ray_cast_vars(int x, t_env *env)
{
	env->camerax = 2 * x / (double)WIN_X - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
}

void	cast_rays(t_env *env)
{
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry) /
			(env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx) /
			(env->raydiry * env->raydiry));
	env->hit = 0;
}

void	floor_casting(int x, t_env *env)
{
	if (env->side == 0 && env->raydirx > 0)
	{
		env->floorxwall = env->mapx;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 0 && env->raydirx < 0)
	{
		env->floorxwall = env->mapx + 1.0;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 1 && env->raydiry > 0)
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy;
	}
	else
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy + 1.0;
	}
	more_floor_cast(x, env);
}

void	more_floor_cast(int x, t_env *e)
{
	int		y;

	e->distwall = e->perwalldist;
	e->distplayer = 0.0;
	if (e->drawend < 0)
		e->drawend = WIN_Y;
	y = e->drawend;
	while (++y < WIN_Y)
	{
		e->currentdist = WIN_Y / (2.0 * y - WIN_Y);
		e->weight = (e->currentdist - e->distplayer) /
			(e->distwall - e->distplayer);
		e->currentfloorx = e->weight * e->floorxwall +
			(1.0 - e->weight) * e->posx;
		e->currentfloory = e->weight * e->floorywall +
			(1.0 - e->weight) * e->posy;
		e->floortexx = (int)(e->currentfloorx * TEXWIDTH / 4) % TEXWIDTH;
		e->floortexy = (int)(e->currentfloory * TEXHEIGHT / 4) % TEXHEIGHT;
		e->color = mlx_get_pixel_clr(e->floor, e->floortexx, e->floortexy);
		mlx_pixel_put(e->mlx, e->win, x, y, e->color);
		e->color = mlx_get_pixel_clr(e->ceiling, e->floortexx, e->floortexy);
		mlx_pixel_put(e->mlx, e->win, x, (WIN_Y - y), e->color);
	}
}
