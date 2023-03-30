/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:20:18 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/30 02:45:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	replace_chars(char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < double_pointer_len(map))
	{
		j = -1;
		while (++j < ft_strlen(map[0]))
			if (poss_caracter(map[i][j]))
				map[i][j] = '0';
	}
}

bool	validate_map(t_general *g)
{
	char	**aux;
	bool	valid_map;

	aux = duplicate_char_matrix(g->map);
	valid_map = covered(aux, 9, 1);
	free_split(aux);
	return (valid_map);
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
