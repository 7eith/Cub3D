/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:26:55 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/19 02:27:19 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game						*init_vars(void)
{
	t_game		*vars;
	int			index;

	index = 0;
	if (!(vars = malloc(sizeof(t_game))))
		return (NULL);
	vars->width = -1;
	vars->height = -1;
	vars->conf = 0;
	vars->screen = 0;
	vars->map_buf = NULL;
	vars->map = NULL;
	vars->mlx = mlx_init();
	vars->move_speed = 0.16f;
	vars->rotation_speed = 0.16f;
	vars->pos_type = 0;
	vars->key = 0;
	while (index < TEXTURES)
		vars->paths[index++] = NULL;
	return (vars);
}

int							main(int argsc, char **args)
{
	t_game		*vars;

	if (!(vars = init_vars()))
		return (0);
	check_params(vars, argsc, args);
	parse_file(vars, vars->screen ? args[2] : args[1]);
	if (!vars->screen)
		open_window(vars);
	exit_program(vars, "Success launched! Closed.");
	return (0);
}
