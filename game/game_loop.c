/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2023/04/05 21:39:31 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static bool	is_valid_position(t_general *g, double x, double y)
{
	int	x_check;
	int	y_check;

	x_check = (int)(x - PREC_DIST);
	while (x_check++ < (int)(x + PREC_DIST))
	{
		y_check = (int)(y - PREC_DIST);
		while (y_check++ < (int)(y + PREC_DIST))
		{
			if (tile_value(g, x_check, y_check) == '1')
				return (false);
		}
	}
	return (true);
}

static void	calc_position(t_general *g)
{
	double	double_var[6];
	int		steps;

	if (g->rotate_dir != 0)
		g->ang = parse_angle(g->ang + g->rotate_dir * g->rotate_speed);
	if (!g->move_dir)
		return ;
	double_var[2] = g->posx;
	double_var[3] = g->posy;
	steps = 0;
	double_var[4] = g->move_dir * cos(to_rad(g->ang));
	double_var[5] = g->move_dir * sin(to_rad(g->ang));
	while (++steps <= g->move_speed)
	{
		double_var[0] = g->posx + double_var[4] * steps;
		if (is_valid_position(g, double_var[0], double_var[3]))
			double_var[2] = double_var[0];
		double_var[1] = g->posy + double_var[5] * steps;
		if (is_valid_position(g, double_var[2], double_var[1]))
			double_var[3] = double_var[1];
	}
	g->posx = double_var[2];
	g->posy = double_var[3];
}

static void	new_frame(t_general *g)
{
	calc_position(g);
	draw_pov(g);
	draw_minimap(&g->img_pov, g);
	mlx_put_image_to_window(g->mlx, g->win, g->img_pov.img, 0, 0);
}

int	game_loop(t_general *g)
{
	if (g->frame == 1000)
		g->frame = 0;
	g->frame++;
	if (g->frame % 20 == 0)
		new_frame(g);
	return (0);
}
