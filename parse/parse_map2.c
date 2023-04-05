/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:18:59 by emgarcia          #+#    #+#             */
/*   Updated: 2023/04/05 19:42:05 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	**file_to_map(char *file_name)
{
	char	**map;
	char	*line;
	int		fd;
	size_t	i;

	map = ft_calloc(sizeof(char *), leng_heigth_file(file_name) + 1);
	fd = open(file_name, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i++] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	parse_map(t_general *g, char *file_name)
{
	g->file_char = file_to_map(file_name);
	count_map(g);
	fill_map(g);
	fill_data(g);
	if (!validate_map(g))
	{
		printf("cub3D: error: Mapa Invalido\n");
		free_all(g);
		exit(0);
	}
	get_caracter_pos(g);
	replace_chars(g->map);
}
