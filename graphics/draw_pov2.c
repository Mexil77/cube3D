/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:42:47 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/20 19:24:43 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static double	remunder(double number, double base)
{
	double	result;

	result = remainder(number, base);
	if (result < 0)
		return (result + base);
	return (result);
}

static void	draw_wall(t_general *g, t_stripe *stripe, t_coll *coll, int x)
{
	int	y_draw;
	int	draw_limit;
	int	y_text_index;
	int	y_text_index_old;
	int	x_text_index;
	int	color;
	double y_perc;
	double y_perc_increase;

	y_draw = stripe->draw_start;
	draw_limit = stripe->draw_end;
	y_perc = (double)(y_draw - stripe->wall_top) / stripe->wall_height;
	y_perc_increase = (double)1 / stripe->wall_height;
	x_text_index = stripe->x_text_index;
	while (y_draw < draw_limit)
	{
		y_text_index = (int)(y_perc * stripe->texture->img_height);
		if (y_text_index != y_text_index_old)
		{
			color = wall_color(stripe->texture, x_text_index, y_text_index);
			y_text_index_old = y_text_index;
		}
		draw_pixel(&g->img_pov, x, y_draw++, color);
		y_perc += y_perc_increase;
	}
}

static void	draw_ceiling_n_floor(t_general *g, int end, int x)
{
	int	y_draw;

	y_draw = 0;
	while (y_draw < end)
		draw_pixel(&g->img_pov, x, y_draw++, g->color_celing);
	y_draw = WINDOW_HEIGHT - end;
	while (y_draw < WINDOW_HEIGHT)
		draw_pixel(&g->img_pov, x, y_draw++, g->color_floor);
}

static void	draw_column(t_general *g, int x, float angle, t_coll *coll)
{
	t_stripe	stripe;

	if (angle < 360)
		angle += 360;
	stripe.wall_height = (int)round(TILE_SIZE * WINDOW_HEIGHT \
									/ (coll->dist * cos(to_rad(angle))));
	stripe.wall_top = WINDOW_HEIGHT / 2 - stripe.wall_height / 2;
	if (coll->object == '1')
		stripe.texture = &g->wall_img[coll->orientation];
	else if (coll->object == '3')
		stripe.texture = &g->door_img;
	stripe.x_text_index = (int)(coll->index * stripe.texture->img_width);
	if (stripe.wall_height < WINDOW_HEIGHT)
	{
		stripe.draw_start = stripe.wall_top;
		stripe.draw_end = WINDOW_HEIGHT - stripe.wall_top;
		draw_ceiling_n_floor(g, stripe.wall_top, x);
	}
	else
	{
		stripe.draw_start = 0;
		stripe.draw_end = WINDOW_HEIGHT;
	}
	draw_wall(g, &stripe, coll, x);
}

void	draw_pov(t_general *g)
{
	double	ang;
	int		numrays;
	t_coll	coll;

	numrays = -1;
	ang = g->ang - PLAYER_FOV / 2;
	if (ang < 0)
		ang += 360;
	while (++numrays < WINDOW_WIDTH)
	{
		if (ang >= 360)
			ang -= 360;
		find_coll(g, ang, &coll);
		draw_column(g, numrays, g->ang - ang, &coll);
		ang += g->ray_separation;
	}
}
