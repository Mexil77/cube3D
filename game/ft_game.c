/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 22:38:43 by emgarcia         ###   ########.fr       */
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
	ft_eraseplayer(g);
	if (g->ka && ft_validtale(g, g->posx - 1, g->posy))
		g->posx--;
	if (g->kd && ft_validtale(g, g->posx + 1, g->posy))
		g->posx++;
	if (g->kw && ft_validtale(g, g->posx, g->posy - 1))
		g->posy--;
	if (g->ks && ft_validtale(g, g->posx, g->posy + 1))
		g->posy++;
	ft_drawplayer(g);
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
