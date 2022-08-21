/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:01:39 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/21 05:21:49 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_data(t_general *g, size_t i, size_t *j, int opt)
{
	size_t	ini;

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
		return ;
	ini = *j;
	if (opt >= 1 && opt <= 4)
		*j += 2;
	else
		(*j)++;
	while (g->file_char[i][++(*j)])
	{
		if (g->file_char[i][*j] == '.'
			&& !ft_strncmp(&g->file_char[i][*j], ".xpm", 4))
			printf("enconrtado\n");
	}
	--(*j);
}

void	find_data(t_general *g, size_t i)
{
	size_t	j;

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

void	fill_data(t_general *g)
{
	size_t	i;

	i = -1;
	while (g->file_char[++i])
		if (!is_map(g->file_char[i]))
			find_data(g, i);
}
