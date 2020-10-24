/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 05:10:26 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:26:36 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check if configurations is valid
*/

int				is_valid_configuration(t_game *vars)
{
	int			index;

	index = 0;
	if (vars->width == -1 || vars->height == -1)
		return (0);
	if (!(vars->conf & C) || !(vars->conf & F))
		return (0);
	while (index < TEXTURES)
		if (!vars->paths[index++])
			return (0);
	return (1);
}

/*
** 	Create Color from Red Green Blue
*/

t_color			create_color(int r, int g, int b)
{
	t_color		color;

	color.rgb.a = 0;
	color.rgb.r = r;
	color.rgb.g = g;
	color.rgb.b = b;
	return (color);
}

/*
**	Return Absolute number from a Float
*/

float			ft_fabs(float number)
{
	return (number < 0 ? -number : number);
}

void			assign_side(t_game *vars)
{
	if (vars->side == 0)
	{
		if (vars->mapx < vars->posx)
			vars->side = 1;
	}
	else
	{
		if (vars->mapy < vars->posy)
			vars->side = 3;
	}
}

void			sprite_fill_img_data(t_game *vars)
{
	while (vars->sprite_yi < vars->sprite_drawend_y)
	{
		vars->sprite_d = (vars->sprite_yi) * 256 - vars->wall_height
		* 128 + vars->sprite_height * 128;
		vars->sprite_texturey = ((vars->sprite_d
		* vars->textures[SPRITE].height) / vars->sprite_height) / 256;
		if ((vars->textures[SPRITE].height * vars->sprite_texturey
		+ vars->sprite_texturex) > vars->textures[SPRITE].size)
			vars->sprite_color =
			vars->textures[SPRITE].data[vars->textures[SPRITE].width
			* vars->sprite_texturey + vars->sprite_texturex];
		else
			vars->sprite_color = 0;
		if (vars->sprite_color > 0 && vars->sprite_color & 0x00FFFFFF)
			vars->img_data[vars->sprite_yi
			* vars->width + vars->sprite_stripe] = vars->sprite_color;
		vars->sprite_yi++;
	}
}
