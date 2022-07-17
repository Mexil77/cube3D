/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:19:12 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/17 18:27:01 by vguttenb         ###   ########.fr       */
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
	int	xnew;
	int	ynew;
	int	xprog;
	int	yprog;
	int	steps;

	if (g->ka)
		g->ang = (g->ang - g->span) % 360;
	if (g->kd)
		g->ang = (g->ang + g->span) % 360;
	if (g->ang < 0)
		g->ang += 360;
	if (!g->kw && !g->ks)
		return ;
	xprog = g->posx;
	yprog = g->posy;
	steps = 0;
	while (++steps <= g->spav)
	{
		xnew = g->posx + g->advdir * (cos(ft_torad(g->ang)) * steps);
		if (ft_validtale(g, xnew, yprog))
			xprog = xnew;
		ynew = g->posy + g->advdir * (sin(ft_torad(g->ang)) * steps);
		if (ft_validtale(g, xprog, ynew))
			yprog = ynew;
	}
	g->posx = xprog;
	g->posy = yprog;
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

void	ft_pov(t_general *gen) 
{
	t_img	img;

	img.img = mlx_new_image(gen->mlx, gen->map_width, gen->map_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
}

int	ft_inigame(t_general *g)
{
	if (g->frame == 1000)
		g->frame = 0;
	g->frame++;
	if (g->frame % 5 == 0)
		ft_pov(g);
	return (0);
}
