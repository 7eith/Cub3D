/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:20:44 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/14 04:58:24 by amonteli         ###   ########lyon.fr   */
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
# define MAP_POSITION_TYPE "NSWE"
# define MAP_FLAGS "NSWE201 \n"

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
	MV_UP = (1 << 0),
	MV_DOWN = (1 << 1),
	MV_LEFT = (1 << 2),
	MV_RIGHT = (1 << 3),
	LEFT = (1 << 4),
	RIGHT = (1 << 5),
};

enum					e_keycode
{
	KEY_ESCAPE = 65307,
	KEY_MOVE_UP = 119,
	KEY_MOVE_DOWN = 115,
	KEY_MOVE_LEFT = 97,
	KEY_MOVE_RIGHT = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
};

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
 **	parser/parser.c
*/

void					parse_file(t_game *vars, char *filename);

/*
**	parser/args_parser.c
*/

void					check_params(t_game *vars, int argc, char **args);

/*
**	parser/configuration_manager.c
*/

void					parse_configuration(t_game *vars, int fd);

/*
**	parser/map_parser.c
*/

void					parse_map(t_game *vars, int fd);

/*
**	parser/parser_utils.c
*/

int						is_only_resolution(char *line);
void					check_screen_size(t_game *vars);

/*
**	utils/exit_manager.c
*/

void					exit_program(t_game *vars, char *reason);

/*
**	utils/utilities.c
*/

int						is_valid_configuration(t_game *vars);
t_color					create_color(int r, int g, int b);
float					ft_fabs(float number);


int						is_valid_map(t_game *vars);

/*
**	=============================
**
**			  ENGINE
**
**  =============================
*/

/*
**	engine/window_manager.c
*/

void					open_window(t_game *vars);
int						close_window(t_game *vars);

/*
**	engine/keyboard_manager.c
*/

int						key_press(int key_code, t_game *vars);
int						key_release(int key_code, t_game *vars);

#endif
