/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/21 13:39:20 by emgarcia         ###   ########.fr       */
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
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '1' && line[i] != '0'
			&& line[i] != ' ' && line[i] != '\n')
			return (false);
	}
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

char	*ft_validfinal(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (ft_substr(str, 0, ft_strlen(str) - 1));
	return (ft_strdup(str));
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
			g->map[i++] = ft_validfinal(line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_parsemap(t_general *g, char *map)
{
	ft_countmap(g, map);
	ft_fillmap(g, map);
}
