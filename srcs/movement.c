/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:33:09 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 15:30:57 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_env *env)
{
	if ((env->posx + env->dirx) > 0 && (env->posx + env->dirx) < 24 &&
			(env->posy + env->diry) > 0 && (env->posy + env->diry) < 24)
	{
		if (env->worldmap[(int)(env->posx + env->dirx)][(int)env->posy] == 0)
			env->posx += env->dirx;
		if (env->worldmap[(int)env->posx][(int)(env->posy + env->diry)] == 0)
			env->posy += env->diry;
	}
	game_on(env);
}

void	move_back(t_env *env)
{
	if ((env->posx - env->dirx) > 0 && (env->posx - env->dirx) < 24 &&
			(env->posy - env->diry) > 0 && (env->posy - env->diry) < 24)
	{
		if (env->worldmap[(int)(env->posx - env->dirx)][(int)env->posy] == 0)
			env->posx -= env->dirx;
		if (env->worldmap[(int)env->posx][(int)(env->posy - env->diry)] == 0)
			env->posy -= env->diry;
	}
	game_on(env);
}

void	turn_left(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(env->rotation) - env->diry * sin(env->rotation);
	env->diry = env->olddirx * sin(env->rotation) + env->diry *
		cos(env->rotation);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(env->rotation) - env->planey *
		sin(env->rotation);
	env->planey = env->oldplanex * sin(env->rotation) + env->planey *
		cos(env->rotation);
	game_on(env);
}

void	turn_right(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(-env->rotation) - env->diry *
		sin(-env->rotation);
	env->diry = env->olddirx * sin(-env->rotation) + env->diry *
		cos(-env->rotation);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(-env->rotation) - env->planey *
		sin(-env->rotation);
	env->planey = env->oldplanex * sin(-env->rotation) + env->planey *
		cos(-env->rotation);
	game_on(env);
}
