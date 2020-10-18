/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:42:30 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/18 06:05:10 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_player_left(t_game *vars)
{
	float	x;
	float	y;

	x = vars->posX + vars->dirY * vars->move_speed / 2;
	y = vars->posY;

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posX += vars->dirY * vars->move_speed / 2;

	x = vars->posX;
	y = vars->posY - vars->dirX * vars->move_speed / 2;

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posY -= vars->dirX * vars->move_speed / 2;
}

void		move_player_right(t_game *vars)
{
	float	x;
	float	y;

	x = vars->posX - vars->dirY * vars->move_speed / 2;
	y = vars->posY;

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posX -= vars->dirY * vars->move_speed / 2;

	x = vars->posX;
	y = vars->posY + vars->dirX * vars->move_speed / 2;

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posY += vars->dirX * vars->move_speed / 2;
}

void		move_player_up(t_game *vars)
{
	int		x;
	int		y;

	x = (int)(vars->posX + vars->dirX * vars->move_speed);
	y = (int)(vars->posY);

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posX += vars->dirX * vars->move_speed;

	x = (int)vars->posX;
	y = (int)(vars->posY + vars->dirY * 0.06);

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posY += vars->dirY * vars->move_speed;
}

void		move_player_down(t_game *vars)
{
	int		x;
	int		y;

	x = (int)(vars->posX - vars->dirX * vars->move_speed);
	y = (int)(vars->posY);

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posX -= vars->dirX * vars->move_speed;

	x = (int)vars->posX;
	y = (int)(vars->posY - vars->dirY * 0.06);

	if (vars->map[(int)x][(int)y] == '0' || vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posY -= vars->dirY * vars->move_speed;
}
