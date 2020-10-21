/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:42:18 by amonteli          #+#    #+#             */
/*   Updated: 2020/10/19 20:50:50 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*create_sprite(int posX, int posY)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	sprite->pos_x = posX;
	sprite->pos_y = posY;
	return (sprite);
}

void		read_sprites(t_game *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '2')
				ft_lstadd_front(&vars->sprites, ft_lstnew(create_sprite(x, y)));
			y++;
		}
		x++;
	}
}

void		parse_sprite(t_game *vars)
{
	read_sprites(vars);

	t_list	*lst;

	lst = vars->sprites;
	while (lst)
	{
		t_sprite	*sprite;
		sprite = lst->content;
		printf("sprite={x=%d, y=%d}\n", sprite->pos_x, sprite->pos_y);
		lst = lst->next;
	}
}
