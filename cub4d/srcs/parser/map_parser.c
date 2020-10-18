/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 01:31:55 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/17 09:48:53 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*get_line_with_removed_space(char *line)
{
	int		count;
	int		size;
	char	*str;

	count = 0;
	size = 0;
	while (line[count])
		if (line[count++] != ' ')
			size++;
	str = ft_calloc(size + 1, sizeof(char));
	count = -1;
	size = 0;
	while (line[++count])
		if (line[count] != ' ')
			str[size++] = line[count];
	free(line);
	return (str);
}

void		read_map(t_game *vars, int fd)
{
	int		ret;
	int		index;
	char	*line;

	index = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		line = ft_strjoin_free(line, "\n", 1);
		vars->map_buf = !vars->map_buf ? ft_strdup(line)
		: ft_strjoin_free(vars->map_buf, line, 1);
		free(line);
	}
	if (ft_strlen(line))
		exit_program(vars, "Last line need to be empty!");
	if (ret == -1)
		exit_program(vars, "Failed to read map content!");
	free(line);
}

int			check_map_buffer(char *map)
{
	int		count;
	char	pos_type;

	count = 0;
	pos_type = 0;
	while (map[count])
	{
		if (!ft_strchr(MAP_FLAGS, map[count]))
			return (0);
		if (ft_strchr(MAP_POSITION_TYPE, map[count]))
		{
			if (pos_type)
				return (0);
			pos_type = map[count];
		}
		count++;
	}
	return (1);
}

void		parse_map(t_game *vars, int fd)
{
	int		count;

	count = -1;
	read_map(vars, fd);
	close(fd);
	if (!check_map_buffer(vars->map_buf))
		exit_program(vars, "Invalid map!");
	vars->map = ft_split(vars->map_buf, '\n');
	if (!vars->map)
		exit_program(vars, "Failed to read map.");
	while (vars->map[++count])
		vars->map[count] = get_line_with_removed_space(vars->map[count]);
	if (!is_valid_map(vars))
		exit_program(vars, "Invalid maps.");
}
