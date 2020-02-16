/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:07:43 by amonteli          #+#    #+#             */
/*   Updated: 2020/02/17 00:53:02 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

int				key_press(int key, t_game *vars)
{
	if (key == 126 && vars->posX > 2.50)
	{
		vars->posX += vars->dirX * 0.90;
	}
	if (key == 125)
	{
		vars->posX -= vars->dirX * 0.90;
	}
}

int				key_release(int key,t_game *vars)
{

}

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

	mlx_loop_hook(vars->mlx, &raycast, (void *)vars);
	mlx_hook(vars->window, 17, 0, &close_window, (void *)vars);
	mlx_hook(vars->window, 2, 0, &key_press, (void *)vars);
	mlx_hook(vars->window, 3, 0, &key_release, (void *)vars);
	mlx_loop(vars->mlx);
	return (1);
}
