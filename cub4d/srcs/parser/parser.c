/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:25:57 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/14 06:19:05 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_file(t_game *vars, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_program(vars, "Failed to read file!");
	parse_configuration(vars, fd);
	parse_map(vars, fd);
}
