/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:02:53 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/20 12:57:59 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	replay(t_env *env)
{
	free(env->worldmap);
	free(env->goal);
	free(env->gg);
	add_textures(env);
	map_allocation(env);
	set_initial_values(env);
	map_builder(env);
	spawn_goal(env);
	splash(env);
}
