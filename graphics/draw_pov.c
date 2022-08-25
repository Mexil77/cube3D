/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/25 19:01:11 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void		draw_column(t_general *g, double dist, int x, float angle)
{
	int	wall_height;
	int	wall_top;
	int	wall_bottom;
	int	y_drawn;

	//angle = parse_angle(angle);
	if (angle < 360)
		angle += 360;
	
	wall_height = 0;
	if (dist >= 1)
		wall_height = (int)round(TILE_SIZE * WINDOW_HEIGHT / (dist * cos(to_rad(angle))));
	if (wall_height > WINDOW_HEIGHT || dist < 1)
		wall_height = WINDOW_HEIGHT;
	//printf("%04dth ray: My dist is %f, my angle cos is %f and their product is %f so wall_height is %d\n\n", x, dist, cos(to_rad(angle)), (dist * cos(to_rad(angle))), wall_height);
	wall_top = WINDOW_HEIGHT / 2 - wall_height / 2;
	wall_bottom = wall_top + wall_height;
	y_drawn = 0;
	while (y_drawn < wall_top)
		draw_pixel(&g->img_pov, x, y_drawn++, g->color_celing);
	while (y_drawn < wall_bottom)
		draw_pixel(&g->img_pov, x, y_drawn++, WALL_COLOR);
	while (y_drawn < WINDOW_HEIGHT)
		draw_pixel(&g->img_pov, x, y_drawn++, g->color_floor);
}

static double	dist(double x_origin, double y_origin, double x_collision, double y_collision)
{
	double x_side;
	double y_side;
	double result;

	x_side = x_origin - x_collision;
	//printf("x_side is %f and its power is %f, ", x_side, pow(x_side, 2));
	y_side = y_origin - y_collision;
	//printf("y_side is %f and its power is %f, ", y_side, pow(y_side, 2));
	result = sqrt(pow(x_side, 2) + pow(y_side, 2));
	//printf("and the result is %f\n", result);
	return (result);
}

static double find_coll_hor(t_general *g, float ang)
{
	double	ray_x;
	double	ray_y;
	
	if (ang == 0 || ang == 180)
		return MAXFLOAT;
	if (ang > 180)
	{
		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE/*- 0.001*/;
		ray_x = g->posx - (1/tan(to_rad(ang)) * (g->posy - ray_y));
		//printf("	player position is %f x and %f y, ray ang is %f, 1st hor collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
		while (tile_value(g, (int)ray_x, (int)ray_y - 1) == '0')
		{
			ray_y -= TILE_SIZE;
			ray_x -= (1/tan(to_rad(ang)) * TILE_SIZE);
			
			//printf("%c\n", tile_value(g, (int)ray_x, (int)ray_y));
		}
		return dist(g->posx, g->posy, ray_x, ray_y);
		//draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x00FF0000);
	}
	else
	{
		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray_x = g->posx + (1/tan(to_rad(ang)) * (ray_y - g->posy));
		//printf("	player position is %f x and %f y, ray ang is %f, 1st hor collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
		while (tile_value(g, (int)ray_x, (int)ray_y) == '0')
		{
			// if ((int)ray_x % TILE_SIZE == 0 && tile_value(g, (int)ray_x - 1, (int)ray_y) != '0' && tile_value(g, (int)ray_x, (int)ray_y - 1) != '0')
			// 	break ;
			ray_y += TILE_SIZE;
			ray_x += (1/tan(to_rad(ang)) * TILE_SIZE);
			
			//sleep(1000);
			//printf("%c\n", tile_value(g, (int)ray_x, (int)ray_y));
		}
		return dist(g->posx, g->posy, ray_x, ray_y);
		// draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x00FF0000);
	}
}

// static float find_coll_hor_2(t_general *g, float ang)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	incr_x;
// 	float	incr_y;
// 	float	distance;
// 	float	incr_dist;
// 	int		deviation = 0;
	
// 	if (ang == 0 || ang == 180)
// 		return MAXFLOAT;
// 	if (ang > 180)
// 	{
// 		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE/*- 0.001*/;
// 		ray_x = g->posx - (1/tan(to_rad(ang)) * (g->posy - ray_y));
		
// 		incr_y = -TILE_SIZE;
// 		incr_x = -(1/tan(to_rad(ang)) * TILE_SIZE);
// 		deviation = 1;

// 	}
// 	else
// 	{
// 		ray_y = (int)(g->posy / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
// 		ray_x = g->posx + (1/tan(to_rad(ang)) * (ray_y - g->posy));
// 		incr_y = TILE_SIZE;
// 		incr_x = (1/tan(to_rad(ang)) * TILE_SIZE);

