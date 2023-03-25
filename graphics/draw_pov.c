/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:56:54 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 19:25:11 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	draw_wall(t_general *g, t_stripe *stripe, int x)
{
	int		int_var[6];
	double	y_perc;
	double	y_perc_increase;

	int_var[0] = stripe->draw_start;
	int_var[1] = stripe->draw_end;
	y_perc = (double)(int_var[0] - stripe->wall_top) / stripe->wall_height;
	y_perc_increase = (double)1 / stripe->wall_height;
	int_var[4] = stripe->x_text_index;
	while (int_var[0] < int_var[1])
	{
		int_var[2] = (int)(y_perc * stripe->texture->img_height);
		if (int_var[2] != int_var[3])
		{
			int_var[5] = pixel_color(stripe->texture, int_var[4], int_var[2]);
			int_var[3] = int_var[2];
		}
		draw_pixel(&g->img_pov, x, int_var[0]++, int_var[5]);
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

static void	draw_column(t_general *g, int x, double angle, t_coll *coll)
{
	t_stripe	stripe;

	if (angle < 360)
		angle += 360;
	stripe.wall_height = (int)round(TILE_SIZE * WINDOW_HEIGHT \
									/ (coll->dist * cos(to_rad(angle))));
	stripe.wall_top = WINDOW_HEIGHT / 2 - stripe.wall_height / 2;
	stripe.texture = &g->wall_img[coll->orientation];
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
	draw_wall(g, &stripe, x);
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
