/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:25:57 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/08 22:13:27 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: remove it only for debug purpose
void						debug_parser(t_game *vars)
{

	printf("_______________________________________________\n\n");
	printf("[R]  Width=%d, Height=%d\n", vars->width, vars->height);
	printf("[F]  R=%d, G=%d, B=%d\n", vars->colors[FLOOR].rgb.r, vars->colors[FLOOR].rgb.g, vars->colors[FLOOR].rgb.b);
	printf("[C]  R=%d, G=%d, B=%d\n", vars->colors[SKY].rgb.r, vars->colors[SKY].rgb.g, vars->colors[SKY].rgb.b);
	printf("[NO] Path=%s\n", vars->paths[NORTH]);
	printf("[SO] Path=%s\n", vars->paths[SOUTH]);
	printf("[WE] Path=%s\n", vars->paths[WEST]);
	printf("[EA] Path=%s\n", vars->paths[EAST]);
	printf("[S]  Path=%s\n", vars->paths[SPRITE]);

	printf("_______________________________________________\n\n");
	int		index;

	index = 0;
	if (vars->map)
		while (vars->map[index])
			printf("{%s}\n", vars->map[index++]);

	printf("_______________________________________________\n\n");

	printf("[POS] x=%f, y=%f\n", vars->posX, vars->posY);
}

void		parse_file(t_game *vars, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_program(vars, "Failed to read file!");
	parse_configuration(vars, fd);
	parse_map(vars, fd);
	// debug_parser(vars);
}
