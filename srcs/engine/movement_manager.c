/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:42:30 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:02:33 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_player_left(t_game *vars)
{
	float	x;
	float	y;

	x = vars->posx + vars->diry * vars->move_speed / 2;
	y = vars->posy;
	if (vars->map[(int)x][(int)y] == '0'
	|| vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posx += vars->diry * vars->move_speed / 2;
	x = vars->posx;
	y = vars->posy - vars->dirx * vars->move_speed / 2;
	if (vars->map[(int)x][(int)y] == '0'
	|| vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posy -= vars->dirx * vars->move_speed / 2;
}

void		move_player_right(t_game *vars)
{
	float	x;
	float	y;

	x = vars->posx - vars->diry * vars->move_speed / 2;
	y = vars->posy;
	if (vars->map[(int)x][(int)y] == '0'
	|| vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posx -= vars->diry * vars->move_speed / 2;
	x = vars->posx;
	y = vars->posy + vars->dirx * vars->move_speed / 2;
	if (vars->map[(int)x][(int)y] == '0'
	|| vars->map[(int)x][(int)y] == vars->pos_type)
		vars->posy += vars->dirx * vars->move_speed / 2;
}

void		move_player_up(t_game *vars)
{
	int		x;
	int		y;

	x = (int)(vars->posx + vars->dirx * vars->move_speed);
	y = (int)(vars->posy);
	if (vars->map[x][y] == '0' || vars->map[x][y] == vars->pos_type)
		vars->posx += vars->dirx * vars->move_speed;
	x = (int)vars->posx;
	y = (int)(vars->posy + vars->diry * vars->move_speed);
	if (vars->map[x][y] == '0' || vars->map[x][y] == vars->pos_type)
		vars->posy += vars->diry * vars->move_speed;
}

void		move_player_down(t_game *vars)
{
	int		x;
	int		y;

	x = (int)(vars->posx - vars->dirx * vars->move_speed);
	y = (int)(vars->posy);
	if (vars->map[x][y] == '0' || vars->map[x][y] == vars->pos_type)
		vars->posx -= vars->dirx * vars->move_speed;
	x = (int)vars->posx;
	y = (int)(vars->posy - vars->diry * 0.06);
	if (vars->map[x][y] == '0' || vars->map[x][y] == vars->pos_type)
		vars->posy -= vars->diry * vars->move_speed;
}
