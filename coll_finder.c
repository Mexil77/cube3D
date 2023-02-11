/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:23:11 by vguttenb          #+#    #+#             */
/*   Updated: 2023/02/11 13:51:03 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"


static void find_coll_up(t_general *g, double ang, t_coll *coll)
{
	double	ray_x;
	double	ray_y;
	double	ray_dist;
	
	ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	ray_y = g->posy + (tan(to_rad(ang)) * (ray_x - g->posx));
	while (tile_value(g, (int)ray_x, (int)ray_y) == '0')
	{
		ray_x += TILE_SIZE;
		ray_y += (tan(to_rad(ang)) * TILE_SIZE);
	}
	ray_dist = dist(g->posx, g->posy, ray_x, ray_y);
	if (ray_dist < coll->dist)
	{
		coll->index = (remunder(ray_y, TILE_SIZE)) / TILE_SIZE;
		coll->orientation = 2;
		coll->object = tile_value(g, (int)ray_x, (int)ray_y);
		coll->dist = ray_dist;
	}
}

static void find_coll_down(t_general *g, double ang, t_coll *coll)
{
	double	ray_x;
	double	ray_y;
	double	ray_dist;
	
	ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE;
	ray_y = g->posy - (tan(to_rad(ang)) * (g->posx - ray_x));
	while (tile_value(g, (int)ray_x - 1, (int)ray_y) == '0')
	{
		ray_x -= TILE_SIZE;
		ray_y -= (tan(to_rad(ang)) * TILE_SIZE);
	}
	ray_dist = dist(g->posx, g->posy, ray_x, ray_y);
	if (ray_dist < coll->dist)
	{
		coll->index = (TILE_SIZE - (remunder(ray_y, TILE_SIZE))) / TILE_SIZE;
		coll->orientation = 3;
		coll->object = tile_value(g, (int)ray_x - 1, (int)ray_y);
		coll->dist = ray_dist;
	}
}

static void find_coll_left(t_general *g, double ang, t_coll *coll)
{
	double	ray_x;
	double	ray_y;
	
	ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	ray_x = g->posx + (1/tan(to_rad(ang)) * (ray_y - g->posy));
	while (tile_value(g, (int)ray_x, (int)ray_y) == '0')
	{
		ray_y += TILE_SIZE;
		ray_x += (1/tan(to_rad(ang)) * TILE_SIZE);
	}
	coll->index = (TILE_SIZE - (remunder(ray_x, TILE_SIZE))) / TILE_SIZE;
	coll->orientation = 0;
	coll->object = tile_value(g, (int)ray_x, (int)ray_y);
	coll->dist = dist(g->posx, g->posy, ray_x, ray_y);
}

static void find_coll_right(t_general *g, double ang, t_coll *coll)
{
	double	ray_x;
	double	ray_y;
	
	ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE;
	ray_x = g->posx - (1/tan(to_rad(ang)) * (g->posy - ray_y));
	while (tile_value(g, (int)ray_x, (int)ray_y - 1) == '0')
	{
		ray_y -= TILE_SIZE;
		ray_x -= (1/tan(to_rad(ang)) * TILE_SIZE);
	}
	coll->index = (remunder(ray_x, TILE_SIZE)) / TILE_SIZE;
	coll->orientation = 1;
	coll->object = tile_value(g, (int)ray_x, (int)ray_y - 1);
	coll->dist = dist(g->posx, g->posy, ray_x, ray_y);
}

void	find_coll(t_general *g, double ray_angle, t_coll *coll)
{
	coll->dist = DBL_MAX;
	if (ray_angle > 180)
		find_coll_right(g, ray_angle, coll);
	else if (ray_angle < 180)
		find_coll_left(g, ray_angle, coll);
	if (ray_angle > 90 && ray_angle < 270)
		find_coll_down(g, ray_angle, coll);
	else if (ray_angle < 90 || ray_angle > 270)
		find_coll_up(g, ray_angle, coll);
}