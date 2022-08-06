/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/06 17:53:42 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static bool	ft_ismap(char *line)
{
	size_t	i;

	if (!line || line[0] == '\n')
		return (false);
	i = -1;
	while (line[++i])
		if (!ft_validcharmap(line[i]) && line[i] != ' ' && line[i] != '\n')
			return (false);
	return (true);
}

static void	ft_countmap(t_general *g, char *map)
{
	int		fd;
	size_t	longest;
	char	*line;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	longest = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_ismap(line))
		{
			g->map_height++;
			if (ft_strlen(line) - 1 > longest)
				longest = ft_strlen(line) - 1;
		}
		free (line);
		line = get_next_line(fd);
	}
	g->map_width = longest;
	close(fd);
}

static char	*ft_fillline(t_general *g, char *line)
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
			mapline[i] = '1';
	}
	return (mapline);
}

static void	ft_fillmap(t_general *g, char *map)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	g->map = ft_calloc(sizeof(char *), g->map_height + 1);
	if (!g->map)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_ismap(line))
			g->map[i++] = ft_fillline(g, line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_parsemap(t_general *g, char *map)
{
	ft_countmap(g, map);
	ft_fillmap(g, map);
	if (ft_validatemap(g))
		printf("Mapa Valido\n");
	else
		printf("Mapa Invalido\n");
	ft_getcaracterpos(g);
}
