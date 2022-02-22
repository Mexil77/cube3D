/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:27 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/22 13:48:40 by emgarcia         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_general	*general;

	if (argc != 2)
	{
		printf("bad arguments.\n");
		return (0);
	}
	general = (t_general *)ft_calloc(sizeof(t_general), 1);
	general->winw = 2000;
	general->winh = 1000;
	printf("mapa : %s\n", argv[1]);
	ft_parsemap(general, argv[1]);
	ft_raycast(general);
	ft_printgeneral(general);
	ft_freesplit(general->map);
	free (general);
	return (0);
}
