/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:16:31 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:04:01 by amonteli         ###   ########lyon.fr   */
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
	texture.img = mlx_xpm_file_to_image(vars->mlx, vars->paths[type],
	&texture.width, &texture.height);
	if (!texture.img)
		exit_program(vars, "Failed to convert .xpm to image!");
	texture.data = (int *)mlx_get_data_addr(texture.img, &texture.bpp,
	&texture.size, &texture.endian);
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
	vars->dirx = -1;
	vars->diry = 0;
	vars->cam_plane_x = 0;
	vars->cam_plane_y = -0.66;
	vars->raydirx = 0;
	vars->raydiry = 0;
	vars->time = 0;
	vars->old_time = 0;
	vars->sidedistx = 0;
	vars->sidedisty = 0;
	vars->deltadistx = 0;
	vars->deltadistx = 0;
	vars->perpwalldist = 0;
}

void		initialize_dir_and_cam(t_game *vars)
{
	float		rotation;

	rotation = 0;
	if (vars->pos_type == 'W')
		rotation = 4.71;
	if (vars->pos_type == 'S')
		rotation = 3.14;
	if (vars->pos_type == 'E')
		rotation = 1.58;
	vars->old_dir_x = vars->dirx;
	vars->dirx = vars->dirx * cos(-rotation) - vars->diry * sin(-rotation);
	vars->diry = vars->old_dir_x * sin(-rotation) + vars->diry * cos(-rotation);
	vars->old_cam_plane_x = vars->cam_plane_x;
	vars->cam_plane_x = vars->cam_plane_x * cos(-rotation)
		- vars->cam_plane_y * sin(-rotation);
	vars->cam_plane_y = vars->old_cam_plane_x * sin(-rotation)
		+ vars->cam_plane_y * cos(-rotation);
}

void		initiate_raycast_and_mlx_data(t_game *vars)
{
	initialize_raycast_default_value(vars);
	initialize_dir_and_cam(vars);
	initialize_raycast_textures(vars);
}
