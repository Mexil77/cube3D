/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:10:13 by vguttenb          #+#    #+#             */
/*   Updated: 2022/07/31 17:22:22 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	tile_value(t_general *g, int x_coord, int y_coord)
{
	int	x;
	int	y;

	x = x_coord / TILE_SIZE;
	y = y_coord / TILE_SIZE;
	//printf("I am tile_value and I am going to return %c for x %d and y %d\n", g->map[y][x], x, y);
	return (g->map[y][x]);
}