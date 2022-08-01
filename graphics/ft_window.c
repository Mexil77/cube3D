/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:29:34 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/01 19:25:10 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_window(t_general *g)
{
	g->mlx = mlx_init();
	//g->win = mlx_new_window(g->mlx, g->window_width, g->window_height, "cube3D");
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGTH * 2, "cube3D");
	if (!g->win)
		ft_error("Error de ventana", g);
	mlx_hook(g->win, 17, 1L << 17, ft_closeredcros, g);
}
