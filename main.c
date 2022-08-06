/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/06 17:53:56 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_printgeneral(t_general *g)
{
	size_t	i;

	printf("tn : %s\n", g->tn);
	printf("ts : %s\n", g->ts);
	printf("te : %s\n", g->te);
	printf("tw : %s\n", g->tw);
	printf("f : %s\n", g->f);
	printf("c : %s\n", g->c);
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
		ft_closewindow(g);
	return (0);
}

void	ft_leaks(void)
{
	system("leaks cube3d");
}

void	ft_inistruct(t_general *g)
{
	g->window_width = g->map_width * TILE_SIZE;
	g->window_height = g->map_height * TILE_SIZE;
	g->game = true;
	g->frame = 0; //DUDA: POR QUÉ ESTO? YA ES CERO
	g->ang = 0;
	g->move_speed = 4;
	g->rotate_speed = 4;
}

int	ft_keypress(int keycode, t_general *g)
{
	if (keycode == 53)
		ft_closewindow(g);
	// else if (keycode == 13)
	// 	g->kw = true;
	// else if (keycode == 0)
	// 	g->ka = true;
	// else if (keycode == 1)
	// 	g->ks = true;
	// else if (keycode == 2)
	// 	g->kd = true;
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
	ft_parsemap(general, argv[1]);
	ft_inistruct(general);
	ft_window(general);
	//ft_minimap(general);
	// ft_printgeneral(general);
	mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	// mlx_key_hook(general->win, ft_keyhook, general);
	mlx_loop_hook(general->mlx, ft_game, general);
	mlx_loop(general->mlx);
	ft_freeall(general);
	return (0);
}
