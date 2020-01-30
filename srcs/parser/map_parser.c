/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 01:24:26 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 11:33:52 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void				check_map_line(t_game *vars, char *line, int size)
{
	int				walls;

	walls = 0;
	if (*line != '1')
	while (*line)
	{
		// if (*line != '1' || *line != ' ')
		if (*line == '1')
			walls++;

	}
	if (walls != size)
		exit_programs(vars, "Map is not rectangular!");
}

void				check_map(t_game *vars)
{
	int				index;
	int				walls;

	index = 0;
	walls = 0;
	while (vars->map[0][index])
	{
		if (vars->map[0][index] != '1' && vars->map[0][index] != ' ')
			vars->map[0][index] == '0' ? exit_programs(vars, "Map not closed at top!") : exit_programs(vars, "Invalid char at the first line of the map!");
		if (vars->map[0][index] == '1')
			walls++;
		index++;
	}
	if (vars->map[0][index - 1] != '1')
		exit_programs(vars, "Line not ending with a walls!");
	while (vars->map[index]) // segfault here, split zobed?
	{
		check_map_line(vars, vars->map[index], walls);
		index++;
	}
	printf("walls_size={%d}\n", walls);
}

void				assign_map(t_game *vars, int fd, char *line)
{
	int			ret;

	vars->map_buf = ft_strjoin_free(line, "\n", 1);
	while ((ret = get_next_line(fd, &line)))
	{
		line = ft_strjoin_free(line, "\n", 1);
		vars->map_buf = ft_strjoin_free(vars->map_buf, line, 2);
		free(line);
	}
	printf("map_buf={\n%s}\n", vars->map_buf);
	vars->map = ft_split(vars->map_buf, '\n');
	if (!vars->map)
		exit_programs(vars, "Failed to read map.");
	free(vars->map_buf);
}

void				read_map(t_game *vars, int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)))
	{
		if (*line == ' ')
			while (*line)
				*line == ' ' ? line++ : exit_programs(vars, "Spaces not at good place!"); // ternary for more verbosed printf
		if (*line != '1')
		{
			free(line);
			exit_programs(vars, "Map left not closed!");
		}
		if (*line == '1')
			break;
	}
	if (ret == -1)
		exit_programs(vars, "Failed to read map.");
	assign_map(vars, fd, line);
}
