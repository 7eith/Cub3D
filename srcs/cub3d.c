/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:54:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 07:03:15 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_settings(t_settings *settings)
{
	settings->flags = 0;
}

/*
**	1. Create settings struct
**	2. Parse settings struct
**	3.
*/

int		main(int argsc, char **args)
{
	t_settings		settings;
	int				loop = 100;


	init_settings(&settings);
	parse(&settings, argsc, args);
}

// set color lol
	// get color : settings.color.c
	// settings->color.rgb.a = 0;
	// settings->color.rgb.r = 0;
	// settings->color.rgb.b = 191;
	// settings->color.rgb.g = 255;
// enjoy mlx lol
	// settings.mlx_ptr = mlx_init();
	// settings.mlx_wdw = mlx_new_window(settings.mlx_ptr, 1000, 1000, "Cub3D");
	// // if (settings.flags & ST_SAVE)
	// // 	return (printf("need to create bmp image!"));
	// while (loop < 500)
	// {
	// 	mlx_pixel_put(settings.mlx_ptr, settings.mlx_wdw, loop, loop, settings.color.c);
	// 	loop++;
	// }
	// mlx_loop(settings.mlx_ptr);
	// return (0);
