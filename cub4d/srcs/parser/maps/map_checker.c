/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:13:38 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/13 23:03:51 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void		format_map(char **map)
{
	int		count;
	int		cursor;

	count = 0;
	cursor = 0;
	while (map[count])
	{
		while (map[count][cursor])
		{
			if (map[count][cursor] == '2')
				map[count][cursor] = '0';
			if (ft_strchr(MAP_POSITION_TYPE, map[count][cursor]))
				map[count][cursor] = '2';
			cursor++;
		}
		cursor = 0;
		count++;
	}
}

void		get_player_pos(char **map, int *x, int *y)
{
	int		count;
	int		found;

	count = 0;
	found = 0;
	while (map[count] && !found)
	{
		if (ft_strchr_len(map[count], '2'))
		{
			*x = count;
			*y = ft_strchr_len(map[count], '2');
			found = 1;
		}
		count++;
	}
}

int			check_side(char **map, int x, int y, int height)
{
	int			count;
	const int	line_size = ft_strlen(map[x]);

	count = 0;
	if (x > 0 && map[x - 1][y] == '0')
	{
		map[x - 1][y] = '2';
		count++;
	}
	if (x < height - 1 && map[x + 1][y] == '0')
	{
		map[x + 1][y] = '2';
		count++;
	}
	if (y > 0 && map[x][y - 1] == '0')
	{
		map[x][y - 1] = '2';
		count++;
	}
	if (y != line_size && map[x][y + 1] == '0')
	{
		map[x][y + 1] = '2';
		count++;
	}
	return (count);
}

int			check_map(char **map, int width, int height)
{
	int		x;
	int		y;
	int		has_posed;

	x = 0;
	y = 0;
	has_posed = 0;
	get_player_pos(map, &x, &y);
	while (!has_posed)
	{
		has_posed = 1;
		x = -1;
		while (map[++x] && (y = -1))
			while (map[x][++y])
				if (map[x][y] == '2' && check_side(map, x, y, height) != 0)
					has_posed = 0;
	}
	x = -1;
	while (map[++x] && (y = -1))
		while (map[x][++y])
			if (map[x][y] == '2'
			&& (x == 0 || y == 0 || y == width - 1 || x == height - 1))
				return (0);
	return (1);
}

int			is_valid_map(t_game *vars)
{
	char				**map;
	int					count;
	const unsigned long	line_size = ft_strlen(vars->map[0]);

	count = 0;
	while (vars->map[count])
		count++;
	count = 0;
	while (vars->map[count])
		if (ft_strlen(vars->map[count++]) != line_size)
			exit_program(vars, "Invalid line size!");
	if (!(map = ft_copy_2d_tabs(vars->map)))
		return (0);
	format_map(map);
	if (!check_map(map, line_size, count))
	{
		ft_clear_2d_tabs((void **)map);
		return (0);
	}
	ft_clear_2d_tabs((void **)map);
	return (1);
}
