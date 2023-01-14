/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:33:40 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/14 17:19:59 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	draw_ray(t_img *img, t_general *g, float ang)
{
	float	prog_x;
	float	prog_y;
	float	x_increment;
	float	y_increment;
	int		x_newtile;
	int		y_newtile;
	int		steps;

	prog_x = g->posx;
	prog_y = g->posy;
	x_increment = cos(to_rad(ang));
	y_increment = sin(to_rad(ang));
	x_newtile = 0;
	y_newtile = 0;
	if (ang > 90 && ang < 270)
		x_newtile = TILE_SIZE - 1;
	if (ang > 180)
		y_newtile = TILE_SIZE - 1;
	steps = 0;
	while (1)
	{
		prog_x += x_increment;
		if ((int)prog_x % TILE_SIZE == x_newtile
			&& tile_value(g, (int)prog_x, (int)prog_y) == '1')
		{
			draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
			return ;
		}
		prog_y += y_increment;
		if ((int)prog_y % TILE_SIZE == y_newtile
			&& tile_value(g, (int)prog_x, (int)prog_y) == '1')
		{
			draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
			return ;
		}
		draw_pixel(img, (int)prog_x, (int)prog_y, SIGHT_COLOR);
	}
}

void	draw_fan(t_img *img, t_general *g)
{
	float	ang;
	size_t	numrays;
	float	increment;

	numrays = -1;
	ang = g->ang - PLAYER_FOV / 2;
	if (ang < 0)
		ang += 360;
	increment = (float)PLAYER_FOV / WINDOW_WIDTH;
	while (++numrays < WINDOW_WIDTH)
	{
		ang += increment;
		if (ang >= 360)
			ang -= 360;
		draw_ray(img, g, ang);
	}
}
