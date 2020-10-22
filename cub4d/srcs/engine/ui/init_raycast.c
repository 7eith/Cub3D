/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:16:31 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/22 23:48:49 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		initialize_raycast_texture_and_data(t_game *vars, int type)
{
	t_textures	texture;

	texture.width = 0;
	texture.height = 0;
	texture.bpp = -1;
	texture.size = -1;
	texture.endian = -1;
	texture.img = mlx_xpm_file_to_image(vars->mlx, vars->paths[type], &texture.width, &texture.height);
	if (!texture.img)
		exit_program(vars, "Failed to convert .xpm to image!");
	texture.data = (int *)mlx_get_data_addr(texture.img, &texture.bpp, &texture.size, &texture.endian);
	if (!texture.data)
		exit_program(vars, "Invalid data!");
	if (!texture.width || !texture.height)
		exit_program(vars, "Invalid size for texture.");
	vars->textures[type] = texture;
}

void		initialize_raycast_textures(t_game *vars)
{
	int			count;

	count = 0;
	while (count < TEXTURES)
		initialize_raycast_texture_and_data(vars, count++);
}

void		initialize_raycast_default_value(t_game *vars)
{
	vars->dirX = -1;
	vars->dirY = 0;
	vars->cam_plane_X = 0;
	vars->cam_plane_Y = -0.66;
	vars->raydirX = 0;
	vars->raydirY = 0;
	vars->time = 0;
	vars->old_time = 0;
	vars->sidedistX = 0;
	vars->sidedistY = 0;
	vars->deltadistX = 0;
	vars->deltadistX = 0;
	vars->perpwalldist = 0;
}

void		initialize_dir_and_cam(t_game *vars)
{
	float		rotation;

	rotation = 0;
	if (vars->pos_type == 'N')
		rotation = 3.14;
	if (vars->pos_type == 'S')
		rotation = 1.58;
	if (vars->pos_type == 'E')
		rotation = 4.71;
	vars->old_dir_x = vars->dirX;
	vars->dirX = vars->dirX * cos(-rotation) - vars->dirY * sin(-rotation);
	vars->dirY = vars->old_dir_x * sin(-rotation) + vars->dirY * cos(-rotation);
	vars->old_cam_plane_x = vars->cam_plane_X;
	vars->cam_plane_X = vars->cam_plane_X * cos(-rotation)
		- vars->cam_plane_Y * sin(-rotation);
	vars->cam_plane_Y = vars->old_cam_plane_x * sin(-rotation)
		+ vars->cam_plane_Y * cos(-rotation);
}

void		initiate_raycast_and_mlx_data(t_game *vars)
{
	initialize_raycast_default_value(vars);
	initialize_dir_and_cam(vars);
	initialize_raycast_textures(vars);
}
