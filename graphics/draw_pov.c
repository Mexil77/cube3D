/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/06 18:28:16 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void		draw_column(t_general *g, float dist, int x, float angle)
{
	int	wall_height;
	int	wall_top;
	int	wall_bottom;
	int	y_drawn;

	//angle = parse_angle(angle);
	if (angle < 360)
		angle += 360;
	// if (dist >= 1)
	// 	dist *= cos(ft_torad(angle));
	
	wall_height = 0;
	if (dist >= 1)
		wall_height = TILE_SIZE * WINDOW_HEIGHT / (int)round(dist * cos(ft_torad(angle)));
	//printf("%04dth ray: My dist is %f, my angle cos is %f and their product is %f so wall_height is %d\n", x, dist, cos(ft_torad(angle)), (dist * cos(ft_torad(angle))), wall_height);
	if (wall_height > WINDOW_HEIGHT || dist < 1)
		wall_height = WINDOW_HEIGHT;
	wall_top = WINDOW_HEIGHT / 2 - wall_height / 2;
	wall_bottom = wall_top + wall_height;
	y_drawn = 0;
	while (y_drawn < wall_top)
		draw_pixel(&g->img_pov, x, y_drawn++, CEILING_COLOR);
	while (y_drawn < wall_bottom)
		draw_pixel(&g->img_pov, x, y_drawn++, WALL_COLOR);
	while (y_drawn < WINDOW_HEIGHT)
		draw_pixel(&g->img_pov, x, y_drawn++, FLOOR_COLOR);
}

static float	dist(float x_origin, float y_origin, float x_collision, float y_collision)
{
	float x_side;
	float y_side;
	float result;

	x_side = x_origin - x_collision;
	//printf("x_side is %f and its power is %f, ", x_side, pow(x_side, 2));
	y_side = y_origin - y_collision;
	//printf("y_side is %f and its power is %f, ", y_side, pow(y_side, 2));
	result = sqrt(pow(x_side, 2) + pow(y_side, 2));
	//printf("and the result is %f\n", result);
	return (result);
}

static void	cast_ray(t_general *g, float ang, int x)
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
	x_increment = cos(ft_torad(ang));
	y_increment = sin(ft_torad(ang));
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
		if ((int)prog_x % TILE_SIZE == x_newtile && tile_value(g, (int)prog_x, (int)prog_y) == '1')
			return (draw_column(g, dist(g->posx, g->posy, prog_x, prog_y), x, g->ang - ang));
		prog_y += y_increment;
		if ((int)prog_y % TILE_SIZE == y_newtile && tile_value(g, (int)prog_x, (int)prog_y) == '1')
			return (draw_column(g, dist(g->posx, g->posy, prog_x, prog_y), x, g->ang - ang));
			// printf("I've encountered something at %d steps\n", steps);
			// write(STDERR_FILENO, "AH!\n", 4);
			//outline_tile(img, (int)prog_x, (int)prog_y);
			//print_distance(g, prog_x, prog_y);
			//draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
	}
}

void	draw_pov(t_general *g)
{
	float	ang;
	int		numrays;
	float	increment;


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
		//printf("%zuth ray: My angle is %f\n", numrays, ang);
		cast_ray(g, ang, numrays);
	}
	//cast_ray(g, g->ang - PLAYER_FOV / 2, 350);
	//draw_ray(img, g, g->ang);
	//while(1);
}
