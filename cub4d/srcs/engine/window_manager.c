/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:19:30 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 02:55:37 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			close_window(t_game *vars)
{
	clean_exit(vars);
	return (1);
}

void		open_window(t_game *vars)
{
	int		bits;
	int		line_size;
	int		endian;

	initiate_raycast_and_mlx_data(vars);
	vars->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img_data =
	(int *)mlx_get_data_addr(vars->img, &bits, &line_size, &endian);
	if (vars->screen)
	{
		init_bmp(vars);
		raycast(vars);
	}
	vars->window =
	mlx_new_window(vars->mlx, vars->width, vars->height, "Cub3D");
	mlx_loop_hook(vars->mlx, &raycast, vars);
	mlx_hook(vars->window, 2, 2, &key_press, vars);
	mlx_hook(vars->window, 3, 2, &key_release, vars);
	mlx_hook(vars->window, 17, 1, close_window, vars);
	mlx_hook(vars->window, 33, 1L << 17, close_window, vars);
	mlx_loop(vars->mlx);
}
