/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2022/07/17 18:26:38 by vguttenb         ###   ########.fr       */
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
# ifndef MPI
#  define MPI 3.14159265358979323846
# endif
# ifndef RADGR
#  define RADGR 0.01745329251
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
	bool	game;
	bool	kw;
	bool	ka;
	bool	ks;
	bool	kd;
	int		advdir;
	int		rot;
	size_t	frame;
	int		ang;
	int		spav;
	int		span;
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

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

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
void	ft_closewindow(t_general *g);
float	ft_torad(float grad);

/* Validations */
void	ft_getcaracterpos(t_general *g);
bool	ft_validatemap(t_general *g);

/* Raycast */
void	ft_raycast(t_general *g);

/* Window */
void	ft_window(t_general *g);

/* Draw */
void	ft_myputpixel(t_general *g, int x, int y, int color);
void	ft_drawsquare(t_general *g, size_t x, size_t y, int color);
int		ft_getcolor(int t, int r, int g, int b);
void	ft_drawray(t_general *g, float ang, int color);
void	ft_drawfan(t_general *g, int color);

/* Minimap */
void	ft_minimap(t_general *g);

/* Game */
int		ft_inigame(t_general *g);
bool	ft_validtale(t_general *g, float xn, float yn);

/* main */
void	ft_printgeneral(t_general *g);

#endif