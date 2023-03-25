/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:17:51 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 19:38:15 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	pixel_color(t_img *img, int x, int y)
{	
	int	color;

	if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width) //TODO: QUEREMOS CONSERVAR ESTO?
	{
		printf("CUB3D ERROR: tried fetching color from outside image dimensions\n\ttried fetching color in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
		exit(1);
	}
	color = *(int *)(img->addr + y * img->line_length + x \
						* img->bits_per_pixel / 8);
	return (color);
}
