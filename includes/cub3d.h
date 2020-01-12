/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:55:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 08:28:50 by amonteli    ###    #+. /#+    ###.fr     */
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

/*
** ERR_INVALID_MAP_NAME
** ERR_DK = Error double key entered
** ERR_IK = Error invalid key
** ERR_EK = Error empty key
*/

enum					e_err
{
	ERR_INVALID_ARGUMENTS,
	ERR_INVALID_MAP_NAME,
	ERR_READING,
	ERR_INVALID_KEY,
	ERR_DOUBLE_KEY,
	ERR_EMPTY_KEY,
	ERR_INVALID_SPACED_LINE
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

/*
**	x:	x position
**	y:	y position
*/

typedef	struct			s_player
{
	float				x;
	float				z;
	float				dir;
}						t_player;

/*
**	mlx_p: 				MiniLibX pointer
**	mlx_w:				MiniLibX window
**	t_player:			struct player
**	t_setting:			struct settings
*/

typedef struct			s_game
{
	void				*mlx;
	void				*window;
	int					screen;
	t_player			player;
	t_textures			textures[5];
}						t_game;

/*
** 	srcs/cub3d.c
*/

int						main(int argsc, char **args);

/*
** 	srcs/parser.c
*/

void					parse(t_game *vars, int argc, char **args);

#endif
