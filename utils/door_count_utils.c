/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_count_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/12 21:51:01 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_doorc *new_door_count(int x, int y)
{
	t_doorc *ret;

	ret = (t_doorc *)malloc(sizeof(t_doorc));
	ret->next = NULL;
	ret->x_coord = x;
	ret->y_coord = y;
	ret->state = 1;
	return (ret);
}

t_doorc *add_door_count(t_doorc *list, int x, int y)
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