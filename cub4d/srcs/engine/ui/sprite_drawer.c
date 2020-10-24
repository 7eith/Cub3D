/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:47:41 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:24:44 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		apply_distance_to_sprite(t_game *vars)
{
	int			count;

	count = 0;
	while (count < vars->sprites_count)
	{
		vars->sprites[count].distance = pow(vars->posx
		- vars->sprites[count].pos_x, 2)
		+ pow(vars->posy - vars->sprites[count].pos_y, 2);
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
	vars->sprite_x = sprite.pos_x - vars->posx + 0.5;
	vars->sprite_y = sprite.pos_y - vars->posy + 0.5;
	vars->invdet = 1 / (vars->cam_plane_x
	* vars->diry - vars->dirx * vars->cam_plane_y);
	vars->transform_x = vars->invdet *
	(vars->diry * vars->sprite_x - vars->dirx * vars->sprite_y);
	vars->transform_y = vars->invdet *
	(-vars->cam_plane_y * vars->sprite_x + vars->cam_plane_x * vars->sprite_y);
	vars->sprite_screen_x = (int)((vars->width / 2)
	* (1 + vars->transform_x / vars->transform_y));
	vars->sprite_width = abs((int)(vars->wall_height / vars->transform_y));
	vars->sprite_height = abs((int)(vars->wall_height / vars->transform_y));
	vars->sprite_drawstart_x = -vars->sprite_width / 2 + vars->sprite_screen_x;
	vars->sprite_drawstart_y = -vars->sprite_height / 2 + vars->wall_height / 2;
	vars->sprite_drawend_x = vars->sprite_width / 2 + vars->sprite_screen_x;
	vars->sprite_drawend_y = vars->sprite_height / 2 + vars->wall_height / 2;
	if (vars->sprite_drawstart_x < 0)
		vars->sprite_drawstart_x = 0;
	if (vars->sprite_drawstart_y < 0)
		vars->sprite_drawstart_y = 0;
	if (vars->sprite_drawend_x >= vars->width)
		vars->sprite_drawend_x = vars->width;
	if (vars->sprite_drawend_y >= vars->height)
		vars->sprite_drawend_y = vars->height - 1;
}

void		draw_sprite(t_game *vars, t_sprite sprite)
{
	get_values_for_draw_sprite(vars, sprite);
	vars->sprite_stripe = vars->sprite_drawstart_x;
	while (vars->sprite_stripe < vars->sprite_drawend_x)
	{
		vars->sprite_texturex = (int)(256 * (vars->sprite_stripe -
		(-vars->sprite_width / 2 + vars->sprite_screen_x))
		* vars->textures[SPRITE].width / vars->sprite_width) / 256;
		vars->sprite_yi = vars->sprite_drawstart_y;
		if (vars->transform_y > 0 && vars->sprite_stripe > 0
		&& vars->sprite_stripe < vars->width
		&& vars->transform_y < vars->perp_buffer[vars->sprite_stripe])
			sprite_fill_img_data(vars);
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
