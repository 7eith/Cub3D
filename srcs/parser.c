/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 06:19:41 by amonteli    ###    #+. /#+    ###.fr     */
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
	int		count;
	t_color	color;

	count = 3;
	while (count)
	{
		// printf("line={%s}\n", line);
		count == 3 ? color.rgb.r = ft_atoi(line) : NULL;
		count == 2 ? color.rgb.g = ft_atoi(line) : NULL;
		count == 1 ? color.rgb.b = ft_atoi(line) : NULL;
		while (line && ft_isdigit(*line))
			line++;
		printf("line={%s}\n", line);
		line++;
		count--;
	}
	printf("type=%s\n", !type ? "Floor" : "Sky");
	printf("r=%d, g=%d, b=%d\n", color.rgb.r, color.rgb.g, color.rgb.b);
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
}
