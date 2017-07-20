/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splashes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:04:22 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/20 11:56:52 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	splash(t_env *env)
{
	env->start = 0;
	mlx_put_image_to_window(env->mlx, env->win, env->splash, 0, 0);
	mlx_string_put(env->mlx, env->win, 255, 281, 0xFFFFFF, "Press Enter");
}

void	winner(t_env *env)
{
	env->game_over = 1;
	mlx_put_image_to_window(env->mlx, env->win, env->gg, 0, 0);
	mlx_string_put(env->mlx, env->win, 200, 400, 0xFFFFFF, "Press Enter to \
			restart");
	mlx_string_put(env->mlx, env->win, 200, 430, 0xFFFFFF, "Press Esc to quit");
}
