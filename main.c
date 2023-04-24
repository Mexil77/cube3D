/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2023/04/24 16:10:32 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	get_texture(t_general *g, t_img *image, char *texture_str)
{
	image->img = mlx_xpm_file_to_image(g->mlx, texture_str, \
		&image->img_width, &image->img_height);
	if (!image->img)
		return (false);
	image->addr = mlx_get_data_addr(image->img, \
		&image->bits_per_pixel, &image->line_length, \
		&image->endian);
	return (true);
}

void	init_struct(t_general *g)
{
	g->game = true;
	g->move_speed = 6;
	g->rotate_speed = 4;
	g->ray_separation = (double)PLAYER_FOV / (WINDOW_WIDTH - 1);
}

int	ft_keypress(int keycode, t_general *g)
{
	if (keycode == 53)
		close_window(g);
	if (keycode == 13)
		g->move_dir = 1;
	else if (keycode == 0)
		g->rotate_dir = -1;
	else if (keycode == 1)
		g->move_dir = -1;
	else if (keycode == 2)
		g->rotate_dir = 1;
	return (0);
}

int	ft_keyrelease(int keycode, t_general *g)
{
	if (keycode == 13)
		g->move_dir = 0;
	else if (keycode == 0)
		g->rotate_dir = 0;
	else if (keycode == 1)
		g->move_dir = 0;
	else if (keycode == 2)
		g->rotate_dir = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	*general;

	if (argc != 2)
	{
		printf("Cub3d error: bad arguments.\n");
		return (0);
	}
	general = (t_general *)ft_calloc(sizeof(t_general), 1);
	general->mlx = mlx_init();
	init_struct(general);
	parse_map(general, argv[1]);
	init_window(general);
	mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	mlx_loop_hook(general->mlx, game_loop, general);
	mlx_loop(general->mlx);
	free_all(general);
	return (0);
}

// void	ft_leaks(void)
// {
// 	system("leaks cube3d");
// }

// print_general(general);
/*
void	print_general(t_general *g)
{
	printf("posx : %f\n", g->posx);
	printf("posy : %f\n", g->posy);
	printf("w : %zu\n", g->map_width);
	printf("h : %zu\n", g->map_height);
	printf("no_texture : %s\n", g->no_texture);
	printf("so_texture : %s\n", g->so_texture);
	printf("we_texture : %s\n", g->we_texture);
	printf("ea_texture : %s\n", g->ea_texture);
	printf("color_floor : %d\n", g->color_floor);
	printf("color_celing : %d\n", g->color_celing);
	print_double_pointer(g->map);
}
*/