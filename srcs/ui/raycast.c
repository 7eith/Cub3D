/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 02:04:59 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 00:57:55 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void						debug_ui(t_game *vars)
{
	// printf("[Position]  X=%f, Y=%f\n", vars->posX, vars->posY);
}

int				raycast(t_game *vars)
{
	int		x = 0;			// raycast index (for send x pixels)
	int		y = 50;

	while (x < vars->width)
	{
		// printf("X=%d\n", x);
		mlx_pixel_put(vars->mlx, vars->window, x, y, vars->colors[SKY].c);
		x++;
	}
	return (1);
}