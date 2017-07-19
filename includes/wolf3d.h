/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:53:49 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/19 15:43:43 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# define WIN_X 800
# define WIN_Y 600

# define TEXWIDTH 64
# define TEXHEIGHT 64

# define KEYPRESSMASK (1L<<0)
# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define NOTIFYNORMAL 0

typedef struct	s_env
{
	void	*mlx;
	void	*win;

	int		**worldmap;
	int		mapx;
	int		mapy;

	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;

	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;

	int		lineheight;
	int		drawstart;
	int		drawend;

	double	wallx;
	double	frametime;
	double	movespeed;
	double	rotation;

	double	floorxwall;
	double	floorywall;
	double	distwall;
	double	distplayer;
	double	currentdist;

	double	weight;
	double	currentfloorx;
	double	currentfloory;
	int		floortexx;
	int		floortexy;
	int		color;

	double	olddirx;
	double	oldplanex;

	void	*splash;
	void	*ceiling;
	void	*wall;
	void	*floor;
	void	*goal;
	void	*gg;
	int		texnum;

	int		start;
	int		game_over;

	int		kx;
	int		ky;
}				t_env;

void		set_initial_values(t_env *env);
void		spawn_goal(t_env *env);
void		gg_check(t_env *env);
void		game_on(t_env *env);
void		calc_step_and_side(t_env *env);
void		digital_differential_analysis(t_env *env);
void		distance_to_wall(t_env *env);
void		wall_height(t_env *env);
int			exit_hook(t_env *env);
int			movement_keys(int keycode, t_env *env);
int			key_press(int keycode, t_env *env);
void		map_allocation(t_env *env);
void		wall_placer(int x, int y, t_env *env);
void		map_builder(t_env *env);
void		move_forward(t_env *env);
void		move_back(t_env *env);
void		turn_left(t_env *env);
void		turn_right(t_env *env);
void		strafe_left(t_env *env);
void		strafe_right(t_env *env);
void		ray_cast_vars(int x, t_env *env);
void		cast_rays(t_env *env);
void		floor_casting(int x, t_env *env);
void		more_floor_cast(int x, t_env *env);
void		texture_calculations(t_env *env);
void		texture_x(int x, t_env *env);
int			texture_color(t_env *env, int x, int y);
void		add_textures(t_env *env);
void		splash(t_env *env);
void		winner(t_env *env);

#endif
