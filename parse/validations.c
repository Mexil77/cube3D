/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:20:18 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/25 19:11:39 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	is_cover(t_general *g, size_t x, size_t y)
{
	if (x > 0 && !valid_map_char(g->map[y][x - 1]))
		return (false);
	if (x < g->map_width - 1 && !valid_map_char(g->map[y][x + 1]))
		return (false);
	if (y > 0 && !valid_map_char(g->map[y - 1][x]))
		return (false);
	if (y < g->map_height - 1 && !valid_map_char(g->map[y + 1][x]))
		return (false);
	return (true);
}

bool	validate_map(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (g->map[i][++j] && j < g->map_width)
			if (g->map[i][j] == '0' && !is_cover(g, j, i))
				return (false);
	}
	return (true);
}

void	get_caracter_pos(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (g->map[i][++j] && j < g->map_width)
		{
			if (g->map[i][j] == 'N' || g->map[i][j] == 'S'
				|| g->map[i][j] == 'W' || g->map[i][j] == 'E')
			{
				g->pos = g->map[i][j];
				g->posx = (float)(j * TILE_SIZE + TILE_SIZE / 2);
				g->posy = (float)(i * TILE_SIZE + TILE_SIZE / 2);
			}
		}
	}
}

bool	check_name_data(t_general *g, size_t i, size_t *j, int opt)
{
	if ((opt == 1 && (g->file_char[i][*j + 1] != 'O'
			|| g->file_char[i][*j + 2] != ' '))
		|| (opt == 2 && (g->file_char[i][*j + 1] != 'O'
			|| g->file_char[i][*j + 2] != ' '))
		|| (opt == 3 && (g->file_char[i][*j + 1] != 'E'
			|| g->file_char[i][*j + 2] != ' '))
		|| (opt == 4 && (g->file_char[i][*j + 1] != 'A'
			|| g->file_char[i][*j + 2] != ' '))
		|| (opt == 5 && g->file_char[i][*j + 1] != ' ')
		|| (opt == 6 && g->file_char[i][*j + 1] != ' '))
		return (false);
	return (true);
}
