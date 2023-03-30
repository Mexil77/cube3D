/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_char_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:43:30 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/30 05:59:28 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	print_matrix(char **m)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < double_pointer_len(m))
	{
		j = -1;
		while (m[i][++j] && j < ft_strlen(m[i]))
			printf("%c", m[i][j]);
		printf("\n");
	}
}

bool	poss_caracter(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

char	**duplicate_char_matrix(char **m)
{
	size_t	i;
	size_t	j;
	char	**dup;

	dup = (char **)ft_calloc(sizeof(char *), double_pointer_len(m) + 1);
	i = -1;
	while (++i < double_pointer_len(m))
		dup[i] = (char *)ft_calloc(sizeof(char), ft_strlen(m[0]) + 1);
	i = -1;
	while (++i < double_pointer_len(m))
	{
		j = -1;
		while (m[i][++j] && j < ft_strlen(m[i]))
		{
			if (poss_caracter(m[i][j]))
				dup[i][j] = '.';
			else
				dup[i][j] = m[i][j];
		}
	}
	return (dup);
}
