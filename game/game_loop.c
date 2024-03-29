/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/15 19:52:23 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	calc_position(t_general *g)
{
	float	xnew;
	float	ynew;
	float	xprog;
	float	yprog;
	int		steps;

	if (g->rotate_dir != 0)
		g->ang = parse_angle(g->ang + g->rotate_dir * g->rotate_speed);
	//printf("Angle now is %d\n", g->ang);
	if (!g->move_dir)
		return ;
	xprog = g->posx;
	yprog = g->posy;
	steps = 0;
	while (++steps <= g->move_speed)
	{
		xnew = g->posx + g->move_dir * cos(to_rad(g->ang)) * steps;
		if (tile_value(g, (int)xnew, (int)yprog) != '1')
			xprog = xnew;
		ynew = g->posy + g->move_dir * sin(to_rad(g->ang)) * steps;
		if (tile_value(g, (int)xprog, (int)ynew) != '1')
			yprog = ynew;
	}
	g->posx = xprog;
	g->posy = yprog;
}

void	new_frame(t_general *g)
{
	calc_position(g); // CALCULAMOS EL MOVIMIENTO

	//SOLUCIÓN PARA VER EL MAPA
	
	//draw_map(g, &g->img_pov, 0, 0); // DIBUJAMOS EL MINIMAPA
	//draw_player(&g->img_pov, (int)g->posx, (int)g->posy, PLAYER_COLOR);
	//draw_fan(&g->img_pov, g);

	draw_pov(g);
	draw_minimap(&g->img_pov, g, 0, 0);
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

// int	game_loop(t_general *g) // SLOW MOTION
// {
// 	if (g->frame == 1000) {
// 		new_frame(g);
// 		g->frame = 0;
// 	}
// 	g->frame++;
// 	return (0);
// }
