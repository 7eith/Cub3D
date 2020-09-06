/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:22:56 by amonteli          #+#    #+#             */
/*   Updated: 2020/09/07 00:18:56 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_only_resolution(char *line)
{
	int		count;

	count = 0;
	while (line[count])
	{
		if (!(ft_isdigit(line[count]) || line[count] == ' '))
			return (0);
		count++;
	}
	return (1);
}

void	check_screen_size(t_game *vars)
{
	int		screensize_x;
	int		screensize_y;

	screensize_x = 0;
	screensize_y = 0;
	mlx_get_screen_size(vars->mlx, &screensize_x, &screensize_y);
	if (vars->width <= 0 || vars->height <= 0)
		exit_program(vars, "Invalid resolution!");
	if (vars->width > screensize_x)
		vars->width = screensize_x;
	if (vars->height > screensize_y)
		vars->height = screensize_y;
}
