/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:20:18 by emgarcia          #+#    #+#             */
/*   Updated: 2023/04/07 13:49:14 by emgarcia         ###   ########.fr       */
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

void	get_point_cords(char **map, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < double_pointer_len(map))
	{
		j = -1;
		while (++j < ft_strlen(map[0]))
		{
			if (map[i][j] == '.')
			{
				*y = i;
				*x = j;
				return ;
			}
		}
	}
}

bool	validate_map(t_general *g)
{
	char	**aux;
	bool	valid_map;
	size_t	x_cero;
	size_t	y_cero;

	x_cero = 0;
	y_cero = 0;
	aux = duplicate_char_matrix(g->map);
	get_point_cords(aux, &x_cero, &y_cero);
	valid_map = covered(aux, x_cero, y_cero);
	free_split(aux);
	if (!valid_map)
		return (valid_map);
	return (g->color_floor > -1 && g->color_celing > -1 && g->ea_texture
		&& g->no_texture && g->so_texture && g->we_texture
		&& get_texture(g, &g->wall_img[0], g->no_texture)
		&& get_texture(g, &g->wall_img[1], g->so_texture)
		&& get_texture(g, &g->wall_img[2], g->we_texture)
		&& get_texture(g, &g->wall_img[3], g->ea_texture));
}

void	get_caracter_pos(t_general *g)
{
	size_t	i;
	size_t	j;
	char	*nesw;

	nesw = "ESWN";
	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (g->map[i][++j] && j < g->map_width)
		{
			if (g->map[i][j] == 'N' || g->map[i][j] == 'S'
				|| g->map[i][j] == 'W' || g->map[i][j] == 'E')
			{			
				g->ang = (ft_strchr(nesw, g->map[i][j]) - nesw) * 90;
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
