/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_counters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:19:49 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/18 19:44:09 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static t_doorc *new_door_count(int x, int y)
{
	t_doorc *ret;

	ret = (t_doorc *)malloc(sizeof(t_doorc));
	ret->next = NULL;
	ret->x_coord = x;
	ret->y_coord = y;
	ret->state = 1;
	return (ret);
}

static t_doorc *add_door_count(t_doorc *list, int x, int y)
{
	t_doorc* iter;

	if (!list)
		return (new_door_count(x, y));
	iter = list;
	while (iter->next)
		iter = iter->next;
	iter->next = new_door_count(x, y);
	return (list);	
}

t_doorc *get_door_counters(t_general *g)
{
	t_doorc *ret;
	size_t	y;
	size_t	x;

	ret = NULL;
	y = 0;
	x = 0;
	while(y < g->map_height)
	{
		x = 0;
		while(x < g->map_width)
		{
			if (g->map[y][x] == '3')
				ret = add_door_count(ret, x, y);
			x++;
		}
		y++;
	}
	
	///PRINTING
	// while (ret) {
	// 	printf("There is a door at %d y and %d x\n", ret->y_coord, ret->x_coord);
	// 	ret = ret->next;
	// }

	return (ret);
}