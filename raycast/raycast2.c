/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:39:36 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/14 16:24:55 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

float	ft_distxini(t_general *g, float ang)
{
	if (g->ang > 90 && g->ang < 270)
		return (((g->posx % FACTOR) + 1) / cos(ft_torad(ang)));
	else
		return ((FACTOR - (g->posx % FACTOR)) / cos(ft_torad(ang)));
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
