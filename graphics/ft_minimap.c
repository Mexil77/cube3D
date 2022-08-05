/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:46:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/05 20:27:28 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

// void	ft_drawgrid(t_general *g)
// {
// 	size_t	xg;
// 	size_t	yg;
// 	int		color;

// 	yg = -1;
// 	while (++yg < g->map_height)
// 	{
// 		xg = -1;
// 		while (++xg < g->map_width)
// 		{
// 			if (g->map[yg][xg] == '1' || g->map[yg][xg] == ' ')
// 				color = ft_getcolor(0, 0, 0, 0);
// 			else
// 				color = ft_getcolor(0, 255, 255, 255);
// 			ft_drawsquare(g, xg * TILE_SIZE, yg * TILE_SIZE, color);
// 		}
// 	}
// }

// void	ft_minimap(t_general *g)
// {
// 	g->img = mlx_new_image(g->mlx, g->window_width, g->window_height);
// 	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->linelenght, &g->endian);
// 	ft_drawgrid(g);
// 	ft_myputpixel(g, (int)g->posx, (int)g->posy, 0x00FF0000);
// 	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
// }
