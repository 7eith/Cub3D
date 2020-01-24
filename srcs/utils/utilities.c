/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 05:10:26 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 05:11:05 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
