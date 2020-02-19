/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:13:52 by amonteli          #+#    #+#             */
/*   Updated: 2020/02/19 05:14:22 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			up_movement(t_game *vars)
{
	int			x;
	int			y;
	float		moveSpeed;

	moveSpeed = 0.10;
	x = (int)(vars->posX + vars->dirX * moveSpeed);
	y = (int)(vars->posY);
	if (vars->map[x][y] != '1')
		vars->posX += vars->dirX * moveSpeed;
	x = (int)vars->posX;
	y = (int)(vars->posX + vars->dirX * moveSpeed);
	if (vars->map[x][y] != '1')
		vars->posX += vars->dirX * moveSpeed;
}

void			down_movement(t_game *vars)
{
	int			x;
	int			y;
	float		moveSpeed;

	moveSpeed = 0.10;
	x = (int)(vars->posX - vars->dirX * moveSpeed);
	y = (int)(vars->posY);
	if (vars->map[x][y] != '1')
		vars->posX -= vars->dirX * moveSpeed;
	x = (int)vars->posX;
	y = (int)(vars->posX - vars->dirX * moveSpeed);
	if (vars->map[x][y] != '1')
		vars->posX -= vars->dirX * moveSpeed;
}

void			left_movement(t_game *vars)
{
	float		x;
	float		y;
	float		moveSpeed;

	dprintf(1, "Call LEFTT MOVE\n");
	moveSpeed = 0.60;
	x = vars->posX - vars->dirY * moveSpeed / 2;
	y = vars->posY;
	dprintf(1, "x=%f, y=%f, ?=%d, 2?=%d\n", x, y, vars->map[(int)(y - 0.00001)][(int)x] != '1', vars->map[(int)(y + 0.00001)][(int)x] != '1');
	if (vars->map[(int)(y - 0.00001)][(int)x] != '1' && vars->map[(int)(y + 0.00001)][(int)x] != '1')
	{
		dprintf(1, "MOVE FFDP \n");
		vars->posX -= vars->dirY * moveSpeed / 2;
	}
}
