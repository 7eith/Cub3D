/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 22:14:42 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 16:39:01 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		report_error(int error, char *str)
{
	ft_putstr_fd("\e[91m", 1);
	ft_putstr_fd(str, 1);
	exit(error);
}

void		parse_args(t_settings *settings, int argc, char **args)
{
	if (argc == 3 && ft_strncmp(args[2], "--save", ft_strlen(args[2])))
		report_error(-1, "use ./Cub3D <map> [--save]");
	else
		settings->flags |= ST_SAVE;
}

void		parse(t_settings *settings, int argc, char **args)
{
	argc < 2 || argc > 3 ? report_error(-1, "Error! invalid number of arguments") : parse_args(settings, argc, args);
	parse_args(settings, argc, args);
}
