/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:29:34 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/26 20:52:12 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_window(t_general *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->window_width, g->window_height, "cube3D");
	if (!g->win)
		ft_error("Error de ventana", g);
	mlx_hook(g->win, 17, 1L << 17, ft_closeredcros, g);
}
