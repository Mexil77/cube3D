/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:49:45 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/14 17:50:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	print_general(t_general *g)
{
	printf("pos : %c\n", g->pos);
	printf("posx : %f\n", g->posx);
	printf("posy : %f\n", g->posy);
	printf("w : %zu\n", g->map_width);
	printf("h : %zu\n", g->map_height);
	printf("no_texture : %s\n", g->no_texture);
	printf("so_texture : %s\n", g->so_texture);
	printf("we_textur : %s\n", g->we_texture);
	printf("ea_texture : %s\n", g->ea_texture);
	printf("color_floor : %d\n", g->color_floor);
	printf("color_celing : %d\n", g->color_celing);
	print_double_pointer(g->map);
}
