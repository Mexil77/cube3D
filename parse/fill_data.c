/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:01:39 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/21 07:13:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

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

void	fill_cordenate(t_general *g, char *texture, size_t len, int opt)
{
	// printf("texture: %s\n", texture);
	if (opt == 1)
		g->no_texture = ft_substr(texture, 0, len);
	if (opt == 2)
		g->so_texture = ft_substr(texture, 0, len);
	if (opt == 3)
		g->we_texture = ft_substr(texture, 0, len);
	if (opt == 4)
		g->ea_texture = ft_substr(texture, 0, len);
}

void	get_data(t_general *g, size_t i, size_t *j, int opt)
{
	size_t	ini;

	if (!check_name_data(g, i, j, opt))
		return ;
	if (opt >= 1 && opt <= 4)
		*j += 2;
	else
		(*j)++;
	ini = *j + 1;
	while (g->file_char[i][++(*j)] && g->file_char[i][*j] != ' ')
	{
		if (g->file_char[i][*j] == '.' && opt >= 1 && opt <= 4
			&& !ft_strncmp(&g->file_char[i][*j], ".xpm", 4))
		{
			*j += 4;
			fill_cordenate(g, &g->file_char[i][ini], (*j) - ini, opt);
			return ;
		}
	}
	--(*j);
}

void	fill_data(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (g->file_char[++i])
	{
		j = -1;
		while (g->file_char[i][++j])
		{
			if (g->file_char[i][j] == 'N')
				get_data(g, i, &j, 1);
			if (g->file_char[i][j] == 'S')
				get_data(g, i, &j, 2);
			if (g->file_char[i][j] == 'W')
				get_data(g, i, &j, 3);
			if (g->file_char[i][j] == 'E')
				get_data(g, i, &j, 4);
			if (g->file_char[i][j] == 'F')
				get_data(g, i, &j, 5);
			if (g->file_char[i][j] == 'C')
				get_data(g, i, &j, 6);
		}
	}
}
