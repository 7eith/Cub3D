/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 02:20:19 by amonteli          #+#    #+#             */
/*   Updated: 2020/09/14 01:02:44 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		exit_program(t_game *vars, char *reason)
{
	ft_printf("%s", reason);
	free(vars->paths[NORTH]);
	free(vars->paths[EAST]);
	free(vars->paths[WEST]);
	free(vars->paths[SOUTH]);
	free(vars->paths[SPRITE]);
	free(vars->mlx);

	if (vars->map_buf)
		free(vars->map_buf);

	int		index;

	index = 0;
	while(vars->map[index])
		free(vars->map[index++]);
	free(vars);
	exit(0);
}
