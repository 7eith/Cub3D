/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 02:07:43 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 05:07:50 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				close_window(t_game *vars)
{
	exit(1);
}

int				open_window(t_game *vars)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3D");

	mlx_loop_hook(vars->mlx, &raycast, (void *)vars);
	mlx_hook(vars->window, 17, 0, &close_window, (void *)vars);
	mlx_loop(vars->mlx);
	return (1);
}