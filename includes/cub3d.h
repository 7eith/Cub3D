/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:55:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 08:20:01 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
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

	double				posX;
	double				posY;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;

	double				cameraX;

	double				raydirX;
	double				raydirY;

	int					mapX;
	int					mapY;

	double				sidedistX;
	double				sidedistY;
	double				deltadistX;
	double				deltadistY;
	double				perpwalldist;

	int					stepX;
	int					stepY;
	int					hit;
	int					side;

	int					lineheight;
	int					drawstart;
	int					drawend;

	int					x;
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

/*
**	srcs/ui/raycast.c
*/

int						raycast(t_game *vars);

/*
** 	srcs/ui/window.c
*/

int						open_window(t_game *vars);

#endif
