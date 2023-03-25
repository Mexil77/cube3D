/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 16:34:09 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

//////////////// TODO: BORRAR /////////////////////////////////

#include <sys/time.h>

///////////////////////////////

static double	remunder(double number, double base)
{
	double result;
	
	result = remainder(number, base);
	if (result < 0)
		return (result + base);
	return (result);
}

static void	draw_wall(t_general *g, int start, int wall_height, t_coll *coll, int x)
{
	int	y_drawn;
	int	drawn_limit;
	int	y_perc_text;
	int	y_perc_text_old;
	int	x_perc_text;
	int	color;
	double y_perc;
	double y_perc_increase;

	y_drawn = start;
	x_perc_text = (int)(coll->index * g->wall_img[coll->orientation].img_width);
	if (y_drawn < 0)
		y_drawn = 0;
	y_perc = (double)(y_drawn - start)/wall_height;
	y_perc_increase = (double)1/wall_height;
	y_perc_text_old = -1;
	drawn_limit = wall_height + start;
	if (drawn_limit > WINDOW_HEIGHT)
		drawn_limit = WINDOW_HEIGHT;
	while (y_drawn < drawn_limit)
	{
		y_perc_text = (int)(y_perc * g->wall_img[coll->orientation].img_height);
		if (y_perc_text != y_perc_text_old)
		{
			color = wall_color(&g->wall_img[coll->orientation], x_perc_text, y_perc_text);
			y_perc_text_old = y_perc_text;
		}
		draw_pixel(&g->img_pov, x, y_drawn++, color);
		y_perc += y_perc_increase;
	}
}

static void	draw_door(t_general *g, int start, int wall_height, t_coll *coll, int x)
{
	int	y_drawn;
	int	drawn_limit;
	int	y_perc_text;
	int	y_perc_text_old;
	int	x_perc_text;
	int	color;
	double y_perc;
	double y_perc_increase;

	y_drawn = start;
	x_perc_text = (int)(coll->index * TILE_SIZE);
	if (y_drawn < 0)
		y_drawn = 0;
	y_perc = (double)(y_drawn - start)/wall_height;
	y_perc_increase = (double)1/wall_height;
	y_perc_text_old = -1;
	drawn_limit = wall_height + start;
	if (drawn_limit > WINDOW_HEIGHT)
		drawn_limit = WINDOW_HEIGHT;
	while (y_drawn < drawn_limit)
	{
		y_perc_text = (int)(y_perc * g->door_img.img_height);
		if (y_perc_text != y_perc_text_old)
		{
			color = wall_color(&g->door_img, x_perc_text, y_perc_text);
			y_perc_text_old = y_perc_text;
		}
		draw_pixel(&g->img_pov, x, y_drawn++, color);
		y_perc += y_perc_increase;
	}
}

static void		draw_ceiling_n_floor(t_general *g, int end, int x)
{
	int	y_drawn;

	y_drawn = 0;
	while (y_drawn < end)
		draw_pixel(&g->img_pov, x, y_drawn++, g->color_celing);
	y_drawn = WINDOW_HEIGHT - end;
	while (y_drawn < WINDOW_HEIGHT)
		draw_pixel(&g->img_pov, x, y_drawn++, g->color_floor);
	
}

static void		draw_column(t_general *g, double dist, int x, float angle, t_coll *coll)
{
	int	wall_height;
	int	wall_top;
	//int	wall_bottom;
	//int	y_drawn;

	//(void)coll;

	//angle = parse_angle(angle);
	if (angle < 360)
		angle += 360;
	
	//if (dist >= 1)
	wall_height = (int)round(TILE_SIZE * WINDOW_HEIGHT / (dist * cos(to_rad(angle))));
	if (wall_height < WINDOW_HEIGHT)
		draw_ceiling_n_floor(g, WINDOW_HEIGHT / 2 - wall_height / 2, x);
	wall_top = WINDOW_HEIGHT / 2 - wall_height / 2;
	if (coll->object == '1')
		draw_wall(g, wall_top, wall_height, coll, x);
	else if (coll->object == '3')
		draw_door(g, wall_top, wall_height, coll, x);
	// if (wall_height > WINDOW_HEIGHT)
	// 	wall_height = WINDOW_HEIGHT;
	// //printf("%04dth ray: My dist is %f, my angle cos is %f and their product is %f so wall_height is %d\n\n", x, dist, cos(to_rad(angle)), (dist * cos(to_rad(angle))), wall_height);
	// wall_top = WINDOW_HEIGHT / 2 - wall_height / 2;
	// wall_bottom = wall_top + wall_height;
	// y_drawn = 0;
	// while (y_drawn < wall_top)
	// 	draw_pixel(&g->img_pov, x, y_drawn++, g->color_celing);
	// // while (y_drawn < wall_bottom) {
	// // 	//printf("coll->index is %f\n", coll->index);
	// // 	draw_pixel(&g->img_pov, x, y_drawn, WALL_COLOR);
	// // 	y_drawn++;
	// // }
	// y_drawn = wall_bottom;
	// while (y_drawn < WINDOW_HEIGHT)
	// 	draw_pixel(&g->img_pov, x, y_drawn++, g->color_floor);
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

static double find_coll_hor(t_general *g, float ang, t_coll *hor_coll)
{
	double	ray_x;
	double	ray_y;
	
	if (ang == 0 || ang == 180)
		return MAXFLOAT; //TODO: SUSTITUIR ESTO POR MAX DOUBLE
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
		hor_coll->index = (remunder(ray_x, TILE_SIZE)) / TILE_SIZE;
		hor_coll->orientation = 1;
		hor_coll->object = tile_value(g, (int)ray_x, (int)ray_y - 1);
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
		hor_coll->index = (TILE_SIZE - (remunder(ray_x, TILE_SIZE))) / TILE_SIZE;
		hor_coll->orientation = 0;
		hor_coll->object = tile_value(g, (int)ray_x, (int)ray_y);
		return dist(g->posx, g->posy, ray_x, ray_y);
		// draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x00FF0000);
	}
}

