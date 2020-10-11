/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:13:38 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/11 05:59:09 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char		**copy_tab(char **map) // to include in libft
{
	char	**tab;
	int		count;

	count = 0;
	while (map[count])
		count++;
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	count = -1;
	while (map[++count])
		tab[count] = ft_strdup(map[count]);
	tab[count] = 0;
	return (tab);
}

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

int		check_side(char **map, int x, int y, int height)
{
	int			count;
	const int	line_size = ft_strlen(map[x]);

	count = 0;
	if (x > 0 && map[x - 1][y] == '0') // check en haut
	{
		map[x - 1][y] = '2';
		count++;
	}
	if (x < height - 1 && map[x + 1][y] == '0') // en bas
	{
		map[x + 1][y] = '2';
		count++;
	}
	if (y > 0 && map[x][y - 1] == '0') // gauche
	{
		map[x][y - 1] = '2';
		count++;
	}
	if (y != line_size && map[x][y + 1] == '0') // droite
	{
		map[x][y + 1] = '2';
		count++;
	}
	return (count);
}

int		backtrack_map(char **map, int width, int height)
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

		x = 0;
		while (map[x])
		{
			y = 0;
			while(map[x][y])
			{
				if (map[x][y] == '2' && check_side(map, x, y, height) != 0)
					has_posed = 0;
				y++;
			}
			x++;
		}
	}
	x = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			printf("x=%d, y=%d, width=%d, height=%d\n", x, y, width, height);
			if (map[x][y] == '2' && (x == 0 || y == 0 || y == width - 1 || x == height - 1))
			{
				return (0);
				// printf("x=%d, y=%d, is_open=%d\n", x, y, (x == 0 || y == 0 || x == width || y == height));
			}
			y++;
		}
		x++;
	}
	return (1);

	// while (++y < data->maph && (x = -1) < 0)
	// while (++x < data->mapw)
	// 	if (map[x + y * data->mapw] == '9')
	// 		if (map[x + y * data->mapw] == '9' && (x == 0 ||
	// 			x == data->mapw - 1 || y == 0 || y == data->maph - 1))
	// 			error(data, "Map ouverte", -1);
}

int			is_valid_map(t_game *vars)
{
	char				**map;
	int					count;
	const unsigned long	line_size = ft_strlen(vars->map[0]);

	count = 0;
	while(vars->map[count])
		count++;
	// while(vars->map[count])
		// if (ft_strlen(vars->map[count++]) != line_size)
			// exit_program(vars, "Invalid line size!");
	if (!(map = copy_tab(vars->map)))
		return (0);
	format_map(map);
	if (!backtrack_map(map, line_size, count))
		exit_program(vars, "Map ouverte");
	// DEBUG
	count = -1;
	while (map[++count])
		ft_printf("{%s}\n", map[count]);
	ft_clear_2d_tabs((void **)map);
	return (1);
}
