/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:17:51 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/29 21:03:43 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	pixel_color(t_img *img, int x, int y)
{	
	int	color;

	color = *(int *)(img->addr + y * img->line_length + x \
						* img->bits_per_pixel / 8);
	return (color);
}
