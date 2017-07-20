/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:47:38 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/20 13:59:50 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		exit_hook(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	system("killall afplay");
	exit(0);
	return (0);
}

int		movement_keys(int keycode, t_env *env)
{
	if (keycode == 13 || keycode == 126)
	{
		system("afplay sounds/walk.mp3 &");
		move_forward(env);
	}
	else if (keycode == 1 || keycode == 125)
	{
		system("afplay sounds/walk.mp3 &");
		move_back(env);
	}
	else if (keycode == 123)
		turn_left(env);
	else if (keycode == 124)
		turn_right(env);
	else if (keycode == 0)
	{
		system("afplay sounds/walk.mp3 &");
		strafe_left(env);
	}
	else if (keycode == 2)
	{
		system("afplay sounds/walk.mp3 &");
		strafe_right(env);
	}
	return (0);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == 36 && env->start == 0)
	{
		env->start = 1;
		system("killall afplay");
		system("afplay sounds/hodor.mp3 &");
		system("afplay sounds/background.mp3 &");
		game_on(env);
	}
	else if (keycode == 36 && env->game_over == 1)
	{
		system("killall afplay");
		system("afplay sounds/got.mp3 &");
		env->game_over = 0;
		replay(env);
	}
	if (env->start == 1 && env->game_over == 0)
		movement_keys(keycode, env);
	if (keycode == 53)
	{
		system("killall afplay");
		exit(0);
	}
	return (0);
}
