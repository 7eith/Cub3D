/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:54:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 06:46:33 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	Initialise variables.
*/

static inline t_game		*init_vars(void)
{
	t_game		*vars;
	int			index;

	index = 0;
	if (!(vars = malloc(sizeof(t_game))))
		return (NULL);
	vars->width = 0;
	vars->height = 0;
	vars->conf = 0;
	vars->screen = 0;
	vars->width = -1;
	vars->height = -1;
	vars->map_buf = NULL;
	vars->map = NULL;

	vars->posX = -1;
	vars->posY = -1;
	vars->dirX = -1;
	vars->dirY = 0;
	vars->planeX = 2;
	vars->planeY = 0.5;
	while (index < TEXTURES)
		vars->paths[index++] = NULL;
	return (vars);
}

void						exit_programs(t_game *vars, char *str)
{
	ft_putstr_fd("\e[91mError\n", 1);
	ft_putstr_fd(str, 1);
	free(vars);
	exit(0);
}

static inline	void		check_params(t_game *vars, int argc, char **args)
{
	if (argc < 2 || argc > 3)
		exit_programs(vars, "Invalid arguments count.");
	if (ft_strncmp(args[1] + ft_strlen(args[1]) - 4, ".cub", 5))
		exit_programs(vars, "Invalid map extension!");
	if (argc == 3)
	{
		if (ft_strncmp(args[2], "--save", 8))
			exit_programs(vars, "Please use ./Cub3D <map> (--save)");
		else
			vars->screen = 1;
	}
}

void						debug_parser(t_game *vars)
{
	printf("[R]  Width=%d, Height=%d\n", vars->width, vars->height);
	printf("[F]  R=%d, G=%d, B=%d\n", vars->colors[FLOOR].rgb.r, vars->colors[FLOOR].rgb.g, vars->colors[FLOOR].rgb.b);
	printf("[C]  R=%d, G=%d, B=%d\n", vars->colors[SKY].rgb.r, vars->colors[SKY].rgb.g, vars->colors[SKY].rgb.b);
	printf("[NO] Path=%s\n", vars->paths[NORTH]);
	printf("[SO] Path=%s\n", vars->paths[SOUTH]);
	printf("[WE] Path=%s\n", vars->paths[WEST]);
	printf("[EA] Path=%s\n", vars->paths[EAST]);
	printf("[S]  Path=%s\n", vars->paths[SPRITE]);

	int		index;

	index = 0;
	if (vars->map)
		while (vars->map[index])
			printf("{%s}\n", vars->map[index++]);
}

int							main(int argsc, char **args)
{
	t_game		*vars;

	if (!(vars = init_vars()))
		return (0);
	check_params(vars, argsc, args);
	parse(vars, args);
	debug_parser(vars);
	open_window(vars);
	return (0);
}
