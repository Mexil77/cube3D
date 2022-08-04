/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/04 19:37:55 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

// void	draw_column(t_general *g, int x, int impact_distance, int mode) 
// {
// 	int	wall_heigth;
// 	int	wall_top;
// 	int	wall_bottom;
// 	int	y;

// 	printf("I've been called to draw a column at distance %d\n", impact_distance);
// 	(void)mode;
// 	wall_heigth = (TILE_HEIGHT / (g->projection_dist + impact_distance)) * g->projection_dist;
// 	wall_top = WINDOW_HEIGTH / 2 - wall_heigth / 2;
// 	if (wall_top < 0) wall_top = 0;
// 	wall_bottom = wall_top + wall_heigth;
// 	if (wall_bottom > WINDOW_HEIGTH) wall_bottom = WINDOW_HEIGTH;
// 	printf("	with wall height %d wall top %d and wall bottom %d\n", wall_heigth, wall_top, wall_bottom);
// 	y = -1;
// 	while (++y < wall_top)
// 		ft_myputpixel_2(g->img_pov, x, y, CEILING_COLOR);
// 	// while (++y < wall_bottom) {
// 	// 	ft_myputpixel_2(g->img_pov, x, y, WALL_COLOR);
// 	// }
// 	while (++y < WINDOW_HEIGTH)
// 		ft_myputpixel_2(g->img_pov, x, y, FLOOR_COLOR);
// }

// void	project_ray(t_general *g, float ang, int x)
// {
// 	int	prog_x;
// 	int	prog_y;
// 	int	steps;
	
// 	prog_x = (int)g->posx;
// 	prog_y = (int)g->posy;
// 	steps = 0;
// 	printf("I have been summoned for angle %f", ang);
// 	while (++steps <= 200)
// 	{
// 		prog_x = g->posx + steps * cos(ft_torad(ang));
// 		if (!ft_validtale(g, prog_x, prog_y)){
// 			printf("A:I've encountered something at %d steps\n", steps);
// 			write(STDERR_FILENO, "AH!\n", 4);
// 			return draw_column(g, x, steps, 0); 
// 		}
// 		prog_y = g->posy + steps * sin(ft_torad(ang));
// 		if (!ft_validtale(g, prog_x, prog_y)){
// 			printf("B:I've encountered something at %d steps\n", steps);
// 			write(STDERR_FILENO, "AH!\n", 4);
// 			return draw_column(g, x, steps, 0);
// 		}
// 	}
// 	printf("I've encountered nothing\n");
// 	write(STDERR_FILENO, "AH!\n", 4);
// 	return draw_column(g, x, steps, 0);
// }

// void	generate_pov(t_general *g)
// {
// 	float	ang;
// 	size_t	numrays;
// 	float	increment;

// 	numrays = -1;
// 	ang = g->ang - PLAYER_FOV / 2;
// 	increment = (float)PLAYER_FOV / (float)WINDOW_WIDTH;
// 	printf("My increment is %f\n", increment);
// 	//write(STDERR_FILENO, "AH!\n", 4);
// 	float		half_FOV = ft_torad(PLAYER_FOV/2);
// 	printf("Half of FOV in radiants is %f\n", half_FOV);
// 	float		tan_half_FOV = tan(half_FOV);
// 	printf("Its tan is %f\n", tan_half_FOV);
// 	g->projection_dist = (WINDOW_WIDTH/2)/tan_half_FOV;
// 	printf(" and my projection dist is %d", g->projection_dist);
// 	while (++numrays < WINDOW_WIDTH)
// 	{
// 		project_ray(g, ang, numrays);
// 		ang += increment;
// 	}
// 	mlx_put_image_to_window(g->mlx, g->win, g->img_pov->img, 0, 0);
// 	while(1);
// }

// void	draw_pov(t_general *g) 
// {
// 	t_img	img;


// 	img.img = mlx_new_image(g->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	g->img_pov = &img;
// 	generate_pov(g);
// }

//-------------------

static void		draw_column(t_img *img, float dist, int x, float angle)
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
	printf("%dth ray: My dist is %f, my angle cos is %f and their product is %f\n", x, dist, cos(ft_torad(angle)), (dist * cos(ft_torad(angle))));
	
	wall_height = 0;
	if (dist >= 1)
		wall_height = TILE_SIZE * WINDOW_HEIGTH / (int)round(dist * cos(ft_torad(angle)));
	if (wall_height > WINDOW_HEIGTH || dist < 1)
		wall_height = WINDOW_HEIGTH;
	wall_top = WINDOW_HEIGTH / 2 - wall_height / 2;
	wall_bottom = wall_top + wall_height;
	y_drawn = 0;
	while (y_drawn < wall_top)
		draw_pixel(img, x, y_drawn++, CEILING_COLOR);
	while (y_drawn < wall_bottom)
		draw_pixel(img, x, y_drawn++, WALL_COLOR);
	while (y_drawn < WINDOW_HEIGTH)
		draw_pixel(img, x, y_drawn++, FLOOR_COLOR);
}

static float	dist(float x_origin, float y_origin, float x_collision, float y_collision)
{
	float x_side;
	float y_side;
	float result;

	x_side = x_origin - x_collision;
	y_side = y_origin - y_collision;
	result = sqrt(pow(x_side, 2) + pow(y_side, 2));
	return (result);
}

static void	cast_ray(t_img *img, t_general *g, float ang, int x)
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
			return (draw_column(img, dist(g->posx, g->posy, prog_x, prog_y), x, g->ang - ang));
		prog_y += y_increment;
		if ((int)prog_y % TILE_SIZE == y_newtile && tile_value(g, (int)prog_x, (int)prog_y) == '1')
			return (draw_column(img, dist(g->posx, g->posy, prog_x, prog_y), x, g->ang - ang));
			// printf("I've encountered something at %d steps\n", steps);
			// write(STDERR_FILENO, "AH!\n", 4);
			//outline_tile(img, (int)prog_x, (int)prog_y);
			//print_distance(g, prog_x, prog_y);
			//draw_pixel(img, (int)prog_x, (int)prog_y, 0x0000FF00);
	}
	return (draw_column(img, 201, x, g->ang - ang));
}

void	draw_pov(t_img *img, t_general *g)
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
		cast_ray(img, g, ang, numrays);
	}
	//draw_ray(img, g, g->ang);
	//while(1);
}
