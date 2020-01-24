/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conf_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 01:24:23 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 22:35:48 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			parse_resolution(t_game *vars, char *line)
{
	if (vars->conf & R)
		exit_programs(vars, "Resolution already parsed.");
	vars->width = ft_atoi(line);
	vars->height = ft_atoi(line + ft_numlen(vars->width));
	if (vars->width > 2560)
		vars->width = 2560;
	if (vars->height > 1440)
		vars->height = 1440;
	vars->conf |= R;
}

void			parse_color(t_game *vars, char *line, int type)
{
	int			r;
	int			g;
	int			b;

	if (vars->conf & (type ? C : F))
		exit_programs(vars, "Already parsed this value.");
	r = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	*line == ',' ? line++ : exit_programs(vars, "Empty line not correctly formated.");
	g = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	*line == ',' ? line++ : exit_programs(vars, "Empty line not correctly formated.");
	b = ft_atoi(line);
	while (*line == ' ')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line)
		exit_programs(vars, "Space at the end of the line of RGB.");
	if (r > 255 || g > 255 || b > 255)
		exit_programs(vars, "RGB Value overflow! Limit to 255.");
	vars->colors[type] = create_color(r, g, b);
	vars->conf |= type ? C : F;
}

void			parse_paths(t_game *vars, char *line, int type)
{
	if (vars->conf & T_NO || vars->conf & T_EA || vars->conf & T_SO || vars->conf & T_WE || vars->conf & T_S)
		exit_programs(vars, "Textures has double entry!");
	if (open(line, O_RDONLY) == -1)
		exit_programs(vars, "Texture not existing!");
	printf("%d\n", open(line, O_RDONLY));
	printf("line={%s}\n", line);
}

void			parse_value(t_game *vars, char *line)
{
	if ((*line == ' ' || !*line) && !vars->conf)
		exit_programs(vars, "Empty lines at the beginning of the file..");
	else if (*line == ' ')
		while (*line)
			*line == ' ' ? line++ : exit_programs(vars, "Empty line not correctly formated.");
	else if (*line == 'R' && line[1] == ' ')
		parse_resolution(vars, line + 2);
	else if (*line == 'F' && line[1] == ' ')
		parse_color(vars, line + 2, FLOOR);
	else if (*line == 'C' && line[1] == ' ')
		parse_color(vars, line + 2, SKY);
	else if (*line == 'N' && line[1] == 'O' && line[2] == ' ')
		parse_paths(vars, line + 3, NORTH);
}

void			parse_configuration(t_game *vars, int fd)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)))
	{
		parse_value(vars, line);
		free(line);
	}
	if (ret == -1)
		exit_programs(vars, "Failed to read map.");
}
