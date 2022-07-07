/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:46:43 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/07 14:14:00 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_drawline(t_general *g, int x, int start, int end)
{
	int		color;
	int		i;

	color = 3000;
	i = start - 1;
	while (++i <= end)
	{
		printf("i: %d\n", i);
		ft_myputpixel(g, x, i, color);
	}
}

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

void	ft_drawray(t_general *g, int color)
{
	size_t	i;
	int		xd;
	int		yd;

	xd = g->posx + g->advdir * cos(g->ang) * 1;
	yd = g->posy + g->advdir * sin(g->ang) * 1;
	i = 1;
	while (ft_validtale(g, xd, yd) && ++i)
	{
		xd = g->posx + g->advdir * cos(g->ang) * i;
		yd = g->posy + g->advdir * sin(g->ang) * i;
		ft_myputpixel(g, xd, yd, color);
	}
	// ft_myputpixel(g, xd, yd, 0x0000000);
}
