/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 07:15:58 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		report_error(int error)
{
	ft_putstr_fd("\e[91m", 1);
	if (error == ERR_INVALID_MAP_NAME)
		ft_putstr_fd("Error! invalid map name.", 1);
	if (error == ERR_INVALID_ARGUMENTS)
		ft_putstr_fd("Error! please use ./Cub3D <map> (--save)", 1);
	if (error == ERR_READING)
		ft_putstr_fd("Error! Reading error.. Invalid maps?", 1);
	if (error == ERR_INVALID_SPACED_LINE)
		ft_putstr_fd("Error! Invalid spaced lines", 1);
	if (error == ERR_INVALID_RGB_KEY)
		ft_putstr_fd("Error! Invalid RGB config.", 1);
	exit(0);
}

void		check_programs_args(t_game *vars, int argc, char **args)
{
	if (argc < 2 || argc > 3)
		report_error(ERR_INVALID_ARGUMENTS);
	if (!ft_strnstr(args[1], ".cub", ft_strlen(args[1])))
		report_error(ERR_INVALID_MAP_NAME);
	vars->screen = 0;
	if (argc == 3)
	{
		if (ft_strncmp(args[2], "--save", 8))
			report_error(ERR_INVALID_ARGUMENTS);
		else
			vars->screen = 1;
	}
}

int			parse_color(t_game *vars, char *line, int type)
{
	t_color		color;

	color.rgb.a = 0;
	color.rgb.r = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line != ',')
		return (ERR_INVALID_RGB_KEY);
	line++;
	color.rgb.g = ft_atoi(line) > 255;
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line != ',')
		return (ERR_INVALID_RGB_KEY);
	line++;
	color.rgb.b = ft_atoi(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line)
		report_error(ERR_INVALID_RGB_KEY);
	vars->colors[type] = &color;
	if (color.rgb.r > 255 ||
	vars->colors[type]->rgb.g > 255 || vars->colors[type]->rgb.b > 255)
		report_error(ERR_INVALID_RGB_KEY);
	return (1);
}

int			parse_resolution(t_game *vars, char *line)
{
	vars->width = ft_atoi(line);
	vars->height = ft_atoi(line + ft_numlen(vars->width));
	printf("width=%d, height=%d\n", vars->width, vars->height);
	return (1);
}

int			parse_var(t_game *vars, char *line)
{
	// printf("line=[%s]\n", line);
	if (*line == ' ')
		while (*line)
			*line == ' ' ? line++ : report_error(ERR_INVALID_SPACED_LINE);
	if (*line == 'R' && line[1] == ' ')
		return (parse_resolution(vars, line + 2));
	if (*line == 'F' && line[1] == ' ')
		return (parse_color(vars, line + 2, FLOOR));
	return (0);
}

int			parse_settings(t_game *vars, int fd)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			report_error(ERR_READING);
		parse_var(vars, line);
		free(line);
	}
	return (1);
}

void		parse(t_game *vars, int argc, char **args)
{
	int		fd;

	check_programs_args(vars, argc, args);
	fd = open(args[1], O_RDONLY);
	parse_settings(vars, fd);
	printf("r=%d, g=%d, b=%d\n", vars->colors[FLOOR]->rgb.r, vars->colors[FLOOR]->rgb.g, vars->colors[FLOOR]->rgb.b);
	printf("rgb=%d\n", vars->colors[FLOOR]->c);
}
