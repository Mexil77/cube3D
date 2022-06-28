/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:36 by emgarcia          #+#    #+#             */
/*   Updated: 2022/06/28 18:33:19 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_raycast(t_general *g)
{
	double	dir_x;
	double	dir_y;
	double	planex;
	double	planey;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		x;

	dir_x = -1;
	dir_y = 0;
	planex = 0;
	planey = 0.66;
	x = -1;
	while (++x < (int)g->winw)
	{
		camera_x = 2 * x / (double)g->winw - 1;
		raydir_x = dir_x + planex * camera_x;
		raydir_y = dir_y + planey * camera_x;
		printf("camerax: ");
	}
}
