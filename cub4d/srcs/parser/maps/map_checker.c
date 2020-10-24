/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:13:38 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 03:55:22 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_around_position(char **map, int x, int y, int corner)
{
	if (x > 0 && y > 0 && map[x - 1][y] && map[x - 1][y] != '1')
		return (0);
	if (x > 0 && y > 0 && map[x + 1][y] && map[x + 1][y] != '1')
		return (0);
	if (corner == 1)
	{
		if (x > 0 && y > 0 && map[x][y - 1] && map[x][y - 1] != '1')
			return (0);
	}
	else if (corner == 2)
	{
		if (x > 0 && y > 0 && map[x][y + 1] && map[x][y + 1] != '1')
			return (0);
	}
	return (1);
}

void		check_arounds(t_game *vars, char **map, int x, int count)
{
	int		was_call;

	was_call = 0;
	while (map[x][count])
	{
		if (map[x][count] != ' ' && was_call == 1)
			was_call = 2;
		if (map[x][count] == ' ')
		{
			if (was_call == 0 && (was_call = 1))
				if (!check_around_position(map, x, count, 1))
					exit_program(vars, "Failed to check around pos!");
			if (was_call == 1)
			{
				if (!check_around_position(map, x, count, 0))
					exit_program(vars, "Failed to check around pos!");
			}
			if (was_call == 2 && !check_around_position(map, x, count, 2))
				exit_program(vars, "Failed to check around pos!");
		}
		count++;
	}
}

void		is_valid_line(t_game *vars, char **map, int x)
{
	int		count;

	count = -1;
	if (x == 0)
		while (map[x][++count])
			if (map[x][count] != '1' && map[x][count] != ' ')
				exit_program(vars, "First line invalid!");
	count = 0;
	while (map[x][count] == ' ')
		count++;
	if (map[x][count] != '1')
		exit_program(vars, "Line doesn't start by wall!");
	check_arounds(vars, map, x, count);
	while (map[x][count])
		count++;
	if (map[x][count - 1] != '1')
		exit_program(vars, "Line doesn't end by wall!");
}

void		check_map_integrity(t_game *vars, char **map)
{
	int		count;
	int		cursor;

	count = 0;
	cursor = 0;
	while (map[count])
	{
		is_valid_line(vars, map, count);
		check_map_hole(vars, map, count, ft_strlen(map[count]));
		count++;
	}
	count--;
	while (map[count][cursor])
	{
		if (map[count][cursor] != '1' && map[count][cursor] != ' ')
			exit_program(vars, "Last line invalid!");
		cursor++;
	}
}

int			is_valid_map(t_game *vars)
{
	vars->map_height = 0;
	while (vars->map[vars->map_height])
		vars->map_height++;
	check_map_integrity(vars, vars->map);
	return (1);
}
