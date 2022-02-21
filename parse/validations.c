/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:20:18 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/21 18:47:56 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	ft_iscover(t_general *g, size_t x, size_t y)
{
	if (x > 0 && !ft_validcharmap(g->map[y][x - 1]))
		return (false);
	if (x < g->w - 1 && !ft_validcharmap(g->map[y][x + 1]))
		return (false);
	if (y > 0 && !ft_validcharmap(g->map[y - 1][x]))
		return (false);
	if (y < g->h - 1 && !ft_validcharmap(g->map[y + 1][x]))
		return (false);
	return (true);
}

bool	ft_validatemap(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (g->map[i][++j] && j < g->w)
			if (g->map[i][j] == '0' && !ft_iscover(g, j, i))
				return (false);
	}
	return (true);
}

void	ft_getcaracterpos(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (g->map[i][++j] && j < g->w)
		{
			if (g->map[i][j] == 'N' || g->map[i][j] == 'S'
				|| g->map[i][j] == 'W' || g->map[i][j] == 'E')
			{
				g->pos = g->map[i][j];
				g->posx = j;
				g->posy = i;
			}
		}
	}
}
