/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:08:33 by vguttenb          #+#    #+#             */
/*   Updated: 2022/07/25 18:10:31 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_column(t_general *g, int x, int impact_distance, int mode) 
{
	int	wall_heigth;
	int	wall_top;
	int	wall_bottom;
	int	y;

	printf("I've been called to draw a column at distance %d\n", impact_distance);
	(void)mode;
	wall_heigth = (TILE_HEIGHT / (g->projection_dist + impact_distance)) * g->projection_dist;
	wall_top = WINDOW_HEIGTH / 2 - wall_heigth / 2;
	if (wall_top < 0) wall_top = 0;
	wall_bottom = wall_top + wall_heigth;
	if (wall_bottom > WINDOW_HEIGTH) wall_bottom = WINDOW_HEIGTH;
	printf("	with wall height %d wall top %d and wall bottom %d\n", wall_heigth, wall_top, wall_bottom);
	y = -1;
	while (++y < wall_top)
		ft_myputpixel_2(g->img_pov, x, y, CEILING_COLOR);
	// while (++y < wall_bottom) {
	// 	ft_myputpixel_2(g->img_pov, x, y, WALL_COLOR);
	// }
	while (++y < WINDOW_HEIGTH)
		ft_myputpixel_2(g->img_pov, x, y, FLOOR_COLOR);
}

void	project_ray(t_general *g, float ang, int x)
{
	int	prog_x;
	int	prog_y;
	int	steps;
	
	prog_x = g->posx;
	prog_y = g->posy;
	steps = 0;
	printf("I have been summoned for angle %f", ang);
	while (++steps <= 200)
	{
		prog_x = g->posx + steps * cos(ft_torad(ang));
		if (!ft_validtale(g, prog_x, prog_y)){
			printf("A:I've encountered something at %d steps\n", steps);
			write(STDERR_FILENO, "AH!\n", 4);
			return draw_column(g, x, steps, 0); 
		}
		prog_y = g->posy + steps * sin(ft_torad(ang));
		if (!ft_validtale(g, prog_x, prog_y)){
			printf("B:I've encountered something at %d steps\n", steps);
			write(STDERR_FILENO, "AH!\n", 4);
			return draw_column(g, x, steps, 0);
		}
	}
	printf("I've encountered nothing\n");
	write(STDERR_FILENO, "AH!\n", 4);
	return draw_column(g, x, steps, 0);
}

void	generate_pov(t_general *g)
{
	float	ang;
	size_t	numrays;
	float	increment;

	numrays = -1;
	ang = g->ang - PLAYER_FOV / 2;
	increment = (float)PLAYER_FOV / (float)WINDOW_WIDTH;
	printf("My increment is %f\n", increment);
	//write(STDERR_FILENO, "AH!\n", 4);
	float		half_FOV = ft_torad(PLAYER_FOV/2);
	printf("Half of FOV in radiants is %f\n", half_FOV);
	float		tan_half_FOV = tan(half_FOV);
	printf("Its tan is %f\n", tan_half_FOV);
	g->projection_dist = (WINDOW_WIDTH/2)/tan_half_FOV;
	printf(" and my projection dist is %d", g->projection_dist);
	while (++numrays < WINDOW_WIDTH)
	{
		project_ray(g, ang, numrays);
		ang += increment;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img_pov->img, 0, 0);
	while(1);
}

void	draw_pov(t_general *g) 
{
	t_img	img;


	img.img = mlx_new_image(g->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	g->img_pov = &img;
	generate_pov(g);
}