/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:05:18 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 13:11:58 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	strafe_left(t_env *env)
{
	if ((env->posx - env->dirx) > 0 && (env->posx - env->dirx) < 24 &&
			(env->posy - env->diry) > 0 && (env->posy - env->diry) < 24)
	{
		if (env->worldmap[(int)(env->posx - env->planex)][(int)env->posy] == 0)
			env->posx -= env->planex;
		if (env->worldmap[(int)env->posx][(int)(env->posy - env->planey)] == 0)
			env->posy -= env->planey;
	}
	game_on(env);
}

void	strafe_right(t_env *env)
{
	if ((env->posx - env->dirx) > 0 && (env->posx - env->dirx) < 24 &&
			(env->posy - env->diry) > 0 && (env->posy - env->diry) < 24)
	{
		if (env->worldmap[(int)(env->posx + env->planex)][(int)env->posy] == 0)
			env->posx += env->planex;
		if (env->worldmap[(int)env->posx][(int)(env->posy + env->planey)] == 0)
			env->posy += env->planey;
	}
	game_on(env);
}
