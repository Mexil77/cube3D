/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:03:57 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/26 19:14:29 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_freesplit(char **split)
{
	size_t	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free (split);
}

bool	ft_validcharmap(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '1')
		return (true);
	return (false);
}

int	ft_closeredcros(t_general *g)
{
	ft_freeall(g);
	exit(0);
	return (0);
}

void	ft_freeall(t_general *g)
{
	ft_freesplit(g->map);
	free (g);
}
