/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:06:04 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/18 06:27:53 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rotate_player_camera_to_left(t_game *vars)
{
	vars->old_dir_x = vars->dirX;

	vars->dirX = vars->dirX * cos(-vars->rotation_speed) - vars->dirY * sin(-vars->rotation_speed);
	vars->dirY = vars->old_dir_x * sin(-vars->rotation_speed) + vars->dirY * cos(-vars->rotation_speed);

	vars->old_cam_plane_x = vars->cam_plane_X;

	vars->cam_plane_X = vars->cam_plane_X * cos(-vars->rotation_speed) - vars->cam_plane_Y * sin(-vars->rotation_speed);
	vars->cam_plane_Y = vars->old_cam_plane_x * sin(-vars->rotation_speed) + vars->cam_plane_Y * cos(-vars->rotation_speed);
}

void		rotate_player_camera_to_right(t_game *vars)
{
	vars->old_dir_x = vars->dirX;

	vars->dirX = vars->dirX * cos(vars->rotation_speed) - vars->dirY * sin(vars->rotation_speed);
	vars->dirY = vars->old_dir_x * sin(vars->rotation_speed) + vars->dirY * cos(vars->rotation_speed);

	vars->old_cam_plane_x = vars->cam_plane_X;

	vars->cam_plane_X = vars->cam_plane_X * cos(vars->rotation_speed) - vars->cam_plane_Y * sin(vars->rotation_speed);
	vars->cam_plane_Y = vars->old_cam_plane_x * sin(vars->rotation_speed) + vars->cam_plane_Y * cos(vars->rotation_speed);
}
