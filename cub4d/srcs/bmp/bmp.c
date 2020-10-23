/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:13:23 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/23 12:03:03 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_bmp_data(t_game *vars)
{
	if (!(vars->bmp = malloc(sizeof(t_bmp))))
		exit_program(vars, "Failed alloc to BMP");
	ft_bzero(vars->bmp->header, 54);

	vars->bmp->width = vars->width;
	vars->bmp->height = vars->height;
	vars->bmp->bytes_count = 32;
	vars->bmp->width_in_bytes = ((vars->bmp->width * vars->bmp->bytes_count + 31) / 32) * 4;
	vars->bmp->image_size = vars->bmp->width_in_bytes * vars->bmp->height;
	vars->bmp->bytes_size = 40;
	vars->bmp->bfoffbits = 54;
	vars->bmp->file_size = 54 + vars->bmp->image_size;
	vars->bmp->biplanes = 1;
}

void		fill_header(t_game *vars)
{
	ft_memcpy(vars->bmp->header, "BM", 2);
	ft_memcpy(vars->bmp->header + 2,  &vars->bmp->file_size, 4);
	ft_memcpy(vars->bmp->header + 10, &vars->bmp->bfoffbits, 4);
	ft_memcpy(vars->bmp->header + 14, &vars->bmp->bytes_size, 4);
	ft_memcpy(vars->bmp->header + 18, &vars->bmp->width, 4);
	ft_memcpy(vars->bmp->header + 22, &vars->bmp->height, 4);
	ft_memcpy(vars->bmp->header + 26, &vars->bmp->biplanes, 4);
	ft_memcpy(vars->bmp->header + 28, &vars->bmp->bytes_count, 4);
	ft_memcpy(vars->bmp->header + 34, &vars->bmp->image_size, 4);

	vars->bmp->fd = open("./capture.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
}

void		init_bmp(t_game *vars)
{
	init_bmp_data(vars);
	fill_header(vars);
}

void		save_bmp(t_game *vars)
{
	int		height_to_write;

	height_to_write = vars->bmp->height;
	write(vars->bmp->fd, vars->bmp->header, 54);
	while (height_to_write)
	{
		write(vars->bmp->fd, vars->img_data + (height_to_write * vars->bmp->width), vars->bmp->width * 4);
		height_to_write--;
	}
	close(vars->bmp->fd);
	// mlx_destroy_image()
	clean_exit(vars);
}
