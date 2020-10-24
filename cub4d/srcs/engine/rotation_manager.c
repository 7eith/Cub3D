/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:06:04 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:02:59 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rotate_player_camera_to_left(t_game *vars)
{
	vars->old_dir_x = vars->dirx;
	vars->dirx = vars->dirx * cos(-vars->rotation_speed)
	- vars->diry * sin(-vars->rotation_speed);
	vars->diry = vars->old_dir_x * sin(-vars->rotation_speed)
	+ vars->diry * cos(-vars->rotation_speed);
	vars->old_cam_plane_x = vars->cam_plane_x;
	vars->cam_plane_x = vars->cam_plane_x * cos(-vars->rotation_speed)
	- vars->cam_plane_y * sin(-vars->rotation_speed);
	vars->cam_plane_y = vars->old_cam_plane_x * sin(-vars->rotation_speed)
	+ vars->cam_plane_y * cos(-vars->rotation_speed);
}

void		rotate_player_camera_to_right(t_game *vars)
{
	vars->old_dir_x = vars->dirx;
	vars->dirx = vars->dirx * cos(vars->rotation_speed)
	- vars->diry * sin(vars->rotation_speed);
	vars->diry = vars->old_dir_x * sin(vars->rotation_speed)
	+ vars->diry * cos(vars->rotation_speed);
	vars->old_cam_plane_x = vars->cam_plane_x;
	vars->cam_plane_x = vars->cam_plane_x * cos(vars->rotation_speed)
	- vars->cam_plane_y * sin(vars->rotation_speed);
	vars->cam_plane_y = vars->old_cam_plane_x * sin(vars->rotation_speed)
	+ vars->cam_plane_y * cos(vars->rotation_speed);
}
