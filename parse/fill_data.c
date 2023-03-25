/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:01:39 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/25 17:17:21 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	fill_cordenate(t_general *g, size_t i, size_t *j, int opt)
{
	size_t	ini;

	ini = *j + 1;
	while (g->file_char[i][++(*j)] && g->file_char[i][*j] != ' ')
	{
		if (!ft_strncmp(&g->file_char[i][*j], ".xpm", 4))
		{
			*j += 4;
			if (opt == 1)
				g->no_texture = ft_substr(g->file_char[i], ini, (*j) - ini);
			if (opt == 2)
				g->so_texture = ft_substr(g->file_char[i], ini, (*j) - ini);
			if (opt == 3)
				g->we_texture = ft_substr(g->file_char[i], ini, (*j) - ini);
			if (opt == 4)
				g->ea_texture = ft_substr(g->file_char[i], ini, (*j) - ini);
		}
	}
	(*j)--;
}

int	destructuring_get_color(char **rgb)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if (red >= -1 && red < 256 && green >= -1 && green < 256
		&& blue >= -1 && blue < 256)
		return (ft_getcolor(0, red, green, blue));
	return (-1);
}

void	fill_color(t_general *g, char *color, size_t *j, int opt)
{
	size_t	ini;
	char	**rgb;
	char	*temp;

	ini = *j + 1;
	while (color[++(*j)] && color[*j] != ' ' && color[*j] != '\n')
		if ((color[*j] < '0' && color[*j] != ',') || color[*j] > '9')
			return ;
	temp = ft_substr(color, ini, *j - ini);
	rgb = ft_split(temp, ',');
	if (opt == 5 && double_pointer_len(rgb) == 3)
		g->color_floor = destructuring_get_color(rgb);
	if (opt == 6 && double_pointer_len(rgb) == 3)
		g->color_celing = destructuring_get_color(rgb);
	free_split(rgb);
	free(temp);
	(*j)--;
}

void	get_data(t_general *g, size_t i, size_t *j, int opt)
{
	if (!check_name_data(g, i, j, opt))
		return ;
	(*j)++;
	if (opt <= 4)
		*j += 1;
	if (opt > 4)
		fill_color(g, g->file_char[i], j, opt);
	else
		fill_cordenate(g, i, j, opt);
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
