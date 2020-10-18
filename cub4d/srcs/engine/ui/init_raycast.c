/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:16:31 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/18 05:37:15 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	float	rotation;

	rotation = 0;
	if (vars->pos_type == 'N')
		rotation = 4.71;
	if (vars->pos_type == 'S')
		rotation = 1.58;
	if (vars->pos_type == 'E')
		rotation = 3.14;
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
}
