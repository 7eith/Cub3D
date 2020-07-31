/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:13:26 by amonteli          #+#    #+#             */
/*   Updated: 2020/07/28 01:41:06 by amonteli         ###   ########lyon.fr   */
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
	if (vars->key & MV_RIGHT)
		right_movement(vars);
}

int				key_press(int key_code, t_game *vars)
{
	printf("%d\n", key_code);
	if (key_code == 65307)
		exit_programs(vars, "Exited successfully");
	if (key_code == 119)
		vars->key |= UP;
	if (key_code == 115)
		vars->key |= DOWN;
	if (key_code == 97)
		vars->key |= MV_LEFT;
	if (key_code == 100)
		vars->key |= MV_RIGHT;
	if (key_code == 65361)
		vars->key |= LEFT;
	if (key_code == 65307)
		vars->key |= RIGHT;
	return (0);
}

int				key_release(int key_code, t_game *vars)
{
	if (key_code == 119)
		vars->key &= ~UP;
	if (key_code == 115)
		vars->key &= ~DOWN;
	if (key_code == 97)
		vars->key &= ~MV_LEFT;
	if (key_code == 100)
		vars->key &= ~MV_RIGHT;
	if (key_code == 65361)
		vars->key &= ~LEFT;
	if (key_code == 65307)
		vars->key &= ~RIGHT;
	return (0);
}
