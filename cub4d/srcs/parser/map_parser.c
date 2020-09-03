/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 01:31:55 by amonteli          #+#    #+#             */
/*   Updated: 2020/08/15 02:05:42 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			format_line(char *line)
{
	int		count;

	count = 0;
	while (line[count] && line[count] == ' ')
	{
		// if (line[count] == ' ')
		line[count] = '0';
		count++;
	}
	printf("%s\n", line);
}

int				is_valid_map_line(char *line)
{
	int		count;

	count = 0;
	if (*line == "1" || *line == "0")
		return (0);
}

void            parse_map(t_game *vars, int fd)
{
	char	*line;

    ft_printf("%s", "Starting parsing map\n");

    while(get_next_line(fd, &line))
    {
		format_line(line);
        // printf("%s\n", line);
        free(line);
    }
    free(line);
}
