/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:54:37 by emgarcia          #+#    #+#             */
/*   Updated: 2023/03/30 02:45:32 by emgarcia         ###   ########.fr       */
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
# include <float.h>

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

# define MM_SCALE 2
# define MM_SIZE 192

# define WALL_COLOR 0x00000000
# define SIGHT_COLOR 0x00FFFFFF
# define PLAYER_COLOR 0x000000FF

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_coll {
	double	dist;
	double	index;
	int		orientation;
	char	object;
}				t_coll;

typedef struct s_minimap
{
	float	x_map_start;
	float	y_map_start;
	int		x_player;
	int		y_player;
}				t_minimap;

typedef struct s_stripe
{
	int				draw_start;
	int				draw_end;
	int				wall_height;
	int				wall_top;
	int				x_text_index;
	struct s_img	*texture;
}				t_stripe;

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
	double			ang;
	int				move_speed;
	int				rotate_speed;
	int				projection_dist;
	struct s_img	img_pov;
	struct s_img	img_minimap;
	struct s_img	wall_img[4];
	double			ray_separation;
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
double	to_rad(double grad);
void	print_double_pointer(char **double_pointer);
size_t	double_pointer_len(char **double_pointer);
int		ft_getcolor(int t, int r, int g, int b);
double	remunder(double number, double base);
double	dist(double x_a, double y_a, double x_b, double y_b);
int		pixel_color(t_img *img, int x, int y);

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
void	draw_player(t_img *img, int x_pos, int y_pos, int color);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_pov(t_general *g);
void	draw_minimap(t_img *img, t_general *g);

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
void	test_image(t_general *g);

int		wall_color(t_img *img, int x, int y);

/* parse_map */
size_t	leng_heigth_file(char *file_name);
void	count_map(t_general *g);
bool	is_map(char *line);
void	fill_map(t_general *g);

/* Parse_map2 */

char	**file_to_map(char *file_name);
void	parse_map(t_general *g, char *file_name);

/* coll_finder */
void	find_coll(t_general *g, double ray_angle, t_coll *coll);

/* duplicate_char_matrix */
void	print_matrix(char **m);
bool	poss_caracter(char c);
char	**duplicate_char_matrix(char **m);

/* covered */
bool	covered(char **m, size_t x, size_t y);
bool	cover_char(char c);

/* validations */
void	replace_chars(char **map);

#endif