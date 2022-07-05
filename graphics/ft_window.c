/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:29:34 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 11:58:00 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_window(t_general *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->winw, g->winh, "cube3D");
	if (!g->win)
		ft_error("Error de ventana", g);
	mlx_hook(g->win, 17, 1L << 17, ft_closeredcros, g);
}
