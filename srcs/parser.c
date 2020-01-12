/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 08:37:07 by amonteli    ###    #+. /#+    ###.fr     */
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
	exit(0);
}

int			check_programs_args(t_game *vars, int argc, char **args)
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

int			skip_empty_line(char **line)
{
	while(*line)
	{
		printf("slt=[%c]\n", **line);
		*line++;
	}
}

int			parse_var(t_game *vars, char *line)
{
	printf("line=[%c]\n", *line);
	if (*line == ' ')
		skip_empty_line(&line);
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
}

void		parse(t_game *vars, int argc, char **args)
{
	int		fd;

	check_programs_args(vars, argc, args);
	fd = open(args[1], O_RDONLY);
	parse_settings(vars, fd);
}
