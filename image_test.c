/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:45:10 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/14 17:46:32 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube3d.h"

int	pixel_color(t_img *img, int x, int y)
{
	int	color;

	if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width)
	{
		printf("CUB3D ERROR: tried fetching color from outside image dimensions\n\ttried fetching color in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
		exit(1);
	}
	color = *(int*)(img->addr + y * img->line_length + x * img->bits_per_pixel/8);
	return (color);
}

int	wall_color(t_img *img, int x, int y)
{
	int	color;

	if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width)
	{
		printf("CUB3D ERROR: tried fetching color from outside image dimensions\n\ttried fetching color in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
		exit(1);
	}
	color = *(int*)(img->addr + y * img->line_length + x * img->bits_per_pixel / 8);
	return (color);
}

void	test_image(t_general *g)
{	
	g->wall_img[0].img = mlx_xpm_file_to_image(g->mlx, g->no_texture,
			&g->wall_img[0].img_width, &g->wall_img[0].img_height);
	g->wall_img[0].addr = mlx_get_data_addr(g->wall_img[0].img,
			&g->wall_img[0].bits_per_pixel,
			&g->wall_img[0].line_length, &g->wall_img[0].endian);
	g->wall_img[1].img = mlx_xpm_file_to_image(g->mlx,
			g->so_texture,
			&g->wall_img[1].img_width, &g->wall_img[1].img_height);
	g->wall_img[1].addr = mlx_get_data_addr(g->wall_img[1].img,
			&g->wall_img[1].bits_per_pixel,
			&g->wall_img[1].line_length, &g->wall_img[1].endian);
	g->wall_img[2].img = mlx_xpm_file_to_image(g->mlx,
			g->we_texture,
			&g->wall_img[2].img_width, &g->wall_img[2].img_height);
	g->wall_img[2].addr = mlx_get_data_addr(g->wall_img[2].img,
			&g->wall_img[2].bits_per_pixel,
			&g->wall_img[2].line_length, &g->wall_img[2].endian);
	g->wall_img[3].img = mlx_xpm_file_to_image(g->mlx,
			g->ea_texture,
			&g->wall_img[3].img_width, &g->wall_img[3].img_height);
	g->wall_img[3].addr = mlx_get_data_addr(g->wall_img[3].img,
			&g->wall_img[3].bits_per_pixel,
			&g->wall_img[3].line_length, &g->wall_img[3].endian);
}
