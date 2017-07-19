/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:01:32 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 15:27:42 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_initial_values(t_env *env)
{
	env->posx = 22.0;
	env->posy = 11.5;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = .66;
	env->rotation = .35;
	env->game_over = 0;
	env->kx = 0;
	env->ky = 0;
	env->camerax = 0;
	env->rayposx = 0;
	env->rayposy = 0;
}

void	spawn_goal(t_env *env)
{
	int		x;
	int		y;

	x = 22;
	x = 11;
	srand(time(NULL));
	{
		x = rand() % 24;
		y = rand() % 24;
	}
	env->worldmap[x][y] = 4;
	env->kx = x;
	env->ky = y;
}

void	gg_check(t_env *env)
{
	if (((int)(env->posx + env->dirx) == env->kx && (int)env->posy == env->ky)
			|| ((int)env->posx == env->kx && (int)(env->posy + env->diry) ==
				env->ky))
	{
		system("killall afplay");
		winner(env);
	}
}

void	game_on(t_env *env)
{
	int		x;

	x = 0;
	mlx_clear_window(env->mlx, env->win);
	gg_check(env);
	if (env->game_over == 0)
	{
		while (x < WIN_X)
		{
			//all of the necessary functions names
			ray_cast_vars(x, env);
			cast_rays(env);
			calc_step_and_side(env);
			digital_differential_analysis(env);
			distance_to_wall(env);
			wall_height(env);
			texture_calculations(env);
			texture_x(x, env);
			floor_casting(x, env);
			x++;
		}
	}
	else
		system("afplay sounds/victory.mp3 &");
}
