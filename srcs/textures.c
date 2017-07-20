/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:29:35 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/20 15:52:28 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_calculations(t_env *env)
{
	env->texnum = env->worldmap[env->mapx][env->mapy];
	if (env->side == 0)
		env->wallx = env->rayposy + env->perwalldist * env->raydiry;
	else
		env->wallx = env->rayposx + env->perwalldist * env->raydirx;
	env->wallx -= (int)env->wallx;
}

void	texture_x(int x, t_env *env)
{
	int		texx;
	int		texy;
	int		d;
	int		color;
	int		y;

	texx = (int)(env->wallx * (double)TEXWIDTH);
	if (env->side == 0 && env->raydirx > 0)
		texx = TEXWIDTH - texx - 1;
	if (env->side == 1 && env->raydiry < 0)
		texx = TEXWIDTH - texx - 1;
	y = env->drawstart;
	while (y < env->drawend)
	{
		d = y * 256 - WIN_Y * 128 + env->lineheight * 128;
		texy = ((d * TEXHEIGHT) / env->lineheight) / 256;
		color = texture_color(env, texx, texy);
		if (env->side == 1 && env->texnum != 4)
		{
			color = mlx_get_pixel_clr(env->ice, texx, texy);
			color = (color >> 1) & 8355711;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, color);
		y++;
	}
}

int		texture_color(t_env *env, int x, int y)
{
	int		color;

	if (env->texnum != 4)
		color = mlx_get_pixel_clr(env->wall, x, y);
	else if (env->texnum != 4 && env->side == 1)
		color = mlx_get_pixel_clr(env->ice, x, y);
	else
		color = mlx_get_pixel_clr(env->goal, x, y);
	return (color);
}

void	add_textures(t_env *env)
{
	env->splash = mlx_xpm_to_img(env->mlx, "./textures/splash_small.xpm");
	env->gg = mlx_xpm_to_img(env->mlx, "./textures/he_held_door.xpm");
	env->ceiling = mlx_xpm_to_img(env->mlx, "./textures/sky.xpm");
	env->wall = mlx_xpm_to_img(env->mlx, "./textures/ice.xpm");
	env->ice = mlx_xpm_to_img(env->mlx, "./textures/ice_test.xpm");
	env->floor = mlx_xpm_to_img(env->mlx, "./textures/snow.xpm");
	env->goal = mlx_xpm_to_img(env->mlx, "./textures/hodor.xpm");
}
