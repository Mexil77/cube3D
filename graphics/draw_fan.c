/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:33:40 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/15 19:52:23 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

// static void	outline_tile(t_img *img, int x_coord, int y_coord)
// {
// 	int	x_start = x_coord - (x_coord % TILE_SIZE);
// 	int	y_start = y_coord - (y_coord % TILE_SIZE);
// 	int x_end = x_start + TILE_SIZE - 1;
// 	int y_end = y_start + TILE_SIZE - 1;
// 	int	x_draw;
// 	int	y_draw;

// 	y_draw = y_start;
// 	x_draw = x_start - 1;
// 	while (++x_draw < x_end)
// 		draw_pixel(img, x_draw, y_draw, 0x00FF0000);
// 	y_draw--;
// 	while (++y_draw < y_end)
// 		draw_pixel(img, x_draw, y_draw, 0x00FF0000);
// 	x_draw++;
// 	while (--x_draw > x_start)
// 		draw_pixel(img, x_draw, y_draw, 0x00FF0000);
// 	y_draw++;
// 	while (--y_draw > y_start)
// 		draw_pixel(img, x_draw, y_draw, 0x00FF0000);
// }

// static void	print_distance(t_general *g, float x_collision, float y_collision)
// {
// 	float x_side = g->posx - x_collision;
// 	float y_side = g->posy - y_collision;
// 	float result = sqrt(pow(x_side, 2) + pow(y_side, 2));
// 	printf("Distance is %f\n", result);
// }

static void	draw_ray(t_img *img, t_general *g, float ang)
{
	float	prog_x;
	float	prog_y;
	float	x_increment;
	float	y_increment;
	int		x_newtile;
	int		y_newtile;
	int	steps;
	
	prog_x = g->posx;
	prog_y = g->posy;
	x_increment = cos(to_rad(ang));
	y_increment = sin(to_rad(ang));
	x_newtile = 0;
	y_newtile = 0;
	//printf("Ang is %f now\n", ang);
	if (ang > 90 && ang < 270)
		x_newtile = TILE_SIZE - 1;
	if (ang > 180)
		y_newtile = TILE_SIZE - 1;
	steps = 0;
	while (1)
	{
		//prog_x = g->posx + steps * cos(to_rad(ang));
		prog_x += x_increment;
		//printf("%dth step: prog_x is %f", steps, prog_x);
		if ((int)prog_x % TILE_SIZE == x_newtile && /*!ft_validtale(g, prog_x, prog_y)*/tile_value(g, (int)prog_x, (int)prog_y) == '1') {
			// printf("I've encountered something at %d steps\n", steps);
			// write(STDERR_FILENO, "AH!\n", 4);
			//outline_tile(img, (int)prog_x, (int)prog_y);
			//print_distance(g, prog_x, prog_y);
			draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
			return ;
		}
		//prog_y = g->posy + steps * sin(to_rad(ang));
		prog_y += y_increment;
		//printf(" and prog_y is %f\n", prog_y);
		if ((int)prog_y % TILE_SIZE == y_newtile && /*!ft_validtale(g, prog_x, prog_y)*/tile_value(g, (int)prog_x, (int)prog_y) == '1') {
			// printf("I've encountered something at %d steps\n", steps);
			// write(STDERR_FILENO, "AH!\n", 4);
			//outline_tile(img, (int)prog_x, (int)prog_y);
			//print_distance(g, prog_x, prog_y);
			draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
			return ;
		}
		draw_pixel(img, (int)prog_x, (int)prog_y, SIGHT_COLOR);
	}
	//print_distance(g, prog_x, prog_y);
	// printf("I've encountered nothing\n");
	// write(STDERR_FILENO, "AH!\n", 4);
}

// static void	draw_ray(t_img *img, t_general *g, float ang)
// {
// 	int	prog_x;
// 	int	prog_y;
// 	int	steps;
	
// 	prog_x = g->posx;
// 	prog_y = g->posy;
// 	steps = 0;
// 	while (++steps <= 200)
// 	{
// 		prog_x = g->posx + steps * cos(to_rad(ang));
// 		if (prog_x % TILE_SIZE == 0 && !ft_validtale(g, prog_x, prog_y)) {
// 			// printf("I've encountered something at %d steps\n", steps);
// 			// write(STDERR_FILENO, "AH!\n", 4);
// 			return ;
// 		}
// 		prog_y = g->posy + steps * sin(to_rad(ang));
// 		if (prog_y % TILE_SIZE == 0 && !ft_validtale(g, prog_x, prog_y)) {
// 			// printf("I've encountered something at %d steps\n", steps);
// 			// write(STDERR_FILENO, "AH!\n", 4);
// 			return ;
// 		}
// 		draw_pixel(img, prog_x, prog_y, SIGHT_COLOR);
// 	}
// 	// printf("I've encountered nothing\n");
// 	// write(STDERR_FILENO, "AH!\n", 4);
// }

void	draw_fan(t_img *img, t_general *g)
{
	float	ang;
	size_t	numrays;
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
		draw_ray(img, g, ang);
	}
	//draw_ray(img, g, g->ang);
	//while(1);
}
