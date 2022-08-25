/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:43:38 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/25 19:25:14 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void draw_tile(t_img *img, int x_start, int y_start, int color)
{
	int	x_draw;
	int	y_draw;

	y_draw = -1;
	while(++y_draw < TILE_SIZE)
	{
		x_draw = -1;
		while (++x_draw < TILE_SIZE)
			draw_pixel(img, x_start + x_draw, y_start + y_draw, color);
	}
}

void	draw_map(t_general *g, t_img *img, int x, int y)
{
	int	tile_x;
	int	tile_y;
	
	(void)x; // ESTÁN AQUÍ PARA CUANDO QUERAMOS ESPECIFICAR EN QUÉ POSICIÓN SE DIBUJARÁ EL MINIMAPA
	(void)y;
	tile_y = -1;
	while (++tile_y < (int)g->map_height)
	{
		tile_x = -1;
		while (++tile_x < (int)g->map_width)
		{
			if (g->map[tile_y][tile_x] == '1' || g->map[tile_y][tile_x] == ' ')
				draw_tile(img, tile_x * TILE_SIZE, tile_y * TILE_SIZE, WALL_COLOR);
			else
				draw_tile(img, tile_x * TILE_SIZE, tile_y * TILE_SIZE, g->color_floor);
		}
	}
}