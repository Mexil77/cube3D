/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:46:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 13:14:04 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_drawgrid(t_general *g)
{
	size_t	xg;
	size_t	yg;
	// int		color;

	yg = -1;
	while (++yg < g->h)
	{
		xg = -1;
		while (++xg < g->w)
		{
			if (g->map[yg][xg] == '1')
				ft_drawsquare(g, xg * FACTOR, yg * FACTOR, ft_getcolor(0, 0, 0, 0));
			else
				ft_drawsquare(g, xg * FACTOR, yg * FACTOR, ft_getcolor(0, 255, 255, 255));
		}
	}
}

void	ft_minimap(t_general *g)
{
	g->img = mlx_new_image(g->mlx, g->winw, g->winh);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->linelenght, &g->endian);
	ft_drawgrid(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
