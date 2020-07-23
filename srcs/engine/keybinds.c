/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:13:26 by amonteli          #+#    #+#             */
/*   Updated: 2020/07/23 04:13:14 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			key_manager(t_game *vars)
{
	if (vars->key & UP)
		up_movement(vars);
	if (vars->key & DOWN)
		down_movement(vars);
	if (vars->key & MV_LEFT)
		left_movement(vars);
}

int				key_press(int key_code, t_game *vars)
{
	if (key_code == ESCAPE)
		exit_programs(vars, "Exited successfully");
	if (key_code == R_UP)
		vars->key |= UP;
	if (key_code == R_DOWN)
		vars->key |= DOWN;
	if (key_code == R_MVLEFT)
	{
		dprintf(1, "MV LEFT\n");
		vars->key |= MV_LEFT;
	}
	if (key_code == R_MVRIGHT)
		vars->key |= MV_RIGHT;
	if (key_code == R_LEFT)
		vars->key |= LEFT;
	if (key_code == R_RIGHT)
		vars->key |= RIGHT;
	return (0);
}

int				key_release(int key_code, t_game *vars)
{
	if (key_code == R_UP)
		vars->key &= ~UP;
	if (key_code == R_DOWN)
		vars->key &= ~DOWN;
	if (key_code == R_MVLEFT)
	{
		dprintf(1, "MV LEFT\n");
		vars->key &= ~MV_LEFT;
	}
	if (key_code == R_MVRIGHT)
		vars->key &= ~MV_RIGHT;
	if (key_code == R_LEFT)
		vars->key &= ~LEFT;
	if (key_code == R_RIGHT)
		vars->key &= ~RIGHT;
	return (0);
}
