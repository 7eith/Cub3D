/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 02:20:19 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/23 12:11:37 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_mlx(t_game *vars)
{
	int		i;

	i = 0;
	while (i < TEXTURES)
	{
		if (vars->paths[i])
			free(vars->paths[i]);
		if (vars->textures[i].img)
			mlx_destroy_image(vars->mlx, vars->textures[i].img);
		i++;
	}
	mlx_destroy_image(vars->mlx, vars->img);
	free(vars->mlx);
}

void		free_all(t_game *vars)
{
	free_mlx(vars);
	if (vars->map_buf)
		free(vars->map_buf);
	if (vars->map)
		ft_clear_2d_tabs((void **)vars->map);
	if (vars->bmp)
		free(vars->bmp);
	if (vars->sprites)
		free(vars->sprites);
	free(vars);
}

void		exit_program(t_game *vars, char *reason)
{
	ft_printf("Error\n%s", reason);
	free_all(vars);
	exit(1);
}

void		clean_exit(t_game *vars)
{
	free_all(vars);
	exit(0);
}
