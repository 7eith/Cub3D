/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:13:38 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 02:37:30 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_around_position(char **map, int x, int y, int corner)
{
	if (map[x - 1][y] && map[x - 1][y] != '1') // up
		return (0);
	if (map[x + 1][y] && map[x + 1][y] != '1') // down
		return (0);
	if (corner == 1)
	{
		if (map[x][y - 1] && map[x][y - 1] != '1') // left
			return (0);
		// if (map[x - 1][y - 1] && map[x - 1][y - 1] != '1')	// diagonal left up
		// 	return (0);
		// if (map[x + 1][y - 1] && map[x + 1][y - 1] != '1') // diagonal left down
		// 	return (0);
	}
	else if (corner == 2)
	{
		if (map[x][y + 1] && map[x][y + 1] != '1') // right
			return (0);
		// if (map[x - 1][y + 1] && map[x - 1][y + 1] != '1')	// diagonal left up
		// 	return (0);
		// if (map[x + 1][y + 1] && map[x + 1][y + 1] != '1') // diagonal right down
		// 	return (0);
	}
	return (1);
}

void		is_valid_line(t_game *vars, char **map, int x)
{
	int		count;

	count = 0;
	if (x == 0) // check first line
	{
		while (map[x][count])
		{
			if (map[x][count] != '1' && map[x][count] != ' ')
			{
				printf("char_map={%c}, position={%d}\n", map[x][count], count);
				exit_program(vars, "Premiere ligne invalid pas de 0 ni d'espace");
			}
			count++;
		}
	}
	count = 0;
	while (map[x][count] == ' ')
		count++;
	if (map[x][count] != '1')
		exit_program(vars, "Line doesn't start by wall!");
	int		was_call;

	was_call = 0;
	while (map[x][count])
	{
		if (map[x][count] != ' ' && was_call == 1)
		{
			was_call = 2;
		}
		if (map[x][count] == ' ')
		{
			if (was_call == 0)
			{
				was_call = 1;
				if (x > 0 && count > 0 && !check_around_position(map, x, count, 1))
					exit_program(vars, "Failed to check around pos!");
			}
			else if (was_call == 1)
			{
				if (x > 0 && count > 0 && !check_around_position(map, x, count, 0))
					exit_program(vars, "Failed to check around pos!");
			}
			else
			{
				if (x > 0 && count > 0 && !check_around_position(map, x, count, 2))
					exit_program(vars, "Failed to check around pos!");
			}
		}
		count++;
	}
	if (map[x][count - 1] != '1')
	{
		printf("[Debug] map_index=%d, line_cursor=%d, line={%s}, char={%c}\n", x, count, map[x], map[x][count - 1]);
		exit_program(vars, "Line doesn't end by wall!");
	}
}

void		check_map_hole(t_game *vars, char **map, int pos, size_t size)
{
	int			cursor;

	cursor = size;
	if (pos > 0 && size < ft_strlen(map[pos - 1]))
	{
		while (map[pos - 1][cursor])
		{
			if (map[pos - 1][cursor] != '1')
				exit_program(vars, "fucking blackhole");
			cursor++;
		}
	}
	cursor = size;
	if (pos < vars->map_height - 1 && size < ft_strlen(map[pos + 1]))
	{
		while (map[pos + 1][cursor])
		{
			if (map[pos + 1][cursor] != '1')
				exit_program(vars, "fucking blackhole en bas pd");
			cursor++;
		}
	}
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
		{
			exit_program(vars, "Derniere ligne invalid pas de 0 ni d'espace");
		}
		cursor++;
	}
	// printf("Success!");
	// exit(1);
}

int			is_valid_map(t_game *vars)
{
	char				**map;

	vars->map_height = 0;
	while (vars->map[vars->map_height])
		vars->map_height++;
	if (!(map = ft_copy_2d_tabs(vars->map)))
		return (0);
	// format_map(vars, map);
	check_map_integrity(vars, map);
	ft_clear_2d_tabs((void **)map);
	return (1);
}


/**
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */