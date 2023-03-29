/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/29 21:07:59 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_keyhook(int keycode, t_general *g)
{
	if (keycode == 53)
		close_window(g);
	return (0);
}

void	ft_leaks(void)
{
	system("leaks cube3d");
}

void	init_struct(t_general *g)
{
	g->game = true;
	g->move_speed = 6;
	g->rotate_speed = 4;
	g->wall_img[0].img = mlx_xpm_file_to_image(g->mlx, g->no_texture, \
		&g->wall_img[0].img_width, &g->wall_img[0].img_height);
	g->wall_img[0].addr = mlx_get_data_addr(g->wall_img[0].img, \
		&g->wall_img[0].bits_per_pixel, &g->wall_img[0].line_length, \
		&g->wall_img[0].endian);
	g->wall_img[1].img = mlx_xpm_file_to_image(g->mlx, g->so_texture, \
		&g->wall_img[1].img_width, &g->wall_img[1].img_height);
	g->wall_img[1].addr = mlx_get_data_addr(g->wall_img[1].img, \
		&g->wall_img[1].bits_per_pixel, &g->wall_img[1].line_length, \
		&g->wall_img[1].endian);
	g->wall_img[2].img = mlx_xpm_file_to_image(g->mlx, g->we_texture, \
		&g->wall_img[2].img_width, &g->wall_img[2].img_height);
	g->wall_img[2].addr = mlx_get_data_addr(g->wall_img[2].img, \
		&g->wall_img[2].bits_per_pixel, &g->wall_img[2].line_length, \
		&g->wall_img[2].endian);
	g->wall_img[3].img = mlx_xpm_file_to_image(g->mlx, g->ea_texture, \
		&g->wall_img[3].img_width, &g->wall_img[3].img_height);
	g->wall_img[3].addr = mlx_get_data_addr(g->wall_img[3].img, \
		&g->wall_img[3].bits_per_pixel, &g->wall_img[3].line_length, \
		&g->wall_img[3].endian);
	g->ray_separation = (double)PLAYER_FOV / (WINDOW_WIDTH - 1);

	//SOBRESCRITURA DE LA POSICIÓN DEL JUGADOR PARA PRUEBAS DE RAYCAST
	// g->posx = 1505.412598;
	// g->posy = 572.279907;
	// g->ang = 188.000000;
	
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
	// atexit(ft_leaks);
	general = (t_general *)ft_calloc(sizeof(t_general), 1); // TODO: POR QUÉ ALOCAR NUESTRA VARIABLE GENERAL
	// printf("mapa : %s\n", argv[1]);
	parse_map(general, argv[1]);
	init_window(general);
	init_struct(general);
	mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	mlx_loop_hook(general->mlx, game_loop, general);
	mlx_loop(general->mlx);
	free_all(general);
	return (0);
}
