/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/21 13:05:06 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "Libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_general
{
	char	**map;
	char	*tn;
	char	*ts;
	char	*te;
	char	*tw;
	char	*f;
	char	*c;
	char	*pos;
	size_t	w;
	size_t	h;
}	t_general;

/* Parse */
void	ft_parsemap(t_general *g, char *map);

/* Utils */
void	ft_freesplit(char **split);

#endif