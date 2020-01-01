/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:55:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 06:39:55 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

enum
{
	ST_SAVE = (1 << 0)
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
}						t_settings;

/*
**	mlx_p: 				MiniLibX pointer
**	mlx_w:				MiniLibX window
**	t_player:			struct player
**	t_setting:			struct settings
*/

typedef struct 			s_cub3d
{
	void				*mlx_p;
	void				*mlx_w;
	t_player			*player;
	t_settings			*settings;
}						t_cub3d;

/*
** 	srcs/cub3d.c
*/

int						main(int argsc, char **args);

/*
** 	srcs/parser.c
*/

void					parse(t_settings *settings, int argc, char **args);

#endif
