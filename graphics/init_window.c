/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:29:34 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/14 17:32:23 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	init_window(t_general *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cube3D");
	if (!g->win)
		error("Error de ventana", g);
	mlx_hook(g->win, 17, 1L << 17, close_red_cross, g);
	g->img_pov.img = mlx_new_image(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	g->img_pov.addr = mlx_get_data_addr(g->img_pov.img,
			&g->img_pov.bits_per_pixel,
			&g->img_pov.line_length, &g->img_pov.endian);
}
