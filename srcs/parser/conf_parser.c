/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conf_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 01:24:23 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 06:53:57 by amonteli    ###    #+. /#+    ###.fr     */
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
	t_color		color;

	color.rgb.a = 0;
	color.rgb.r = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line != ',')
		exit_programs(vars, "Empty line not correctly formated.");
	line++;
	color.rgb.g = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line != ',')
		exit_programs(vars, "Empty line not correctly formated.");
	line++;
	color.rgb.b = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line)
		exit_programs(vars, "Empty line not correctly formated.");
	vars->colors[type] = &color;
	if (color.rgb.r > 255 ||
	vars->colors[type]->rgb.g > 255 || vars->colors[type]->rgb.b > 255)
		exit_programs(vars, "Empty line not correctly formated.");
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
		vars->conf & F ? exit_programs (vars, "Floor colors already parsed.") : parse_color(vars, line + 2, FLOOR);
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
