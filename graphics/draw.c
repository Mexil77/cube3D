/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:46:43 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/26 19:02:09 by vguttenb         ###   ########.fr       */
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
	while (++yf < TILE_SIZE)
	{
		xf = -1;
		while (++xf < TILE_SIZE)
			ft_myputpixel(g, x + xf, y + yf, color);
	}
}

void	ft_myputpixel(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->linelenght + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_myputpixel_2(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_drawray(t_general *g, float ang, int color)
{
	int	prog_x;
	int	prog_y;
	int	steps;
	
	prog_x = g->posx;
	prog_y = g->posy;
	steps = 0;
	while (++steps <= 200)
	{
		prog_x = g->posx + steps * cos(ft_torad(ang));
		if (!ft_validtale(g, prog_x, prog_y)) {
			printf("I've encountered something at %d steps\n", steps);
			write(STDERR_FILENO, "AH!\n", 4);
			return ;
		}
		prog_y = g->posy + steps * sin(ft_torad(ang));
		if (!ft_validtale(g, prog_x, prog_y)) {
			printf("I've encountered something at %d steps\n", steps);
			write(STDERR_FILENO, "AH!\n", 4);
			return ;
		}
		ft_myputpixel(g, prog_x, prog_y, color);
	}
	printf("I've encountered nothing\n");
	write(STDERR_FILENO, "AH!\n", 4);
}

void	ft_drawfan(t_general *g, int color)
{
	float	ang;
	size_t	numrays;
	double	increment;

	numrays = -1;
	ang = g->ang - PLAYER_FOV / 2;
	increment = PLAYER_FOV / 60;
	while (++numrays < 60)
	{
		ft_drawray(g, ang, color);
		ang += increment;
	}
}