static double find_coll_vert(t_general *g, float ang, t_coll *vert_coll)
{
	double	ray_x;
	double	ray_y;
	
	if (ang == 90 || ang == 270)
		return MAXFLOAT; //TODO: SUSTITUIR ESTO POR MAX DOUBLE
	if (ang > 90 && ang < 270)
	{
		
		ray_x = (int)(g->posx / TILE_SIZE) * TILE_SIZE;
		ray_y = g->posy - (tan(to_rad(ang)) * (g->posx - ray_x));
		//printf("	player position is %f x and %f y, ray ang is %f, 1st vert collision is %f x and %f y\n", g->posx, g->posy, ang, ray_x, ray_y);
		while (tile_value(g, (int)ray_x - 1, (int)ray_y) == '0')
		{
			ray_x -= TILE_SIZE;
			ray_y -= (tan(to_rad(ang)) * TILE_SIZE);
			
			//sleep(1000);
			//printf("%c\n", tile_value(g, (int)ray_x, (int)ray_y));
		}
		vert_coll->index = (TILE_SIZE - (remunder(ray_y, TILE_SIZE))) / TILE_SIZE;
		vert_coll->orientation = 3;
		vert_coll->object = tile_value(g, (int)ray_x - 1, (int)ray_y);
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
		vert_coll->index = (remunder(ray_y, TILE_SIZE)) / TILE_SIZE;
		vert_coll->orientation = 2;
		vert_coll->object = tile_value(g, (int)ray_x, (int)ray_y);
		return dist(g->posx, g->posy, ray_x, ray_y);
		// draw_player(&g->img_pov, (int)ray_x, (int)ray_y, 0x000000FF);
		
	}
}

//////////////// TODO: BORRAR /////////////////////////////////

int	get_time(struct timeval *time, int t_start)
{
	gettimeofday(time, NULL);
	return ((time->tv_sec * 1000 + time->tv_usec / 1000) - t_start);
}

/////////////////////////////////////////////////

void	draw_pov(t_general *g)
{
	double	ang;
	int		numrays;
	float	increment;

	double	x_dist;
	double	y_dist;

	t_coll	hor_coll;
	t_coll	vert_coll;

	

	numrays = -1;
	//ang = g->ang - PLAYER_FOV / 2;
	// if (ang < 0)
	// 	ang += 360;
	// printf("My starting angle is %f\n", ang);
	increment = (double)PLAYER_FOV / WINDOW_WIDTH; // TODO: Esto puede hacerse solo una vez
	// printf("My increment is %f\n", increment);

	//////////////// TODO: CORRECCIÓN ANTI FISH EYE ////////////////////

	//double max_fov = (WINDOW_WIDTH / 2) / (tan(to_rad(PLAYER_FOV / 2)) * 57.2958);

	double first_angle = g->ang - PLAYER_FOV / 2;
	if (first_angle < 0)
		first_angle += 360;
	ang = first_angle;

	/////////////////////////////////////////////////

	//////////////// TODO: BORRAR ////////////////////
	
	// struct timeval	time;
	// int	time_start;
	// time_start = get_time(&time, 0);

	/////////////////////////////////////////////////

	while (++numrays < WINDOW_WIDTH)
	{
		//ang  = first_angle + atan((numrays / max_fov) * 0.01745329251) * 57.2958;
		ang += increment;
		if (ang >= 360)
			ang -= 360;
		y_dist = find_coll_hor(g, ang, &hor_coll);
		x_dist = find_coll_vert(g, ang, &vert_coll);
		if (x_dist < y_dist)
			draw_column(g, x_dist, numrays, g->ang - ang, &vert_coll);
		else
			draw_column(g, y_dist, numrays, g->ang - ang, &hor_coll);
		//printf("%zuth ray: My angle is %f\n", numrays, ang);
	}
	
	//printf("This frame costed me %d miliseconds\n", get_time(&time, time_start));	// TODO: BORRAR
	
}
