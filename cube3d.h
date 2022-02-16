/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/15 13:07:48 by emgarcia         ###   ########.fr       */
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
}	t_general;

#endif