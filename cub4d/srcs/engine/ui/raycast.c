/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 06:22:39 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:21:36 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycast_init_values(t_game *vars)
{
	vars->camerax = 2 * vars->x / (float)vars->width - 1;
	vars->raydirx = vars->dirx + vars->cam_plane_x * vars->camerax;
	vars->raydiry = vars->diry + vars->cam_plane_y * vars->camerax;
	vars->mapx = (int)vars->posx;
	vars->mapy = (int)vars->posy;
	vars->deltadistx = ft_fabs(1 / vars->raydirx);
	vars->deltadisty = ft_fabs(1 / vars->raydiry);
	vars->hit = 0;
}

void			raycast_get_steps(t_game *vars)
{
	if (vars->raydirx < 0)
	{
		vars->stepx = -1;
		vars->sidedistx = (vars->posx - vars->mapx) * vars->deltadistx;
	}
	else
	{
		vars->stepx = 1;
		vars->sidedistx = (vars->mapx + 1.0 - vars->posx) * vars->deltadistx;
	}
	if (vars->raydiry < 0)
	{
		vars->stepy = -1;
		vars->sidedisty = (vars->posy - vars->mapy) * vars->deltadisty;
	}
	else
	{
		vars->stepy = 1;
		vars->sidedisty = (vars->mapy + 1.0 - vars->posy) * vars->deltadisty;
	}
}

void			raycast_hit(t_game *vars)
{
	while (!vars->hit)
	{
		if (vars->sidedistx < vars->sidedisty)
		{
			vars->sidedistx += vars->deltadistx;
			vars->mapx += vars->stepx;
			vars->side = 0;
		}
		else
		{
			vars->sidedisty += vars->deltadisty;
			vars->mapy += vars->stepy;
			vars->side = 2;
		}
		if (vars->map[vars->mapx][vars->mapy] == '1')
			vars->hit = 1;
	}
	assign_side(vars);
}

void			raycast_get_values_for_sky_and_floor(t_game *vars)
{
	if (vars->side == 0 || vars->side == 1)
		vars->perpwalldist =
		(vars->mapx - vars->posx + (1 - vars->stepx) / 2) / vars->raydirx;
	else
		vars->perpwalldist =
		(vars->mapy - vars->posy + (1 - vars->stepy) / 2) / vars->raydiry;
	vars->lineheight = (long int)(vars->wall_height / vars->perpwalldist);
	vars->drawstart = -vars->lineheight / 2 + vars->wall_height / 2;
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->lineheight / 2 + vars->wall_height / 2;
	if (vars->drawend >= vars->height)
		vars->drawend = vars->height - 1;
}

int				raycast(t_game *vars)
{
	vars->x = 0;
	vars->wall_height = vars->height / 1.35;
	vars->perp_buffer = malloc(sizeof(float) * vars->width);
	while (vars->x < vars->width)
	{
		raycast_init_values(vars);
		raycast_get_steps(vars);
		raycast_hit(vars);
		raycast_get_values_for_sky_and_floor(vars);
		raycast_draw(vars);
		vars->perp_buffer[(int)vars->x] = vars->perpwalldist;
		vars->x++;
	}
	draw_sprites(vars);
	key_loop_controller(vars);
	free(vars->perp_buffer);
	if (vars->screen)
		save_bmp(vars);
	mlx_clear_window(vars->mlx, vars->window);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	mlx_do_sync(vars->mlx);
	return (1);
}
