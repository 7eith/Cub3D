/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 03:58:43 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/21 17:06:15 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycast_draw_walls(t_game *vars)
{
	t_textures	texture;
	float		wallX;
	int			textureX;
	float		step;
	float		texturePos;
	float		textureY;

	texture = vars->textures[vars->side];
	if (vars->side == 0 || vars->side == 1)
		wallX = vars->posY + vars->perpwalldist * vars->raydirY;
	else
		wallX = vars->posX + vars->perpwalldist * vars->raydirX;

	wallX -= floorf(wallX);
	textureX = (int)(wallX * (float)texture.width);

	if (vars->side == 0 && vars->raydirX > 0)
		textureX = texture.width - textureX - 1;
	if (vars->side == 1 && vars->raydirX < 0)
		textureX = texture.width - textureX - 1;

	step = 1.0 * texture.height / vars->lineheight;
	texturePos = (vars->drawstart - vars->wall_height / 2 + vars->lineheight / 2) * step;

	while (vars->drawstart < vars->drawend)
	{
		textureY = (int)texturePos;
		texturePos += step;
		vars->img_data[vars->drawstart++ * vars->width + (int)vars->x] = texture.data[texture.width * (int)textureY + textureX];
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
