/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 10:10:31 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		report_error(char *str)
{
	ft_putstr_fd("\e[91m", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}

void		check_args(t_cub3d *cube, int argc, char **args)
{
	if (argc < 2 || argc > 3)
		report_error("use ./Cub3D <map> (--save)");
	if (!ft_strnstr(args[1], ".cub", ft_strlen(args[1])))
		report_error("invalid map file.");
	if (argc == 3 && ft_strncmp(args[2], "--save", ft_strlen(args[2])))
		report_error("use ./Cub3D <map> (--save)");
	else
		cube->settings->flags |= ST_SAVE;
}

int			parse_resolution(t_cub3d *vars, char *line)
{
	int		count;

	count = 1;
	while (line[count] == ' ' && line[count])
		count++;
	if (!(vars->settings->w = ft_atoi(line + count)))
		return (0);
	count += ft_numlen(vars->settings->w);
	while (line[count] == ' ' && line[count])
		count++;
	if (!(vars->settings->h = ft_atoi(line + count)))
		return (0);
	count += ft_numlen(vars->settings->w);
	printf("%s\n", line);
	free(line);
	return (1);
}

int			parse_var(t_cub3d *vars, char *line)
{
	int			count;

	count = 0;
	(void)vars;
	printf("received=%s\n", line);
	// printf("[%c]", line[count]);
	if (line[count] == ' ')
	{
		while(line[count])
		{
			printf("%c\n", line[count]);
			line[count] == ' ' ? count++ : report_error("Error when reading spaced lines");
		}
	}
	if (line[count] == 'R')
		parse_resolution(vars, line) ? 0 : report_error("Error when reading resolution");
	return (1);
}

void		parse_settings(t_cub3d *vars, int fd)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			report_error("Error when reading map.");
		if (!parse_var(vars, line))
			report_error("Error when reading key.");
		// printf("[%d] line=%s\n", ret, line);
	}
	ret = get_next_line(fd, &line);
	// printf("[%d] line=%s\n", ret, line);
}

	// char		*line;
	// int			count;
	// int			fd;

	// count = 0;
	// printf("args=%s\n", args[1]);
	// fd = open(args[1], O_RDONLY);
	// if (get_next_line(fd, &line))
	// {
	// 	parse_resolution(vars, line);
	// 	return ;
	// }
	// if (get_next_line(fd, &line) && line[count] == 'R')
	// {
	// 	dprintf(1, "slt=%s\n", line + 2);
	// 	vars->settings->w = ft_atoi(line + 2);
	// 	vars->settings->h = ft_atoi(line + 2 + ft_numlen(vars->settings->w));
	// 	dprintf(1, "slt=%s\n", line);
	// 	printf("resolution w=%d\n", vars->settings->w);
	// 	printf("resolution h=%d\n", vars->settings->h);
	// 	free(line);
	// }
	// else
	// 	report_error("Error while parsing Resolution");

/*
**	check args, like --save, map.
**
**
**
*/

void		parse(t_cub3d *vars, int argc, char **args)
{
	int		fd;

	check_args(vars, argc, args);

	fd = open(args[1], O_RDONLY);
	parse_settings(vars, fd);
	// parse_map(vars, fd);
}
