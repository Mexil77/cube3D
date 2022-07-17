/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/11 17:51:52 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	ft_ismap(char *line)
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

void	ft_countmap(t_general *g, char *map)
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
			g->h++;
			if (ft_strlen(line) - 1 > longest)
				longest = ft_strlen(line) - 1;
		}
		free (line);
		line = get_next_line(fd);
	}
	g->w = longest;
	close(fd);
}

char	*ft_fillline(t_general *g, char *line)
{
	char	*mapline;
	size_t	i;

	mapline = ft_calloc(sizeof(char), g->w + 1);
	if (!mapline)
		return (NULL);
	i = -1;
	while (++i < g->w)
	{
		if (i < ft_strlen(line) && line[i] != '\n')
			mapline[i] = line[i];
		else
			mapline[i] = '1';
	}
	return (mapline);
}

void	ft_fillmap(t_general *g, char *map)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	g->map = ft_calloc(sizeof(char *), g->h + 1);
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
