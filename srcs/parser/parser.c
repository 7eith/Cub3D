/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 06:51:27 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			assign_assets(t_game *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		dprintf(1, "parsing line x=%d, y=%d\n", x, y);
		while (vars->map[x][y])
		{
			if (ft_strchr("NSWE", vars->map[x][y]))
			{
				dprintf(1, "found line x=%d, y=%d\n", x, y);
				vars->posX = (double)5;
				vars->posY = (double)5;
			}
			y++;
		}
		x++;
	}
}

void			parse(t_game *vars, char **args)
{
	int			fd;

	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		exit_programs(vars, "Failed to read file!");
	parse_configuration(vars, fd);
	read_map(vars, fd);
	check_map(vars);
	assign_assets(vars);
	dprintf(1, "found assets x=%f, y=%f\n", vars->posX, vars->posY);
}
