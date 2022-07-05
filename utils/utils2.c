/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:01 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 21:37:07 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_printraycast(t_raycast *r)
{
	printf("camera_x: %f\n", r->camera_x);
	printf("raydir_x: %f\n", r->raydir_x);
	printf("raydir_y: %f\n", r->raydir_y);
	printf("delta_dist_x: %f\n", r->delta_dist_x);
	printf("delta_dist_y: %f\n", r->delta_dist_y);
	printf("side_dist_x: %f\n", r->side_dist_x);
	printf("side_dist_y: %f\n", r->side_dist_y);
	printf("draw-start: %d\n", r->draw_start);
	printf("draw-end: %d\n", r->draw_end);
	printf("\n");
}

void	ft_closewindow(t_general *g)
{
	ft_freeall(g);
	exit(0);
}
