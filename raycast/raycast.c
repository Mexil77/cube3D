/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:36 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/26 19:49:25 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_base_calc(t_general *g, t_raycast *r, size_t x)
{
	r->camera_x = 2 * x / (double)g->map_width - 1;
	r->raydir_x = r->dir_x + r->planex * r->camera_x;
	r->raydir_y = r->dir_y + r->planey * r->camera_x;
	r->map_x = (int)g->posx;
	r->map_y = (int)g->posy;
	r->delta_dist_x = fabs(1 / r->raydir_x);
	r->delta_dist_y = fabs(1 / r->raydir_y);
}

void	ft_step_condition(t_raycast *r, t_general *g)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->posx - r->map_x);
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->posx);
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->posy - r->map_y);
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->posy);
	}
}

void	ft_find_hit(t_general *g, t_raycast *r)
{
	if (r->side_dist_x < r->side_dist_y)
	{
		r->side_dist_x += r->delta_dist_x;
		r->map_x += r->step_x;
		r->side = false;
	}
	else
	{
		r->side_dist_y += r->delta_dist_y;
		r->map_y += r->map_y;
		r->side = true;
	}
	if (g->map[r->map_x][r->map_y] == '1')
		r->hit = true;
}

void	ft_ray_lenght(t_general *g, t_raycast *r)
{
	r->line_height = (int)(g->map_height / r->prep_wall_dist);
	r->draw_start = -r->line_height / 2 + g->map_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + g->map_height / 2;
	if (r->draw_end < 0)
		r->draw_end = g->map_height - 1;
}

void	ft_raycast(t_general *g)
{
	t_raycast	ray;
	size_t		x;

	ray.dir_x = -1;
	ray.dir_y = 0;
	ray.planex = 0;
	ray.planey = 0.66;
	x = -1;
	while (++x < g->map_width)
	{
		ft_base_calc(g, &ray, x);
		ft_step_condition(&ray, g);
		ray.hit = false;
		while (!ray.hit)
			ft_find_hit(g, &ray);
		if (!ray.side)
			ray.prep_wall_dist = ray.side_dist_x - ray.delta_dist_x;
		else
			ray.prep_wall_dist = ray.side_dist_y - ray.delta_dist_y;
		ft_ray_lenght(g, &ray);
		// ft_drawline(g, x, ray.draw_start, ray.draw_end);
		printf("x: %zu\n", x);
		ft_printraycast(&ray);
	}
}
