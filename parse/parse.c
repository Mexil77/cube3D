/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/15 18:12:04 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_freedouble(char **split)
{
	size_t	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free (split);
}

size_t	ft_validline(char *line)
{
	char	**split;
	size_t	i;

	split = ft_split(line, ' ');
	i = -1;
	while (split[++i])
		printf("split[%zu] : %s\n", split[i]);
	ft_freedouble(split);
}

void	ft_parsemap(t_general *g, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		ft_getdataline(line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
}