// 	}
// 	distance = dist(g->posx, g->posy, ray_x, ray_y);
// 	incr_dist = dist(0, 0, incr_x, incr_y);
// 	while (tile_value(g, (int)ray_x, (int)ray_y - deviation) == '0')
// 	{
// 		ray_x += incr_x;
// 		ray_y += incr_y;
// 		distance += incr_dist; 
// 	}
// 	return distance;
// }

static double find_coll_vert(t_general *g, float ang)
{
	double	ray_x;
	double	ray_y;
	
	if (ang == 90 || ang == 270)
		return MAXFLOAT;
	if (ang > 90 && ang < 270)
	{
		
		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE/*- 0.001*/;
		ray_y = g->posy - (tan(to_rad(ang)) * (g->posx - ray_x));
		// h1 = dist(g->posx, g->posy, ray_x, ray_y);
		// h2 = bla bla bla TODO: LA APUESTA SUPER INFERNAL
		//printf("	player position is %f x and %f y, ray ang is %f, 1st vert collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
		while (tile_value(g, (int)ray_x - 1, (int)ray_y) == '0')
		{
			ray_x -= TILE_SIZE;
			ray_y -= (tan(to_rad(ang)) * TILE_SIZE);
			
			//sleep(1000);
			//printf("%c\n", tile_value(g, (int)ray_x, (int)ray_y));
		}
		return dist(g->posx, g->posy, ray_x, ray_y);
		// draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x000000FF);
	}
	else
	{
		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray_y = g->posy + (tan(to_rad(ang)) * (ray_x - g->posx));
		//printf("	player position is %f x and %f y, ray ang is %f, 1st vert collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
		while (tile_value(g, (int)ray_x, (int)ray_y) == '0')
		{
			// if ((int)ray_y % TILE_SIZE == 0 && tile_value(g, (int)ray_x, (int)ray_y - 1) != '0' && tile_value(g, (int)ray_x - 1, (int)ray_y) != '0')
			// 	break ;
			ray_x += TILE_SIZE;
			ray_y += (tan(to_rad(ang)) * TILE_SIZE);
			//sleep(1000);
			//printf("%c\n", tile_value(g, (int)ray_x, (int)ray_y));
		}
		return dist(g->posx, g->posy, ray_x, ray_y);
		// draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x000000FF);
		
	}
}

// static float find_coll_vert_2(t_general *g, float ang)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	incr_x;
// 	float	incr_y;
// 	float	distance;
// 	float	incr_dist;
// 	int		deviation = 0;
	
// 	if (ang == 90 || ang == 270)
// 		return MAXFLOAT;
// 	if (ang > 90 && ang < 270)
// 	{
// 		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE/*- 0.001*/;
// 		ray_y = g->posy - (tan(to_rad(ang)) * (g->posx - ray_x));
// 		// h2 = bla bla bla TODO: LA APUESTA SUPER INFERNAL
// 		//printf("	player position is %f x and %f y, ray ang is %f, 1st vert collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
// 		incr_x = -TILE_SIZE;
// 		incr_y = -(tan(to_rad(ang)) * TILE_SIZE);
// 		deviation = 1;
// 	}
// 	else
// 	{
// 		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
// 		ray_y = g->posy + (tan(to_rad(ang)) * (ray_x - g->posx));
// 		incr_x = TILE_SIZE;
// 		incr_y = (tan(to_rad(ang)) * TILE_SIZE);
		
// 	}
// 	distance = dist(g->posx, g->posy, ray_x, ray_y);
// 	incr_dist = dist(0, 0, incr_x, incr_y);
// 	while (tile_value(g, (int)ray_x - deviation, (int)ray_y) == '0')
// 	{
// 		ray_x += incr_x;
// 		ray_y += incr_y;
// 		distance += incr_dist; 
// 	}
// 	return distance;
// }

void	draw_pov(t_general *g)
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
	//printf("My starting angle is %f\n", ang);
	increment = (float)PLAYER_FOV / WINDOW_WIDTH;
	//printf("My increment is %f\n", increment);
	while (++numrays < WINDOW_WIDTH)
	{
		ang += increment;
		if (ang >= 360)
			ang -= 360;
		y_dist = find_coll_hor(g, ang);
		x_dist = find_coll_vert(g, ang);
		if (x_dist < y_dist)
			draw_column(g, x_dist, numrays, g->ang - ang);
		else
			draw_column(g, y_dist, numrays, g->ang - ang);
		//printf("%zuth ray: My angle is %f\n", numrays, ang);
	}
}
