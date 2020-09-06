/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 09:04:24 by amonteli          #+#    #+#             */
/*   Updated: 2020/09/06 23:55:47 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			parse_resolution(t_game *vars, char *line)
{
	int		index;

	index = -1;
	if (vars->width != -1 || vars->height != -1)
		exit_program(vars, "Resolution already parsed.");
	if (!is_only_resolution(line))
		exit_program(vars, "Contains invalid char in resolution");
	vars->width = ft_atoi(line);
	line += ft_numlen(vars->width);
	if (*line++ != ' ')
		exit_program(vars, "Can't parse resolution");
	vars->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line)
		exit_program(vars, "Space at the end of the resolution");

	vars->conf |= R;
}

void			parse_color(t_game *vars, char *line, int type)
{
	int			r;
	int			g;
	int			b;

	if (vars->conf & (type ? C : F))
		exit_program(vars, "Already parsed this value.");
	r = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	*line == ',' ? line++ : exit_program(vars, "RGB not correctly formated");
	g = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	*line == ',' ? line++ : exit_program(vars, "RGB not correctly formated");
	b = ft_atoi(line);
	while (*line == ' ')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line)
		exit_program(vars, "Space at the end of the line of RGB.");
	if (r > 255 || g > 255 || b > 255)
		exit_program(vars, "RGB Value overflow! Limit to 255.");
	vars->colors[type] = create_color(r, g, b);
	vars->conf |= type ? C : F;
}

void			parse_textures(t_game *vars, char *line, int type)
{
	int			opened_fd;

	if (vars->paths[type] != NULL)
		exit_program(vars, "Textures has double entry!");
	opened_fd = open(line, O_RDONLY);
	if (opened_fd == -1)
		exit_program(vars, "Texture not existing!");
	close(opened_fd);
	vars->paths[type] = ft_strdup(line);
}

void			parse_value(t_game *vars, char *line)
{
	if ((*line == ' ' || !*line) && !vars->conf)
		exit_program(vars, "Empty lines at the beginning of the file..");
	if (*line == ' ' || !*line)
		while (*line)
			*line == ' ' ? line++ : exit_program(vars, "Error");
	else if (*line == 'R' && line[1] == ' ')
		return (parse_resolution(vars, line + 2));
	else if (*line == 'F' && line[1] == ' ')
		return (parse_color(vars, line + 2, FLOOR));
	else if (*line == 'C' && line[1] == ' ')
		return (parse_color(vars, line + 2, SKY));
	else if (*line == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parse_textures(vars, line + 3, NORTH));
	else if (*line == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parse_textures(vars, line + 3, SOUTH));
	else if (*line == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parse_textures(vars, line + 3, WEST));
	else if (*line == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parse_textures(vars, line + 3, EAST));
	else if (*line == 'S' && line[1] == ' ')
		return (parse_textures(vars, line + 2, SPRITE));
	else if (*line == '1')
		exit_program(vars, "Missing keys in configurations before map!");
	else
		exit_program(vars, "Invalid keys!");
}

void			parse_configuration(t_game *vars, int fd)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) && !is_valid_configuration(vars))
	{
		parse_value(vars, line);
		free(line);
	}
	if (ft_strlen(line) != 0)
		ret = -1;
	free(line);
	if (ret == -1 || !ret)
		exit_program(vars, "Failed to read map.");
}
