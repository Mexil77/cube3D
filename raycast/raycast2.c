/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:39:36 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/26 19:02:33 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

float	ft_distxini(t_general *g, float ang)
{
	if (g->ang > 90 && g->ang < 270)
		return (((g->posx % TILE_SIZE) + 1) / cos(ft_torad(ang)));
	else
		return ((TILE_SIZE - (g->posx % TILE_SIZE)) / cos(ft_torad(ang)));
}

void	ft_calcray(t_general *g, float ang, int color)
{
	float	dxi;
	float	dyi;
	float	dxc;
	float	dyc;

	dxi = ft_distxini(g, ang);
	dyi = ft_distyini(g, ang);
}
