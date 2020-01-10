/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:54:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 15:35:35 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_cub3d *cube)
{
	t_settings *s;

	if (!(s = ft_calloc(1, sizeof(t_settings))))
		return ;
	s->w = -1;
	s->h = -1;
	s->flags = 0;
	cube->settings = s;
}

/*
**	1. Create settings struct
**	2. Parse settings struct
**	3.
*/

int		main(int argsc, char **args)
{
	t_cub3d		vars;

	init_struct(&vars);
	parse(&vars, argsc, args);
	return (0);
}

	// int		size_w;
	// int		size_h;


	// void		*mlx;
	// void		*window;
	// void		*img;
	// int			*data;
	// int			bpp;
	// int			endian;
	// int			size_line;

	// int			h;
	// int			w;

	// w = 0;
	// h = 0;
	// size_w = 1000;
	// size_h = 1000;

	// mlx = mlx_init();
	// window = mlx_new_window(mlx, size_w, size_h, "slt");
	// img = mlx_xpm_file_to_image(mlx, "textures/pikachu.xpm", &size_w, &size_h);
	// data = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	// mlx_put_image_to_window(mlx, window, img, 0, 0);
	// mlx_loop(mlx);

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
