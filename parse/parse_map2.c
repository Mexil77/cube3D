/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:18:59 by emgarcia          #+#    #+#             */
/*   Updated: 2023/04/24 19:26:46 by emgarcia         ###   ########.fr       */
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

bool	check_name_map(char *file_name)
{
	size_t	i;

	i = -1;
	while (file_name[++i])
		if (file_name[i] == '.' && !ft_strncmp(&file_name[i], ".cub\0", 5))
			return (true);
	return (false);
}

void	parse_map(t_general *g, char *file_name)
{
	if (!check_name_map(file_name) || open(file_name, O_RDWR) < 0)
	{
		printf("cub3D: error: Mapa Invalido\n");
		free_all(g);
		exit(0);
	}
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
