/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:45:10 by vguttenb          #+#    #+#             */
/*   Updated: 2023/01/09 21:29:51 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube3d.h"

int	pixel_color(t_img *img, int	x, int y) {
	int	color;

	//void	*right_pixel = (void*)img->addr;
	// char	*right_pixel = img->addr + y * img->line_length + x * img->bits_per_pixel/8;
	// printf("pointer before: %p\n", right_pixel);
	// right_pixel += y * img->line_length + x * img->bits_per_pixel/8;
	// printf("pointer after: %p\n", right_pixel);
	// int	*jeje = (int*)right_pixel;

	//	FALTA INCLUIR UNA MEDIDA DE SEGURIDAD PARA EVITAR SEGFAULT AQUÍ
	if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width)
	{
		printf("CUB3D ERROR: tried fetching color from outside image dimensions\n\ttried fetching color in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
		exit(1);
	}
	
	color = *(int*)(img->addr + y * img->line_length + x * img->bits_per_pixel/8);
	// color = *jeje;
	return (color);
}

int	wall_color(t_img *img, int	x, int y) {
	int	color;

	//void	*right_pixel = (void*)img->addr;
	// char	*right_pixel = img->addr + y * img->line_length + x * img->bits_per_pixel/8;
	// printf("pointer before: %p\n", right_pixel);
	// right_pixel += y * img->line_length + x * img->bits_per_pixel/8;
	// printf("pointer after: %p\n", right_pixel);
	// int	*jeje = (int*)right_pixel;
	if (y < 0 || y >= img->img_height || x < 0 || x >= img->img_width)
	{
		printf("CUB3D ERROR: tried fetching color from outside image dimensions\n\ttried fetching color in x: %d and y: %d\n\tfor an image of dimensions x: %d and y: %d\n", x, y, img->img_width, img->img_height);
		exit(1);
	}

	//	FALTA INCLUIR UNA MEDIDA DE SEGURIDAD PARA EVITAR SEGFAULT AQUÍ
	// printf("Going to check color at x %d and y %d\n", x, y);
	color = *(int*)(img->addr + y * img->line_length + x * img->bits_per_pixel/8);
	// color = *jeje;
	return (color);
}

void	test_image(t_general *g) {
	// printf("%s%s\n", "no_texture: ", g->no_texture);
	
	g->wall_img[0].img = mlx_xpm_file_to_image(g->mlx, g->no_texture, &g->wall_img[0].img_width, &g->wall_img[0].img_height);
	// printf("img: %p\nimg_height: %d\nimg_width: %d\n", g->wall_img[0].img, g->wall_img[0].img_height, g->wall_img[0].img_width);
	
	g->wall_img[0].addr = mlx_get_data_addr(g->wall_img[0].img, &g->wall_img[0].bits_per_pixel, &g->wall_img[0].line_length, &g->wall_img[0].endian);
	// printf("image: %p\nbits_per_pixel: %d\nsize_line: %d\nendian: %d\n", g->wall_img[0].addr, g->wall_img[0].bits_per_pixel, g->wall_img[0].line_length, g->wall_img[0].endian);

	// printf("%s%s\n", "so_texture: ", g->so_texture);
	
	g->wall_img[1].img = mlx_xpm_file_to_image(g->mlx, g->so_texture, &g->wall_img[1].img_width, &g->wall_img[1].img_height);
	// printf("img: %p\nimg_height: %d\nimg_width: %d\n", g->wall_img[1].img, g->wall_img[1].img_height, g->wall_img[1].img_width);
	
	g->wall_img[1].addr = mlx_get_data_addr(g->wall_img[1].img, &g->wall_img[1].bits_per_pixel, &g->wall_img[1].line_length, &g->wall_img[1].endian);
	// printf("image: %p\nbits_per_pixel: %d\nsize_line: %d\nendian: %d\n", g->wall_img[1].addr, g->wall_img[1].bits_per_pixel, g->wall_img[1].line_length, g->wall_img[1].endian);

	// printf("%s%s\n", "we_texture: ", g->we_texture);
	
	g->wall_img[2].img = mlx_xpm_file_to_image(g->mlx, g->we_texture, &g->wall_img[2].img_width, &g->wall_img[2].img_height);
	// printf("img: %p\nimg_height: %d\nimg_width: %d\n", g->wall_img[2].img, g->wall_img[2].img_height, g->wall_img[2].img_width);
	
	g->wall_img[2].addr = mlx_get_data_addr(g->wall_img[2].img, &g->wall_img[2].bits_per_pixel, &g->wall_img[2].line_length, &g->wall_img[2].endian);
	// printf("image: %p\nbits_per_pixel: %d\nsize_line: %d\nendian: %d\n", g->wall_img[2].addr, g->wall_img[2].bits_per_pixel, g->wall_img[2].line_length, g->wall_img[2].endian);

	// printf("%s%s\n", "ea_texture: ", g->ea_texture);
	
	g->wall_img[3].img = mlx_xpm_file_to_image(g->mlx, g->ea_texture, &g->wall_img[3].img_width, &g->wall_img[3].img_height);
	// printf("img: %p\nimg_height: %d\nimg_width: %d\n", g->wall_img[3].img, g->wall_img[3].img_height, g->wall_img[3].img_width);
	
	g->wall_img[3].addr = mlx_get_data_addr(g->wall_img[3].img, &g->wall_img[3].bits_per_pixel, &g->wall_img[3].line_length, &g->wall_img[3].endian);
	// printf("image: %p\nbits_per_pixel: %d\nsize_line: %d\nendian: %d\n", g->wall_img[3].addr, g->wall_img[3].bits_per_pixel, g->wall_img[3].line_length, g->wall_img[3].endian);
	
	g->door_img.img = mlx_xpm_file_to_image(g->mlx, "./res/door_sprite.xpm", &g->door_img.img_width, &g->door_img.img_height);
	// printf("img: %p\nimg_height: %d\nimg_width: %d\n", g->door_img.img, g->door_img.img_height, g->door_img.img_width);
	
	g->door_img.addr = mlx_get_data_addr(g->door_img.img, &g->door_img.bits_per_pixel, &g->door_img.line_length, &g->door_img.endian);
	// printf("image: %p\nbits_per_pixel: %d\nsize_line: %d\nendian: %d\n", g->door_img.addr, g->door_img.bits_per_pixel, g->door_img.line_length, g->door_img.endian);

	
}