/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/07 14:00:30 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	ft_validtale(t_general *g, size_t xn, size_t yn)
{
	size_t	x;
	size_t	y;

	x = xn / FACTOR;
	y = yn / FACTOR;
	if (g->map[y][x] == '1' || g->map[y][x] == ' ')
		return (false);
	return (true);
}

void	ft_move(t_general *g)
{
	ft_myputpixel(g, g->posx, g->posy, 0x00FFFFFF);
	ft_drawray(g, 0x00FFFFFF);
	if (g->ka)
		g->ang -= (g->span * (MPI / 180));
	if (g->kd)
		g->ang += (g->span * (MPI / 180));
	if ((g->kw || g->ks) && ft_validtale(g,
			g->posx + g->advdir * (cos(g->ang) * g->spav),
			g->posy + g->advdir * (sin(g->ang) * g->spav)))
	{
		g->posx += (g->advdir * cos(g->ang) * g->spav);
		g->posy += (g->advdir * sin(g->ang) * g->spav);
	}
	ft_drawray(g, 0x0000FF00);
	ft_myputpixel(g, g->posx, g->posy, 0x00FF0000);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

int	ft_inigame(t_general *g)
{
	if (g->frame >= 1000)
		g->frame = 0;
	g->frame++;
	if (g->frame % 5 == 0)
		ft_move(g);
	return (0);
}
