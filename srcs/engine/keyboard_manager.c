/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:47:07 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/18 06:09:32 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_loop_controller(t_game *vars)
{
	if (vars->key & MV_LEFT)
		move_player_left(vars);
	if (vars->key & MV_RIGHT)
		move_player_right(vars);
	if (vars->key & MV_UP)
		move_player_up(vars);
	if (vars->key & MV_DOWN)
		move_player_down(vars);
	if (vars->key & LEFT)
		rotate_player_camera_to_left(vars);
	if (vars->key & RIGHT)
		rotate_player_camera_to_right(vars);
	return (1);
}

int				key_press(int key_code, t_game *vars)
{
	if (key_code == KEY_ESCAPE)
		close_window(vars);
	if (key_code == KEY_MOVE_UP)
		vars->key |= MV_UP;
	if (key_code == KEY_MOVE_DOWN)
		vars->key |= MV_DOWN;
	if (key_code == KEY_MOVE_LEFT)
		vars->key |= MV_LEFT;
	if (key_code == KEY_MOVE_RIGHT)
		vars->key |= MV_RIGHT;
	if (key_code == KEY_LEFT)
		vars->key |= LEFT;
	if (key_code == KEY_RIGHT)
		vars->key |= RIGHT;
	return (0);
}

int				key_release(int key_code, t_game *vars)
{
	if (key_code == KEY_ESCAPE)
		close_window(vars);
	if (key_code == KEY_MOVE_UP)
		vars->key &= ~MV_UP;
	if (key_code == KEY_MOVE_DOWN)
		vars->key &= ~MV_DOWN;
	if (key_code == KEY_MOVE_LEFT)
		vars->key &= ~MV_LEFT;
	if (key_code == KEY_MOVE_RIGHT)
		vars->key &= ~MV_RIGHT;
	if (key_code == KEY_LEFT)
		vars->key &= ~LEFT;
	if (key_code == KEY_RIGHT)
		vars->key &= ~RIGHT;
	return (0);
}
