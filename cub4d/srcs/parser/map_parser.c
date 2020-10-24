/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 01:31:55 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/24 02:40:44 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int			check_map_buffer(t_game *vars)
{
	int		count;

	count = 0;
	while (vars->map_buf[count])
	{
		if (!ft_strchr(MAP_FLAGS, vars->map_buf[count]))
			return (-1);
		if (ft_strchr(MAP_POSITION_TYPE, vars->map_buf[count]))
		{
			if (vars->pos_type)
				return (-2);
			vars->pos_type = vars->map_buf[count];
		}
		count++;
	}
	return (1);
}

void		parse_map(t_game *vars, int fd)
{
	int		ret;

	read_map(vars, fd);
	if ((ret = check_map_buffer(vars)) != 1)
		exit_program(vars, ret == -1 ? "Invalid char in map" : "Too many spawn point!");
	vars->map = ft_split(vars->map_buf, '\n');
	if (!vars->map)
		exit_program(vars, "Failed to read map.");
	if (!is_valid_map(vars))
		exit_program(vars, "Invalid maps.");
}
