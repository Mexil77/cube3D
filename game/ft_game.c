/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/13 20:29:27 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	ft_validtale(t_general *g, float xn, float yn)
{
	size_t	x;
	size_t	y;

	x = xn / FACTOR;
	y = yn / FACTOR;
	if (g->map[y][x] == '1')
		return (false);
	return (true);
}

void	ft_keyaction(t_general *g)
{
	int	xadd;
	int	yadd;

	if (g->ka)
		g->ang = (g->ang - g->span) % 360;
	if (g->kd)
		g->ang = (g->ang + g->span) % 360;
	if (g->ang < 0)
		g->ang += 360;
	xadd = g->advdir * (cos(ft_torad(g->ang)) * g->spav);
	yadd = g->advdir * (sin(ft_torad(g->ang)) * g->spav);
	if ((g->kw || g->ks) && ft_validtale(g, g->posx + xadd, g->posy + yadd))
	{
		g->posx += xadd;
		g->posy += yadd;
	}
}

void	ft_move(t_general *g)
{
	ft_myputpixel(g, g->posx, g->posy, 0x00FFFFFF);
	ft_drawfan(g, 0x00FFFFFF);
	ft_keyaction(g);
	ft_drawfan(g, 0x0000FF00);
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
