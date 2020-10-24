/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:31:00 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/14 06:19:05 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_options(t_game *vars, char **args)
{
	if (ft_strncmp(args[1], "--save", 7)
	|| ft_strncmp(args[2] + ft_strlen(args[2]) - 4, ".cub", 5))
		exit_program(vars, "Please use ./Cub3D (--save) <map.cub>");
	vars->screen = 1;
}

void		check_params(t_game *vars, int argc, char **args)
{
	if (argc < 2 || argc > 3)
		exit_program(vars, "Please use ./Cub3D (--save) <map.cub>");
	if (argc == 3)
		return (check_options(vars, args));
	if (ft_strncmp(args[1] + ft_strlen(args[1]) - 4, ".cub", 5))
		exit_program(vars, "Please use ./Cub3D (--save) <map.cub>");
}
