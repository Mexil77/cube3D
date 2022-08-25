/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:37:02 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/21 07:14:44 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	free_all(t_general *g)
{
	free_split(g->map);
	free_split(g->file_char);
	free(g->no_texture);
	free(g->so_texture);
	free(g->we_texture);
	free(g->ea_texture);
	free (g);
}
