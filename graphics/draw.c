/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:46:43 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/17 18:22:43 by vguttenb         ###   ########.fr       */
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
	size_t	xd;
	size_t	yd;
	int		steps;
	
	xd = g->posx;
	yd = g->posy;
	steps = 0;
	while (++steps <= 200)
	{
		xd = g->posx + steps * cos(ft_torad(ang));
		if (!ft_validtale(g, xd, yd))
			break ;
		yd = g->posy + steps * sin(ft_torad(ang));
		if (!ft_validtale(g, xd, yd))
			break ;
		ft_myputpixel(g, xd, yd, color);
	}
}

void	ft_drawfan(t_general *g, int color)
{
	float	ang;
	float	rangfan;
	size_t	numrays;
	double	increment;

	numrays = -1;
	rangfan = 60;
	ang = g->ang - rangfan / 2;
	increment = rangfan / 1080;
	while (++numrays < 1080)
	{
		ft_drawray(g, ang, color);
		ang += increment;
	}
}
