/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/30 02:21:08 by emgarcia         ###   ########.fr       */
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
	bool	start_map;

	longest = 0;
	start_map = is_map(g->file_char[0]);
	i = -1;
	while (g->file_char[++i])
	{
		if (start_map)
		{
			g->map_height++;
			if (ft_strlen(g->file_char[i]) - 1 > longest)
				longest = ft_strlen(g->file_char[i]) - 1;
		}
		else
			start_map = is_map(g->file_char[i + 1]);
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
	i = double_pointer_len(g->file_char) - g->map_height - 1;
	j = 0;
	while (g->file_char[++i])
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
