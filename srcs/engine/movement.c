/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:13:52 by amonteli          #+#    #+#             */
/*   Updated: 2020/07/23 08:37:46 by amonteli         ###   ########lyon.fr   */
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
	x = vars->posX + vars->dirY * moveSpeed / 2;
	y = vars->posY;

	if (vars->map[(int)(x)][(int)y] == '0' || vars->map[(int)(x)][(int)y] == 'N')
		vars->posX -= vars->dirY * moveSpeed / 2;
	y = vars->posY - vars->dirX * moveSpeed / 2;
	x = vars->posX;
	if (vars->map[(int)(x)][(int)y] == '0' || vars->map[(int)(x)][(int)y] == 'N')
		vars->posY += vars->dirX * moveSpeed / 2;
}
