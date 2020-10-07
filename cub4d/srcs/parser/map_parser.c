/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkh <snkh@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 01:31:55 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/07 10:15:04 by snkh             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			where_map_segment_start(char *line)
{
	int		index;

	index = 0;
	while (line[index] && line[index] == ' ')
		index++;
	return (index);
}

int			find_highest(char **map)
{
	int		index;
	int		highest;
	size_t	size;

	index = 0;
	highest = 0;
	size = 0;
	while (map[index])
	{
		if (ft_strlen(map[index]) > size)
		{
			size = ft_strlen(map[index]);
			highest = index;
		}
		index++;
	}
	return (highest);
}

char		*get_formated_line(t_game *vars, char *line, int size)
{
	int		count;

	count = 0;
	while (line[count] && line[count] == ' ') // si espace avant un mur de debut il remplis de 0
		line[count++] = '2';

	// printf("info {size=%d, need=%d}\n", ft_strlen(line), size);
	// printf("mine={%s}\n", line);

	while(line[count])
	{
		if (!ft_strchr(MAP_FLAGS, line[count]))
			exit_program(vars, "Invalid char in map");
		count++;
	}
	// while (line[count] && line[count] == ' ') // si espace avant un mur de debut il remplis de 0
	// 	line[count--] = '2';
	return (line);
}

// comment faire?
// tout d'abord realloc toutes les lines de la meme taille donc prendre la plus grosse et full free+strdup
// puis ligne par ligne passer d'abord le fill du debut
// line_size = taille d'une ligne, size = la taille de la map haut en bas
char		**alloc_map(t_game *vars, int line_size)
{
	char		**map;
	int			count;
	int			size;

	count = 0;
	size = 0;
	while (vars->map[size])
		size++;
	if (!(map = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	map[size] = 0;
	while (map[count])
	{
		map[count] = ft_calloc(line_size + 1, sizeof(char));
		count++;
	}
	return (map);
}

int		copy_and_check(char *dst, char *src, int size)
{
	int		count;
	int		has_wall;

	count = 0;
	has_wall = 0;
	while(src[count])
	{
		if (src[count] == '1')
			has_wall = 1;
		if (src[count] == ' ')
			src[count] = has_wall ? '0' : '1';
		dst[count] = src[count];
		count++;
	}
	while (count < size)
	{
		dst[count] = '1';
		count++;
	}
	return (has_wall);
}

void		load_map(t_game *vars, char **map, int size_line)
{
	int		current_line;

	current_line = 0;
	while(map[current_line])
	{
		if (!copy_and_check(map[current_line], vars->map[current_line], size_line))
			exit_program(vars, "Not wall");
		// ft_strlcpy(map[current_line], vars->map[current_line], size_line);
		current_line++;
	}
}

void		check_map(t_game *vars)
{
	int		count;

	count = where_map_segment_start(vars->map[0]);
	// printf("{%d}\n", count);
	while (vars->map[0][count])
	{
		if (vars->map[0][count] != '1' || vars->map[0][count] != ' ')
			exit_program(vars, "Empty line at top");
	}
}

void		format_map(t_game *vars)
{
	const	size_t	high = ft_strlen(vars->map[find_highest(vars->map)]);
	char		**map;
	int			count;

	count = 0;
	check_map(vars);
	map = alloc_map(vars, high);
	load_map(vars, map, high);
	while(vars->map[count])
	{
		free(vars->map[count]);
		// printf("{%s}\n", map[count]);
		// vars->map[count] = get_formated_line(vars, vars->map[count], high);
		// vars->map[count] = realloc_lines(vars, vars->map[count], high);
		count++;
	}
	free(vars->map);
	vars->map = map;
	// printf("%s\n", vars->map[find_highest(vars->map)]);
	// int		index;

	// index = 0;
	// while(vars->map[index])
	// {
	// 	printf("{start=%d, size=%d}\n", where_map_segment_start(vars->map[index]), ft_strlen(vars->map[index]));
	// 	index++;

	// }
}

void		read_map(t_game *vars, int fd)
{
	int		ret;
	int		index;
	char	*line;

	index = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		// printf("[%d] => {%s}\n", ret, line);
		line = ft_strjoin_free(line, "\n", 1);
		vars->map_buf = !vars->map_buf ? ft_strdup(line) : ft_strjoin_free(vars->map_buf, line, 1);
		free(line);
	}
	if (ft_strlen(line))
		exit_program(vars, "Last line need to be empty!");
	if (ret == -1)
		exit_program(vars, "Failed to read map content!");
	free(line);
	vars->map = ft_split(vars->map_buf, '\n');
	if (!vars->map)
		exit_program(vars, "Failed to read map.");
}

void		parse_map(t_game *vars, int fd)
{
	read_map(vars, fd);
	close(fd);
	// check_map(vars);
	format_map(vars);

	int count;
	count = 0;
	while(vars->map[count])
	{
		printf("{%s}\n", vars->map[count]);
		count++;
	}
}
