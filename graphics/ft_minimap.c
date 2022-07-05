/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:46:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 22:21:30 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_drawgrid(t_general *g)
{
	size_t	xg;
	size_t	yg;
	int		color;

	yg = -1;
	while (++yg < g->h)
	{
		xg = -1;
		while (++xg < g->w)
		{
			if (g->map[yg][xg] == '1' || g->map[yg][xg] == ' ')
				color = ft_getcolor(0, 0, 0, 0);
			else
				color = ft_getcolor(0, 255, 255, 255);
			ft_drawsquare(g, xg * FACTOR, yg * FACTOR, color);
		}
	}
}

void	ft_drawplayer(t_general *g)
{
	ft_myputpixel(g, g->posx, g->posy, 0x00FF0000);
}

void	ft_eraseplayer(t_general *g)
{
	ft_myputpixel(g, g->posx, g->posy, 0x00FFFFFF);
}

void	ft_minimap(t_general *g)
{
	g->img = mlx_new_image(g->mlx, g->winw, g->winh);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->linelenght, &g->endian);
	ft_drawgrid(g);
	ft_drawplayer(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
