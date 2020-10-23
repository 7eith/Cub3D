/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:25:57 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/23 12:13:56 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_player_in_map(t_game *vars)
{
	int		x;
	int		y;
	int		found;

	x = 0;
	y = 0;
	found = 0;
	while (vars->map[x] && !found)
	{
		while (vars->map[x][y])
		{
			if (ft_strchr(MAP_POSITION_TYPE, vars->map[x][y]))
			{
				vars->posX = (float)x + 0.5;
				vars->posY = (float)y + 0.5;
				found = 1;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (!found)
		exit_program(vars, "No player in map!");
}

void		parse_file(t_game *vars, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_program(vars, "Failed to read file!");
	parse_configuration(vars, fd);
	parse_map(vars, fd);
	close(fd);
	set_player_in_map(vars);
	parse_sprite(vars);
}
