/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/12 21:51:30 by vguttenb         ###   ########.fr       */
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

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif
# ifndef MPI
#  define MPI 3.14159265358979323846
# endif
# ifndef RADGR
#  define RADGR 0.01745329251
# endif

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PLAYER_FOV 60
# define PLAYER_SIGHT 200

# define MINIMAP_SCALE 2 // NECESITA SER MAYOR QUE 1 (Y A SER POSIBLE POTENCIA DE 2), SI NO HAY QUE HACER FLOAT X_DRAWN E Y_DRAWN EN DRAW_MINIMAP.
# define MINIMAP_SIZE 192

#define WALL_COLOR 0x00000000
//#define WALL_COLOR 0x00C0C0C0
#define SIGHT_COLOR 0x00FFFFFF
#define PLAYER_COLOR 0x000000FF

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_doorc {
	int		x_coord;
	int		y_coord;
	int		state;
	struct sdoorc	*next;
}				t_doorc;

typedef struct	s_coll {
	double	index;
	int		orientation;
	char	object;
}				t_coll;

typedef struct	s_minimap
{
	//PÍXELES DEL MAPA DESDE LOS QUE VAMOS A EMPEZAR A DIBUJAR
	float	x_map_start;
	float	y_map_start;

	//COORDENADAS EN LAS QUE HAY QUE DIBUJAR AL PERSONAJE DENTRO DEL MINIMAP
	int		x_player;
	int		y_player;
}				t_minimap;

typedef struct s_general
{
	void			*mlx;
	void			*win;
	char			**map;
	char			**file_char;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				color_floor;
	int				color_celing;
	char			pos;
	size_t			map_width;
	size_t			map_height;
	double			posx;
	double			posy;
	bool			game;
	int				move_dir;
	int				rotate_dir;
	size_t			frame;
	int				ang;
	int				move_speed;
	int				rotate_speed;
	int				projection_dist;
	struct s_img	img_pov;
	struct s_img	img_minimap;
	struct s_img	wall_img[4];
	struct s_img	door_sprite;
	struct s_doorc	*door_counters;
}	t_general;

/* Parse */
void	print_general(t_general *g);
void	parse_map(t_general *g, char *map);
bool	is_map(char *line);

/* Utils */
void	free_split(char **split);
bool	valid_map_char(char c);
void	error(char *str, t_general *g);
void	free_all(t_general *g);
int		close_red_cross(t_general *g);
int		parse_angle(int angle);
char	tile_value(t_general *g, int x_coord, int y_coord);
void	close_window(t_general *g);
float	to_rad(float grad);
void	print_double_pointer(char **double_pointer);
size_t	double_pointer_len(char **double_pointer);
int		ft_getcolor(int t, int r, int g, int b);
t_doorc *new_door_count(int x, int y);
t_doorc *add_door_count(t_doorc *list, int x, int y);

/* Validations */
void	get_caracter_pos(t_general *g);
bool	validate_map(t_general *g);
bool	check_name_data(t_general *g, size_t i, size_t *j, int opt);

/* Window */
void	init_window(t_general *g);

/* Draw */
void	ft_myputpixel(t_general *g, int x, int y, int color);
void	ft_drawsquare(t_general *g, size_t x, size_t y, int color);
int		ft_getcolor(int t, int r, int g, int b);
void	ft_drawray(t_general *g, float ang, int color);
void	ft_drawfan(t_general *g, int color);
void	draw_map(t_general *g, t_img *img, int x, int y);
void	draw_player(t_img *img, int x_pos, int y_pos, int color);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_fan(t_img *img, t_general *g);
void	draw_pov(t_general *g);
void	draw_minimap(t_img *img, t_general *g, int x_start, int y_start);

/* Minimap */
void	ft_minimap(t_general *g);

/* Game */
int		game_loop(t_general *g);
bool	ft_validtale(t_general *g, float xn, float yn);

/* main */
void	ft_printgeneral(t_general *g);

/* POV */
void	generate_pov(t_general *g);

/* fill_data */
void	fill_data(t_general *g);

/* Diagnose */
void	draw_pov_diagn(t_general *g);

void	test_image(t_general *g);

int	wall_color(t_img *img, int	x, int y);

#endif