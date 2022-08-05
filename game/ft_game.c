/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/05 20:45:24 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	ft_validtale(t_general *g, float xn, float yn)
{
	size_t	x;
	size_t	y;

	x = xn / TILE_SIZE;
	y = yn / TILE_SIZE;
	if (g->map[y][x] == '1')
		return (false);
	return (true);
}



void	calc_position(t_general *g)
{
	float	xnew;
	float	ynew;
	float	xprog;
	float	yprog;
	int		steps;

	if (g->rotate_dir != 0)
		g->ang = parse_angle(g->ang + g->rotate_dir * g->rotate_speed);
	if (!g->move_dir)
		return ;
	xprog = g->posx;
	yprog = g->posy;
	steps = 0;
	while (++steps <= g->move_speed)
	{
		xnew = g->posx + g->move_dir * cos(ft_torad(g->ang)) * steps;
		if (tile_value(g, (int)xnew, (int)yprog) != '1')
			xprog = xnew;
		ynew = g->posy + g->move_dir * sin(ft_torad(g->ang)) * steps;
		if (tile_value(g, (int)xprog, (int)ynew) != '1')
			yprog = ynew;
	}
	g->posx = xprog;
	g->posy = yprog;
}

void	new_frame(t_general *g)
{
	// t_img	frame;

	// frame.img = mlx_new_image(g->mlx, g->window_width, g->window_height);
	// frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	calc_position(g); // CALCULAMOS EL MOVIMIENTO
	draw_map(g, &g->img_minimap, 0, 0); // DIBUJAMOS EL MINIMAPA
	draw_player(&g->img_minimap, (int)g->posx, (int)g->posy, PLAYER_COLOR);
	draw_fan(&g->img_minimap, g);
	mlx_put_image_to_window(g->mlx, g->win, g->img_minimap.img, 0, 0);
	draw_pov(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img_pov.img, 0, g->window_height);
}

// void	ft_move(t_general *g)
// {
// 	ft_myputpixel(g, g->posx, g->posy, 0x00FFFFFF);
// 	ft_drawfan(g, 0x00FFFFFF);
// 	//ft_keyaction(g);
// 	ft_drawfan(g, 0x0000FF00);
// 	ft_myputpixel(g, g->posx, g->posy, 0x00FF0000);
// 	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
// 	while(1);
// }

void	new_pov(t_general *g)
{
	// t_img	frame;

	// frame.img = mlx_new_image(g->mlx, g->window_width, g->window_height);
	// frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	draw_pov(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img_pov.img, 0, WINDOW_HEIGTH);
}

// int	ft_game(t_general *g)
// {
// 	if (g->frame == 1000)
// 		g->frame = 0;
// 	g->frame++;
// 	if (g->frame % 5 == 0)
// 	{
// 		new_frame(g);
// 		new_pov(g);
// 	}
// 	return (0);
// }

int	ft_game(t_general *g)
{
	if (g->frame == 10000) {
		new_frame(g);
		g->frame = 0;
	}
	g->frame++;
	return (0);
}
