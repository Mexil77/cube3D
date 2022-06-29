/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/06/29 19:32:16 by emgarcia         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	size_t	winh;
	size_t	winw;
	char	**map;
	char	*tn;
	char	*ts;
	char	*te;
	char	*tw;
	char	*f;
	char	*c;
	char	pos;
	void	*img;
	char	*addr;
	int		bpp;
	int		linelenght;
	int		endian;
	size_t	w;
	size_t	h;
	size_t	posx;
	size_t	posy;
}	t_general;

typedef struct s_raycast
{
	double	dir_x;
	double	dir_y;
	double	planex;
	double	planey;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}	t_raycast;

/* Parse */
void	ft_parsemap(t_general *g, char *map);

/* Utils */
void	ft_freesplit(char **split);
bool	ft_validcharmap(char c);
void	ft_error(char *str, t_general *g);
void	ft_freeall(t_general *g);
int		ft_closeredcros(t_general *g);

/* Validations */
void	ft_getcaracterpos(t_general *g);
bool	ft_validatemap(t_general *g);

/* Raycast */
void	ft_raycast(t_general *g);

/* Grapfics */
void	ft_window(t_general *g);

#endif