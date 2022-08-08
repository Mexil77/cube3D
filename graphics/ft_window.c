/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:29:34 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/08 19:00:48 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_window(t_general *g)
{
	g->mlx = mlx_init();
	//g->win = mlx_new_window(g->mlx, g->window_width, g->window_height, "cube3D");
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cube3D");
	if (!g->win)
		ft_error("Error de ventana", g);
	mlx_hook(g->win, 17, 1L << 17, ft_closeredcros, g);
	g->img_pov.img = mlx_new_image(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	g->img_pov.addr = mlx_get_data_addr(g->img_pov.img, &g->img_pov.bits_per_pixel, &g->img_pov.line_length, &g->img_pov.endian);
	// g->img_minimap.img = mlx_new_image(g->mlx, g->window_width, g->window_height);
	// g->img_minimap.addr = mlx_get_data_addr(g->img_minimap.img, &g->img_minimap.bits_per_pixel, &g->img_minimap.line_length, &g->img_minimap.endian);
}
