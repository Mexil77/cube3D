/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/16 18:36:41 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_general(t_general *g)
{
	size_t	i;

	printf("pos : %c\n", g->pos);
	printf("posx : %f\n", g->posx);
	printf("posy : %f\n", g->posy);
	printf("w : %zu\n", g->map_width);
	printf("h : %zu\n", g->map_height);
	i = -1;
	while (g->map && g->map[++i] && i < g->map_height)
		printf("%s\n", g->map[i]);
}

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
	// g->window_width = g->map_width * TILE_SIZE;
	// g->window_height = g->map_height * TILE_SIZE;
	g->game = true;
	g->frame = 0; //DUDA: POR QUÉ ESTO? YA ES CERO
	g->ang = 0;
	g->move_speed = 4;
	g->rotate_speed = 4;
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
		printf("bad arguments.\n");
		return (0);
	}
	// atexit(ft_leaks);
	general = (t_general *)ft_calloc(sizeof(t_general), 1); // DUDA: POR QUÉ ALOCAR NUESTRA VARIABLE GENERAL
	printf("mapa : %s\n", argv[1]);
	parse_map(general, argv[1]); // RENOMBRADO
	init_struct(general);
	init_window(general);
	print_general(general);
	// mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	// mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	// mlx_key_hook(general->win, ft_keyhook, general);
	// mlx_loop_hook(general->mlx, game_loop, general);
	// mlx_loop(general->mlx);
	free_all(general);
	return (0);
}
