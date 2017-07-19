/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:51:01 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 15:21:20 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env *env;

	if (ac > 1)
	{
		av = NULL;
		ft_putendl("No need to put anything, this program has one map");
		ft_putendl("Please try again without any arguments. Have a nice day!");
		return (0);
	}
	system("afplay sounds/doom.mp3 &");
	env = (t_env*)ft_memalloc(sizeof(t_env));
	env->mlx = mlx_init(0);
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Wolf3D");
	add_textures(env);
	map_allocation(env);
	set_initial_values(env);
	map_builder(env);
	spawn_goal(env);
	splash(env);
	mlx_hook(env->win, KEYPRESS, KEYPRESSMASK, key_press, env);
	mlx_hook(env->win, DESTROYNOTIFY, NOTIFYNORMAL, exit_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
