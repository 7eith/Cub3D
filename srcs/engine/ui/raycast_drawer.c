/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 03:58:43 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:57:48 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycast_draw_walls(t_game *vars)
{
	t_textures	texture;

	texture = vars->textures[vars->side];
	if (vars->side == 0 || vars->side == 1)
		vars->wallx = vars->posy + vars->perpwalldist * vars->raydiry;
	else
		vars->wallx = vars->posx + vars->perpwalldist * vars->raydirx;
	vars->wallx -= floorf(vars->wallx);
	vars->texturex = (int)(vars->wallx * (float)texture.width);
	if (vars->side == 0 && vars->raydirx > 0)
		vars->texturex = texture.width - vars->texturex - 1;
	if (vars->side == 1 && vars->raydirx < 0)
		vars->texturex = texture.width - vars->texturex - 1;
	vars->step = 1.0 * texture.height / vars->lineheight;
	vars->texturepos = (vars->drawstart - vars->wall_height / 2
	+ vars->lineheight / 2) * vars->step;
	while (vars->drawstart < vars->drawend)
	{
		vars->texturey = (int)vars->texturepos;
		vars->texturepos += vars->step;
		vars->img_data[vars->drawstart++ * vars->width + (int)vars->x] =
		texture.data[texture.width * (int)vars->texturey + vars->texturex];
	}
}

void			raycast_draw(t_game *vars)
{
	int			i;

	i = 0;
	while (i < vars->drawstart)
	{
		vars->img_data[i * vars->width + (int)vars->x] = vars->colors[SKY].c;
		i++;
	}
	raycast_draw_walls(vars);
	i = vars->drawend;
	while (i < vars->height - 1)
	{
		vars->img_data[i * vars->width + (int)vars->x] = vars->colors[FLOOR].c;
		i++;
	}
}
