/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/14 17:50:05 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_keyhook(int keycode, t_general *g)
{
	if (keycode == 53)
		close_window(g);
	return (0);
}

void	init_struct(t_general *g)
{
	g->game = true;
	g->frame = 0;
	g->ang = 0;
	g->move_speed = 6;
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
	else if (keycode == 37)
		draw_pov_diagn(g);
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
	general = (t_general *)ft_calloc(sizeof(t_general), 1);
	printf("mapa : %s\n", argv[1]);
	parse_map(general, argv[1]);
	init_struct(general);
	init_window(general);
	print_general(general);
	test_image(general);
	mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	mlx_loop_hook(general->mlx, game_loop, general);
	mlx_loop(general->mlx);
	free_all(general);
	return (0);
}
