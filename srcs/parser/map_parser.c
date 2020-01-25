/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_parser.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 01:24:26 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/25 08:34:09 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void				parse_map(t_game *vars, int fd)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line) && *line == ' '))
	{
		printf("line=%s\n", line);
		free(line);
	}
	if (ret == -1)
		exit_programs(vars, "Failed to read map.");
}

// void				parse_map(t_game *vars, char *line)
// {
// 	int				walls;
// 	int				n_walls;
// 	int				sprites;
// 	int				count;

// 	count = 0;
// 	n_walls = 0;
// 	walls = 0;
// 	sprites = 0;
// 	while (line[count])
// 	{
// 		if (!ft_strchr(MAP_FLAGS, line[count]))
// 			exit_programs(vars, "Unsupported flag in map!");
// 		if (line[count] == '0')
// 			n_walls++;
// 		if (line[count] == '1')
// 			walls++;
// 		if (line[count] == '2')
// 			sprites++;
// 		if (line[count] == 'N' || line[count] == 'S'
// 		|| line[count] == 'W' || line[count] == 'E')
// 		{
// 			printf("founded a dir! {%c}\n", line[count]);
// 		}
// 		count++;
// 	}
// 	if (walls > 0 && !n_walls && !sprites)
// 		printf("[Debug]full line!\n");
// 	printf("walls=%d, vide=%d, sprites=%d, count=%d\n", walls, n_walls, sprites, count);
// 	printf("%s\n", line);
// }
