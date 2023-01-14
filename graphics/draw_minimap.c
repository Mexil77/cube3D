/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:49:41 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/14 17:26:01 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static bool	check_valid_minimap(t_general *g, int x_start, int y_start)
{
	(void)g;
	if (MINIMAP_SIZE > WINDOW_WIDTH || MINIMAP_SIZE > WINDOW_HEIGHT)
		return (false);
	if (x_start < 0 || x_start > WINDOW_WIDTH)
		return (false);
	if (y_start < 0 || y_start > WINDOW_HEIGHT)
		return (false);
	return (true);
}

static	bool	set_vars(t_minimap *vars, t_general *g, int x_star, int y_star)
{
	bool	x_pl_off;
	bool	y_pl_off;

	if (!check_valid_minimap(g, x_star, y_star))
		return (false);
	x_pl_off = false;
	y_pl_off = false;
	vars->x_map_start = g->posx - round(MINIMAP_SCALE * MINIMAP_SIZE / 2);
	vars->y_map_start = g->posy - round(MINIMAP_SCALE * MINIMAP_SIZE / 2);
	if (vars->x_map_start < 0 && ++x_pl_off)
		vars->x_map_start = 0;
	if (vars->y_map_start < 0 && ++y_pl_off)
		vars->y_map_start = 0;
	if (vars->x_map_start + round(MINIMAP_SCALE * MINIMAP_SIZE)
		> (int)(g->map_width * TILE_SIZE) && ++x_pl_off)
		vars->x_map_start = (int)(g->map_width * TILE_SIZE) - round(MINIMAP_SCALE * MINIMAP_SIZE);
	if (vars->y_map_start + round(MINIMAP_SCALE * MINIMAP_SIZE)
		> (int)(g->map_height * TILE_SIZE) && ++y_pl_off)
		vars->y_map_start = (int)(g->map_height * TILE_SIZE) - round(MINIMAP_SCALE * MINIMAP_SIZE);
	if (x_pl_off)
		vars->x_player = x_star + (int)round((g->posx - vars->x_map_start) / MINIMAP_SCALE);
	else
		vars->x_player = x_star + MINIMAP_SIZE / 2;
	if (y_pl_off)
		vars->y_player = y_star + (int)round((g->posy - vars->y_map_start) / MINIMAP_SCALE);
	else
		vars->y_player = y_star + MINIMAP_SIZE / 2;
	return (true);
}

void	draw_minimap(t_img *img, t_general *g, int x_start, int y_start)
{
	t_minimap	vars;
	int			x_drawn;
	int			y_drawn;
	int			y_increment;
	char		tile_val;

	if (!set_vars(&vars, g, x_start, y_start))
		return ;
	y_drawn = -1;
	while (++y_drawn < MINIMAP_SIZE)
	{
		x_drawn = -1;
		y_increment = (int)round(y_drawn * MINIMAP_SCALE);
		while (++x_drawn < MINIMAP_SIZE)
		{
			tile_val = tile_value(g, vars.x_map_start + (int)round(x_drawn * MINIMAP_SCALE), vars.y_map_start + y_increment);
			if (tile_val == -1)
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, 0x00FF0000);
			if (tile_val == '1' || tile_val == ' ')
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, WALL_COLOR);
			else
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, g->color_floor);
		}
	}
	draw_player(img, vars.x_player, vars.y_player, PLAYER_COLOR);
}
