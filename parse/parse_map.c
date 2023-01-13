/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/13 21:21:50 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	is_map(char *line)
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

void	count_map(t_general *g)
{
	size_t	longest;
	size_t	i;

	longest = 0;
	i = -1;
	while (g->file_char[++i])
	{
		if (is_map(g->file_char[i])) // TODO: ESTO SOLO IGNORA UNA FILA CON UN CARÁCTER RARO, ES NORMAL?
		{
			g->map_height++;
			if (ft_strlen(g->file_char[i]) - 1 > longest)
				longest = ft_strlen(g->file_char[i]) - 1;
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

void	fill_map(t_general *g)
{
	size_t	i;
	size_t	j;

	g->map = ft_calloc(sizeof(char *), g->map_height + 1);
	if (!g->map)
		return ;
	i = -1;
	j = 0;
	while (g->file_char[++i])
		if (is_map(g->file_char[i]))
			g->map[j++] = fill_line(g, g->file_char[i]);
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
	g->file_char = file_to_map(file_name);
	count_map(g);
	fill_map(g);
	if (validate_map(g))
		printf("Mapa Valido\n");
	else
		printf("Mapa Invalido\n");
	fill_data(g);
	get_caracter_pos(g);
}

bool	get_texture(t_general *g, char *line, char *identifier, int text_index)
{
	if (ft_strncmp(line, identifier, 2))
		return false;
	line += 2;
	while (is_empty_space(*line))
		line++;
	
}

bool	check_textures(t_general *g, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line || !get_texture(g, line, "NO", 0))
		return (false);
	free(line);
	line = get_next_line(fd);
	if (!line || !get_texture(g, line, "SO", 1))
		return (false);
	free(line);
	line = get_next_line(fd);
	if (!line || !get_texture(g, line, "WE", 2))
		return (false);
	free(line);
	line = get_next_line(fd);
	if (!line || !get_texture(g, line, "EA", 3))
		return (false);
	return (true);
}

bool	is_valid_map(t_general *g, char *file_name, int *map_height, int *map_width)
{
	int		fd;
	char	*line;
	int		index;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	index = 0;
	if (check_textures(g, fd))
		return (true);
}

void	parse_map(t_general *g, char *file_name)
{
	int	map_width;
	int	map_height;

	map_height = 0;
	map_width = 0;
	if (is_valid_map(g, file_name, &map_height, &map_width));
}
