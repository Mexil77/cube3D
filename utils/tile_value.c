/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:10:13 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 18:59:34 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	tile_value(t_general *g, int x_coord, int y_coord)
{
	int	x;
	int	y;

	x = x_coord / TILE_SIZE;
	y = y_coord / TILE_SIZE;
	if (x < 0 || y < 0 || x >= (int)g->map_width || y >= (int)g->map_height)
		return (-1);
	return (g->map[y][x]);
}
