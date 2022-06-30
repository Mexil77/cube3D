/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:46:43 by emgarcia          #+#    #+#             */
/*   Updated: 2022/06/30 15:30:03 by emgarcia         ###   ########.fr       */
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

void	ft_myputpixel(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->linelenght + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}
