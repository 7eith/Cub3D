/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:07:43 by amonteli          #+#    #+#             */
/*   Updated: 2020/07/28 01:42:45 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"


int				close_window(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	exit(1);
}

int				open_window(t_game *vars)
{
	int		bits;
	int		line_size;
	int		endian;

	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3D");
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img_data = (int *)mlx_get_data_addr(vars->img, &bits, &line_size, &endian);

	mlx_loop_hook(vars->mlx, &raycast, vars);
	mlx_hook(vars->window, 2, 2, &key_press, vars);
	mlx_hook(vars->window, 3, 2, &key_release, vars);
	mlx_hook(vars->window, 17, 1, close_window, vars);
	mlx_hook(vars->window, 33, 1L << 17, close_window, vars);
	mlx_loop(vars->mlx);
	return (1);
}
