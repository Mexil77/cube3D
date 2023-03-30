/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:35:23 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/30 01:36:31 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	cover_char(char c)
{
	return (c == '1' || c == '0' || c == '.');
}

bool	covered(char **m, size_t x, size_t y)
{
	bool	valid;

	valid = true;
	if (x == 0 || y == 0 || y == double_pointer_len(m) - 1
		|| x == ft_strlen(m[0]) - 1 || !cover_char(m[y - 1][x])
		|| !cover_char(m[y + 1][x]) || !cover_char(m[y][x - 1])
		|| !cover_char(m[y][x + 1]))
		valid = false;
	if (valid && (m[y - 1][x] == '0' || m[y + 1][x] == '0' || m[y][x - 1] == '0'
		|| m[y][x + 1] == '0'))
		m[y][x] = '.';
	if (valid && m[y - 1][x] == '0')
		valid = covered(m, x, y - 1);
	if (valid && m[y + 1][x] == '0')
		valid = covered(m, x, y + 1);
	if (valid && m[y][x - 1] == '0')
		valid = covered(m, x - 1, y);
	if (valid && m[y][x + 1] == '0')
		valid = covered(m, x + 1, y);
	m[y][x] = '.';
	return (valid);
}
