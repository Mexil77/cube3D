/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/05 12:59:07 by emgarcia         ###   ########.fr       */
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

# ifndef FACTOR
#  define FACTOR 50
# endif

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
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	prep_wall_dist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	bool	hit;
	bool	side;
}	t_raycast;

/* Parse */
void	ft_parsemap(t_general *g, char *map);

/* Utils */
void	ft_freesplit(char **split);
bool	ft_validcharmap(char c);
void	ft_error(char *str, t_general *g);
void	ft_freeall(t_general *g);
int		ft_closeredcros(t_general *g);

/* Utils 2 */
void	ft_printraycast(t_raycast *r);

/* Validations */
void	ft_getcaracterpos(t_general *g);
bool	ft_validatemap(t_general *g);

/* Raycast */
void	ft_raycast(t_general *g);

/* Window */
void	ft_window(t_general *g);

/* Draw */
void	ft_myputpixel(t_general *g, int x, int y, int color);
void	ft_drawline(t_general *g, int x, int start, int end);
void	ft_drawsquare(t_general *g, size_t x, size_t y, int color);
int		ft_getcolor(int t, int r, int g, int b);

/* Minimap */
void	ft_minimap(t_general *g);

#endif