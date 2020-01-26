/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 01:24:26 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 07:56:23 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	vars->map = ft_split(vars->map_buf, '\n');
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
			exit_programs(vars, "Yah tu deconne zebi");
		}
		if (*line == '1')
			break;
	}
	if (ret == -1)
		exit_programs(vars, "Failed to read map.");
	assign_map(vars, fd, line);
}
