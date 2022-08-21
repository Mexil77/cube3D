/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/16 18:54:01 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static bool	is_map(char *line)
{
	size_t	i;

	if (!line || line[0] == '\n')
		return (false);
	i = -1;
	while (line[++i])
		if (!valid_map_char(line[i]) && line[i] != ' ' && line[i] != '\n')
			return (false);
	return (true);
}

void	count_map(t_general *g, char **file_char)
{
	size_t	longest;
	size_t	i;

	longest = 0;
	i = -1;
	while (file_char[++i])
	{
		if (is_map(file_char[i]))
		{
			g->map_height++;
			if (ft_strlen(file_char[i]) - 1 > longest)
				longest = ft_strlen(file_char[i]) - 1;
		}
	}
	g->map_width = longest;
}

char	*fill_line(t_general *g, char *line)
{
	char	*mapline;
	size_t	i;

	mapline = ft_calloc(sizeof(char), g->map_width + 1);
	if (!mapline)
		return (NULL);
	i = -1;
	while (++i < g->map_width)
	{
		if (i < ft_strlen(line) && line[i] != '\n')
			mapline[i] = line[i];
		else
			mapline[i] = '2';
	}
	return (mapline);
}

void	fill_map(t_general *g, char **file_char)
{
	size_t	i;
	size_t	j;

	g->map = ft_calloc(sizeof(char *), g->map_height + 1);
	if (!g->map)
		return ;
	i = -1;
	j = 0;
	while (file_char[++i])
		if (is_map(file_char[i]))
			g->map[j++] = fill_line(g, file_char[i]);
}

size_t	leng_heigth_file(char *file_name)
{
	size_t	lenght_size;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (0);
	lenght_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		lenght_size++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lenght_size);
}

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
	char	**file_char;

	file_char = file_to_map(file_name);
	count_map(g, file_char);
	fill_map(g, file_char);
	if (validate_map(g))
		printf("Mapa Valido\n");
	else
		printf("Mapa Invalido\n");
	fill_data(g);
	get_caracter_pos(g);
}
