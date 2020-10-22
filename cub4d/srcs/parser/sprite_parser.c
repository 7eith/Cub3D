/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:42:18 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/23 00:12:43 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	create_sprite(int pos_x, int pos_y)
{
	t_sprite	sprite;

	sprite.pos_x = pos_x;
	sprite.pos_y = pos_y;
	sprite.distance = -1;
	return (sprite);
}

int			count_sprites(t_game *vars)
{
	int		cursor;
	int		count;

	cursor = 0;
	count = 0;
	while (vars->map_buf[cursor])
	{
		if (vars->map_buf[cursor] == '2')
			count++;
		cursor++;
	}
	return (count);
}

void		read_sprites(t_game *vars)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '2')
			{
				vars->sprites[count] = create_sprite(x, y);
				count++;
			}
			y++;
		}
		x++;
	}
}

void		parse_sprite(t_game *vars)
{
	vars->sprites_count = count_sprites(vars);
	vars->sprites = ft_calloc(sizeof(t_sprite), vars->sprites_count + 1);
	ft_bzero(vars->sprites, vars->sprites_count + 1);
	read_sprites(vars);
}
