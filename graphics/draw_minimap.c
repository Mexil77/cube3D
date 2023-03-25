/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:49:41 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 18:08:29 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	set_vars(t_minimap *vars, t_general *g)
{
	vars->x_player = 0;
	vars->y_player = 0;
	vars->x_map_start = g->posx - round(MM_SCALE * MM_SIZE / 2);
	vars->y_map_start = g->posy - round(MM_SCALE * MM_SIZE / 2);
	if (vars->x_map_start < 0)
		vars->x_map_start = 0;
	else if (vars->x_map_start + round(MM_SCALE * MM_SIZE) \
				> (int)(g->map_width * TILE_SIZE))
		vars->x_map_start = (int)(g->map_width * TILE_SIZE) \
								- round(MM_SCALE * MM_SIZE);
	else
		vars->x_player = MM_SIZE / 2;
	if (vars->y_map_start < 0)
		vars->y_map_start = 0;
	else if (vars->y_map_start + round(MM_SCALE * MM_SIZE) \
				> (int)(g->map_height * TILE_SIZE))
		vars->y_map_start = (int)(g->map_height * TILE_SIZE) \
								- round(MM_SCALE * MM_SIZE);
	else
		vars->y_player = MM_SIZE / 2;
	if (!vars->x_player)
		vars->x_player = (int)round((g->posx - vars->x_map_start) / MM_SCALE);
	if (!vars->y_player)
		vars->y_player = (int)round((g->posy - vars->y_map_start) / MM_SCALE);
}

void	draw_minimap(t_img *img, t_general *g)
{
	t_minimap	vars;
	int			x_drawn;
	int			y_drawn;
	int			y_increment;
	char		tile_val;

	set_vars(&vars, g);
	y_drawn = -1;
	while (++y_drawn < MM_SIZE)
	{
		x_drawn = -1;
		y_increment = (int)round(y_drawn * MM_SCALE);
		while (++x_drawn < MM_SIZE)
		{
			tile_val = tile_value(g, vars.x_map_start + (int)round(x_drawn \
							* MM_SCALE), vars.y_map_start + y_increment);
			if (tile_val == -1)
				draw_pixel(img, x_drawn, y_drawn, 0x00FF0000);
			if (tile_val == '1' || tile_val == ' ')
				draw_pixel(img, x_drawn, y_drawn, WALL_COLOR);
			else
				draw_pixel(img, x_drawn, y_drawn, g->color_floor);
		}
	}
	draw_player(img, vars.x_player, vars.y_player, PLAYER_COLOR);
}
