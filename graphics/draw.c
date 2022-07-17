/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:46:43 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/14 14:17:37 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	ft_getcolor(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_drawsquare(t_general *g, size_t x, size_t y, int color)
{
	size_t	xf;
	size_t	yf;

	yf = -1;
	while (++yf < FACTOR)
	{
		xf = -1;
		while (++xf < FACTOR)
			ft_myputpixel(g, x + xf, y + yf, color);
	}
}

void	ft_myputpixel(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->linelenght + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

/* void	ft_drawline()
{
} */

void	ft_drawray(t_general *g, float ang, int color)
{
	size_t	i;
	size_t	xd;
	size_t	yd;

	xd = g->posx + g->advdir * cos(ft_torad(ang));
	yd = g->posy + g->advdir * sin(ft_torad(ang));
	i = 0;
	while (++i && ft_validtale(g, xd, yd))
	{
		ft_myputpixel(g, xd, yd, color);
		xd = g->posx + cos(ft_torad(ang)) * i;
		yd = g->posy + sin(ft_torad(ang)) * i;
	}
}

void	ft_drawfan(t_general *g, int color)
{
	float	ang;
	float	rangfan;
	size_t	numrays;

	numrays = -1;
	rangfan = 30;
	ang = g->ang - rangfan / 2;
	while (++numrays < 1080)
	{
		ft_drawray(g, ang, color);
		ang += (rangfan / 1080);
	}
}
