/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 02:04:59 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 06:53:22 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			set_pixels(t_game *vars)
{
	int			i;

	i = 0;
	while (i < vars->drawstart)//add draw start
	{
		//dprintf(1, "i = %d, drawEnd=%d, drawStart=%d\n", i, vars->lineheight, vars->height);
		vars->img_data[i * vars->width + (int)vars->x] = vars->colors[SKY].c;
		i++;
	}
	i = vars->drawend;
	while (i < vars->height)	// sol? wtf
	{
		vars->img_data[i * vars->width + (int)vars->x] = 0xFF0000;
		i++;
	}
	while (i < vars->height - 1)
	{
		vars->img_data[i * vars->width + (int)vars->x] = vars->side ? vars->colors[FLOOR].c : vars->colors[FLOOR].c / 2;
		i++;
	}
}

int				raycast(t_game *vars)
{
	vars->x = 0;
	while (vars->x < vars->width)
	{
		vars->cameraX = 2 * vars->x / (double)vars->width - 1;
		vars->raydirX = vars->dirX + vars->planeX + vars->cameraX;
		vars->raydirY = vars->dirY + vars->planeY + vars->cameraX;

		vars->mapX = (int)vars->posX;
		vars->mapY = (int)vars->posY;

		vars->deltadistX = fabs(1 / vars->raydirX);
		vars->deltadistY = fabs(1 / vars->raydirY);

		vars->hit = 0;
		if (vars->raydirX < 0)
		{
			vars->stepX = -1;
			vars->sidedistX = (vars->posX - vars->mapX) * vars->deltadistX;
		}
		else
		{
			vars->stepX = 1;
			vars->sidedistX = (vars->mapX + 1.0 - vars->posX) * vars->deltadistX;
		}

		if (vars->raydirY < 0)
		{
			vars->stepY = -1;
			vars->sidedistY = (vars->posY - vars->mapY) * vars->deltadistY;
		}
		else
		{
			vars->stepY = 1;
			vars->sidedistY = (vars->mapY + 1.0 - vars->posY) * vars->deltadistY;
		}

		while (!vars->hit)	// not hitted walls? continue DDA
		{
			if (vars->sidedistX < vars->sidedistY)
			{
				vars->sidedistX += vars->deltadistX;
				vars->mapX += vars->stepX;
				vars->side = 0;
			}
			else
			{
				vars->sidedistY += vars->deltadistY;
				vars->mapY += vars->stepY;
				vars->side = 0;
			}
			printf("mapY = %d, mapX = %d\n", vars->mapY, vars->mapX);
			if (vars->map[vars->mapY][vars->mapX] != '0')
				vars->hit = 1;
		}

		if (vars->side == 0)
			vars->perpwalldist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->raydirX;
        else
            vars->perpwalldist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->raydirY;
		if (vars->perpwalldist < 0)
			vars->perpwalldist *= -1; //check here
		vars->lineheight = (long int)(vars->height / vars->perpwalldist);
		vars->drawstart = -vars->lineheight / 2 + vars->height / 2;
      	if(vars->drawstart < 0)
			vars->drawstart = 0;
		vars->drawend = vars->lineheight / 2 + vars->height / 2;
      	if(vars->drawend >= vars->height)
		 	vars->drawend = vars->height;
		set_pixels(vars);
		vars->x++;
	}
	mlx_clear_window(vars->mlx, vars->window);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	return (1);
}
