/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_diagn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/14 17:31:19 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static float	dist(float x_origin, float y_origin, float x_col, float y_col)
{
	float	x_side;
	float	y_side;
	float	result;

	x_side = x_origin - x_col;
	y_side = y_origin - y_col;
	result = sqrt(pow(x_side, 2) + pow(y_side, 2));
	return (result);
}

static	float	find_coll_hor_2(t_general *g, float ang)
{
	float	ray_x;
	float	ray_y;
	float	incr_x;
	float	incr_y;
	float	distance;
	float	incr_dist;
	int		deviation = 0;
	
	if (ang == 0 || ang == 180)
		return (MAXFLOAT);
	if (ang > 180)
	{
		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE;
		ray_x = g->posx - (1 / tan(to_rad(ang)) * (g->posy - ray_y));
		incr_y = -TILE_SIZE;
		incr_x = -(1 / tan(to_rad(ang)) * TILE_SIZE);
		deviation = 1;
	}
	else
	{
		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray_x = g->posx + (1 / tan(to_rad(ang)) * (ray_y - g->posy));
		incr_y = TILE_SIZE;
		incr_x = (1 / tan(to_rad(ang)) * TILE_SIZE);
	}
	distance = dist(g->posx, g->posy, ray_x, ray_y);
	incr_dist = dist(0, 0, incr_x, incr_y);
	printf("\tHor check \t%d x and \t%d y\n", (int)ray_x, (int)ray_y - deviation);
	while (tile_value(g, (int)ray_x, (int)ray_y - deviation) == '0')
	{
		ray_x += incr_x;
		ray_y += incr_y;
		distance += incr_dist;
		printf("\tHor check \t%d x and \t%d y\n", (int)ray_x, (int)ray_y - deviation);
	}
	return (distance);
}

static	float	find_coll_vert_2(t_general *g, float ang)
{
	float	ray_x;
	float	ray_y;
	float	incr_x;
	float	incr_y;
	float	distance;
	float	incr_dist;
	int		deviation = 0;

	if (ang == 90 || ang == 270)
		return (MAXFLOAT);
	if (ang > 90 && ang < 270)
	{
		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE;
		ray_y = g->posy - (tan(to_rad(ang)) * (g->posx - ray_x));
		incr_x = -TILE_SIZE;
		incr_y = -(tan(to_rad(ang)) * TILE_SIZE);
		deviation = 1;
	}
	else
	{
		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray_y = g->posy + (tan(to_rad(ang)) * (ray_x - g->posx));
		incr_x = TILE_SIZE;
		incr_y = (tan(to_rad(ang)) * TILE_SIZE);
	}
	distance = dist(g->posx, g->posy, ray_x, ray_y);
	incr_dist = dist(0, 0, incr_x, incr_y);
	printf("\tVert check \t%d x and \t%d y\n", (int)ray_x, (int)ray_y - deviation);
	while (tile_value(g, (int)ray_x - deviation, (int)ray_y) == '0')
	{
		ray_x += incr_x;
		ray_y += incr_y;
		distance += incr_dist;
		printf("\tVert check \t%d x and \t%d y\n", (int)ray_x, (int)ray_y - deviation);
	}
	return (distance);
}

void	draw_pov_diagn(t_general *g)
{
	float	ang;
	int		numrays;
	float	increment;
	float	x_dist;
	float	y_dist;

	numrays = -1;
	ang = g->ang - PLAYER_FOV / 2;
	if (ang < 0)
		ang += 360;
	increment = (float)PLAYER_FOV / WINDOW_WIDTH;
	printf("Player is %f x, %f y and %d angle\n\n", g->posx, g->posy, g->ang);
	while (++numrays < WINDOW_WIDTH)
	{
		ang += increment;
		if (ang >= 360)
			ang -= 360;
		printf("%04dth ray, ang %f\n", numrays, ang);
		y_dist = find_coll_hor_2(g, ang);
		printf("Final distance is \t%f y collission\n", y_dist);
		x_dist = find_coll_vert_2(g, ang);
		printf("Final distance is \t%f x collision\n\n", x_dist);
	}
}
