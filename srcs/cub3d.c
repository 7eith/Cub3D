/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 21:54:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 08:19:02 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argsc, char **args)
{
	t_game		*vars;

	if (!(vars = malloc(sizeof(t_game))))
		return (0);
	parse(vars, argsc, args);
	printf("save?=%d\n", vars->screen);
	return (0);
}
