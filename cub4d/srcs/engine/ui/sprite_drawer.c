/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:47:41 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/22 23:34:34 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		apply_distance_to_sprite(t_game *vars)
{
	int			count;

	count = 0;
	while (count < vars->sprites_count) // set distance
	{
		vars->sprites[count].distance = pow(vars->posX - vars->sprites[count].pos_x, 2) + pow(vars->posY - vars->sprites[count].pos_y, 2);
		// printf("{distance=%f}\n", vars->sprites[count].distance);
		count++;
	}
}

void		sort_sprites_by_distance(t_game *vars)
{
	int			count;
	t_sprite	temp;

	count = 0;
	while (count < vars->sprites_count - 1)
	{
		if (vars->sprites[count + 1].distance > vars->sprites[count].distance)
		{
			temp = vars->sprites[count];
			vars->sprites[count] = vars->sprites[count + 1];
			vars->sprites[count + 1] = temp;
			count = -1;
		}
		count++;
	}
}

void		get_values_for_draw_sprite(t_game *vars, t_sprite sprite)
{
	vars->sprite_x = sprite.pos_x - vars->posX + 0.5;
	vars->sprite_y = sprite.pos_y - vars->posY + 0.5;

	vars->invdet = 1 / (vars->cam_plane_X * vars->dirY - vars->dirX * vars->cam_plane_Y);

	vars->transform_x = vars->invdet * (vars->dirY * vars->sprite_x - vars->dirX * vars->sprite_y);
	vars->transform_y = vars->invdet * (-vars->cam_plane_Y * vars->sprite_x + vars->cam_plane_X * vars->sprite_y);

	vars->sprite_screen_x = (int)((vars->width / 2) * (1 + vars->transform_x / vars->transform_y));

	vars->sprite_width = abs((int)(vars->wall_height / vars->transform_y));
	vars->sprite_height = abs((int)(vars->wall_height / vars->transform_y));

	vars->sprite_drawStart_x = -vars->sprite_width / 2 + vars->sprite_screen_x;
	vars->sprite_drawStart_y = -vars->sprite_height / 2 + vars->wall_height / 2;

	vars->sprite_drawEnd_x = vars->sprite_width / 2 + vars->sprite_screen_x;
	vars->sprite_drawEnd_y = vars->sprite_height / 2 + vars->wall_height / 2;

	if (vars->sprite_drawStart_x < 0)
		vars->sprite_drawStart_x = 0;

	if (vars->sprite_drawStart_y < 0)
		vars->sprite_drawStart_y = 0;

	if (vars->sprite_drawEnd_x >= vars->width)
		vars->sprite_drawEnd_x = vars->width;

	if (vars->sprite_drawEnd_y >= vars->height)
		vars->sprite_drawEnd_y = vars->height - 1;
}

void		draw_sprite(t_game *vars, t_sprite sprite)
{
	int				textureX;
	int				textureY;
	unsigned int	color;
	int				y;

	get_values_for_draw_sprite(vars, sprite);
	vars->sprite_stripe = vars->sprite_drawStart_x;

	while (vars->sprite_stripe < vars->sprite_drawEnd_x)
	{
		textureX = (int)(256 * (vars->sprite_stripe - (-vars->sprite_width / 2 + vars->sprite_screen_x)) * vars->textures[SPRITE].width / vars->sprite_width) / 256;
		y = vars->sprite_drawStart_y;

		if (vars->transform_y > 0 && vars->sprite_stripe > 0 && vars->sprite_stripe < vars->width && vars->transform_y < vars->perp_buffer[vars->sprite_stripe])
		{
			while (y < vars->sprite_drawEnd_y)
			{
				vars->sprite_d = (y) * 256 - vars->wall_height * 128 + vars->sprite_height * 128;
				textureY = ((vars->sprite_d * vars->textures[SPRITE].height) / vars->sprite_height) / 256;

				if ((vars->textures[SPRITE].height * textureY + textureX) > vars->textures[SPRITE].size)
					color = vars->textures[SPRITE].data[vars->textures[SPRITE].width * textureY + textureX];
				else
					color = 0;

				if (color > 0 && color & 0x00FFFFFF)
					vars->img_data[y * vars->width + vars->sprite_stripe] = color;

				y++;
			}
		}
		vars->sprite_stripe++;
	}
}

void		draw_sprites(t_game *vars)
{
	vars->sprite_index = 0;
	apply_distance_to_sprite(vars);
	sort_sprites_by_distance(vars);

	while (vars->sprite_index < vars->sprites_count)
	{
		draw_sprite(vars, vars->sprites[vars->sprite_index]);
		vars->sprite_index++;
	}
}