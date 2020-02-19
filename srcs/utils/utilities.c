/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 05:10:26 by amonteli          #+#    #+#             */
/*   Updated: 2020/02/19 01:18:36 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Check if configurations is valid
*/

int				is_valid_configuration(t_game *vars)
{
	int			index;

	index = 0;
	if (vars->width == -1 || vars->height == -1)
		return (0);
	if (!(vars->conf & C) || !(vars->conf & F))
		return (0);
	while (index < TEXTURES)
		if (!vars->paths[index++])
			return (0);
	return (1);
}

/*
** 	Create Color from Red Green Blue
*/

t_color			create_color(int r, int g, int b)
{
	t_color		color;

	color.rgb.a = 0;
	color.rgb.r = r;
	color.rgb.g = g;
	color.rgb.b = b;
	return (color);
}

/*
**	Return Absolute number from a Float
*/

float			ft_fabs(float number)
{
	return (number < 0 ? -number : number);
}
