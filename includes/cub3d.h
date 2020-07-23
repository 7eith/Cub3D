/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:55:06 by amonteli          #+#    #+#             */
/*   Updated: 2020/07/22 21:08:50 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define TEXTURES 5
# define MAP_FLAGS "NSWE201 "

/*
**	Configurations key in map.cub
*/

enum					e_conf
{
	R = (1 << 0),
	T_NO = (1 << 1),
	T_SO = (1 << 2),
	T_WE = (1 << 3),
	T_EA = (1 << 4),
	T_S = (1 << 5),
	F = (1 << 6),
	C = (1 << 7),
};

enum					e_key
{
	LEFT = (1 << 0),
	RIGHT = (1 << 1),
	UP = (1 << 2),
	DOWN = (1 << 3),
	MV_LEFT = (1 << 4),
	MV_RIGHT = (1 << 5),
};

enum					e_keycode
{
	ESCAPE = 53,
	R_LEFT = 123,
	R_RIGHT = 124,
	R_DOWN = 125,
	R_UP = 126,
	R_MVLEFT = 0,
	R_MVRIGHT = 2
};

/*
** 	Enum
**	Colored Textures. (RGB Textures)
*/

enum					e_colored_textures
{
	FLOOR,
	SKY
};

enum					e_textures
{
	NORTH,
	WEST,
	SOUTH,
	EAST,
	SPRITE
};

/*
**	union for get RGB color
**	assign color by t_color.rgb.KEY = INT;
**	get int RGB by t_color.c;
*/

typedef union			u_color
{
	unsigned int		c;
	struct				s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}					rgb;
}						t_color;

typedef	struct			s_textures
{
	int					width;
	int					height;
	void				*img;
	int					*data;
}						t_textures;

typedef struct			s_game
{
	void				*mlx;
	void				*window;
	int					screen;
	int					width;
	int					height;
	int					conf;
	t_color				colors[2];
	char				*paths[5];
	char				**map;
	char				*map_buf;

	void				*img;
	int					*img_data;

	float				posX;
	float				posY;
	float				dirX;
	float				dirY;
	float				planeX;
	float				planeY;

	float				cameraX;

	float				raydirX;
	float				raydirY;

	int					mapX;
	int					mapY;

	float				sidedistX;
	float				sidedistY;
	float				deltadistX;
	float				deltadistY;
	float				perpwalldist;

	int					stepX;
	int					stepY;
	int					hit;
	int					side;

	int					lineheight;
	int					drawstart;
	int					drawend;

	float				x;
	int					wall_height;
	unsigned char		key;
}						t_game;

/*
** 	srcs/cub3d.c
*/

int						main(int argsc, char **args);
void					exit_programs(t_game *vars, char *str);

/*
** 	srcs/parser.c
*/

void					parse(t_game *vars, char **args);
void					parse_configuration(t_game *vars, int fd);
void					read_map(t_game *vars, int fd);
void					check_map(t_game *vars);

/*
**	srcs/utils/utilities.c
*/

t_color					create_color(int r, int g, int b);
float					ft_fabs(float number);
int						is_valid_configuration(t_game *vars);

/*
**	srcs/ui/raycast.c
*/

int						raycast(t_game *vars);

/*
** 	srcs/ui/window.c
*/

int						open_window(t_game *vars);

/*
**	srcs/ui/keybinds.c
*/

int						key_press(int key_code, t_game *vars);
int						key_release(int key_code, t_game *vars);
void					key_manager(t_game *vars);

/*
**	srcs/engine/movement.c
*/

void					up_movement(t_game *vars);
void					down_movement(t_game *vars);
void					left_movement(t_game *vars);

#endif
