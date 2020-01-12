/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:55:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 03:51:34 by amonteli    ###    #+. /#+    ###.fr     */
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
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define C_SETTINGS ""
# define MAP_ACCEPT_FLAGS "012NSWE"

enum
{
	ST_SAVE = (1 << 0),
};

enum					e_err
{
	ERR_MAP,
	ERR_RD,
	ERR_KEY
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
	int					c;
	int					width;
	int					height;
	void				*img;
	int					*data;
}						t_textures;

/*
**	x:	x position
**	y:	y position
*/

typedef	struct			s_player
{
	float				x;
	float				z;
}						t_player;

typedef	struct			s_settings
{
	unsigned char		flags;
	int					w;
	int					h;
}						t_settings;

typedef	struct			s_map
{
	int					**map;
	int					w;
	int					h;
}						t_map;

/*
**	mlx_p: 				MiniLibX pointer
**	mlx_w:				MiniLibX window
**	t_player:			struct player
**	t_setting:			struct settings
*/

typedef struct			s_cub3d
{
	void				*mlx_p;
	void				*mlx_w;
	t_player			player;
	t_settings			settings;
	t_map				map;
	t_textures			textures[4];
}						t_cub3d;

/*
** 	srcs/cub3d.c
*/

int						main(int argsc, char **args);

/*
** 	srcs/parser.c
*/

void					parse(t_cub3d *cube, int argc, char **args);

#endif
