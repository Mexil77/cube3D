/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:05:19 by vguttenb          #+#    #+#             */
/*   Updated: 2022/11/29 20:01:24 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	// if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width)
	// {
	// 	printf("CUB3D ERROR: tried painting pixel from outside image dimensions\n\ttried painting pixel in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
	// 	exit(1);
	// }
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
