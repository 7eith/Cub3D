/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:14:42 by amonteli          #+#    #+#             */
/*   Updated: 2020/02/19 01:15:55 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			assign_assets(t_game *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (ft_strchr("NSWE", vars->map[x][y]))
			{
				vars->posX = (float)x + 0.5;
				vars->posY = (float)y + 0.5;
				break ;
			}
			y++;
		}
		x++;
	}
}

void			parse(t_game *vars, char **args)
{
	int			fd;

	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		exit_programs(vars, "Failed to read file!");
	parse_configuration(vars, fd);
	read_map(vars, fd);
	check_map(vars);
	assign_assets(vars);
	close(fd);
}
