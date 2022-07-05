/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 22:01:04 by emgarcia         ###   ########.fr       */
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
	printf("posx : %zu\n", g->posx);
	printf("posy : %zu\n", g->posy);
	printf("w : %zu\n", g->w);
	printf("h : %zu\n", g->h);
	i = -1;
	while (g->map && g->map[++i] && i < g->h)
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
	g->winw = g->w * FACTOR;
	g->winh = g->h * FACTOR;
	g->game = true;
	g->frame = 0;
}

int	ft_keypress(int keycode, t_general *g)
{
	if (keycode == 53)
		ft_closewindow(g);
	else if (keycode == 13)
		g->kw = true;
	else if (keycode == 0)
		g->ka = true;
	else if (keycode == 1)
		g->ks = true;
	else if (keycode == 2)
		g->kd = true;
	return (0);
}

int	ft_keyrelease(int keycode, t_general *g)
{
	if (keycode == 53)
		ft_closewindow(g);
	else if (keycode == 13)
		g->kw = false;
	else if (keycode == 0)
		g->ka = false;
	else if (keycode == 1)
		g->ks = false;
	else if (keycode == 2)
		g->kd = false;
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
	general = (t_general *)ft_calloc(sizeof(t_general), 1);
	printf("mapa : %s\n", argv[1]);
	ft_parsemap(general, argv[1]);
	ft_inistruct(general);
	ft_window(general);
	ft_minimap(general);
	// ft_printgeneral(general);
	mlx_hook(general->win, 2, (1L << 0), ft_keypress, general);
	mlx_hook(general->win, 3, (1L << 1), ft_keyrelease, general);
	// mlx_key_hook(general->win, ft_keyhook, general);
	mlx_loop_hook(general->mlx, ft_inigame, general);
	mlx_loop(general->mlx);
	ft_freeall(general);
	return (0);
}
