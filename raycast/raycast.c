/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:36 by emgarcia          #+#    #+#             */
/*   Updated: 2022/06/29 19:43:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_printraycast(t_raycast *r)
{
	printf("camera_x: %f\n", r->camera_x);
	printf("raydir_x: %f\n", r->raydir_x);
	printf("raydir_y: %f\n", r->raydir_y);
	printf("side_dist_x: %f\n", r->side_dist_x);
	printf("side_dist_y: %f\n", r->side_dist_y);
	printf("\n");
}

void	ft_raycast(t_general *g)
{
	t_raycast	ray;
	int			x;

	ray.dir_x = -1;
	ray.dir_y = 0;
	ray.planex = 0;
	ray.planey = 0.66;
	x = -1;
	while (++x < (int)g->w)
	{
		ray.camera_x = 2 * x / (double)g->w - 1;
		ray.raydir_x = ray.dir_x + ray.planex * ray.camera_x;
		ray.raydir_y = ray.dir_y + ray.planey * ray.camera_x;
		ray.map_x = (int)g->posx;
		ray.map_y = (int)g->posy;
		ray.side_dist_x = fabs(1 / ray.raydir_x);
		ray.side_dist_y = fabs(1 / ray.raydir_y);
		if (ray.raydir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (g->posx - ray.map_x);
		}
		else
		{
			ray.step_x = -1;
			ray.side_dist_x = (g->posx - ray.map_x);
		}
		printf("x: %d\n", x);
		ft_printraycast(&ray);
	}
}
