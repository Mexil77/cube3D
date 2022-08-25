/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:49:41 by vguttenb          #+#    #+#             */
/*   Updated: 2022/08/25 19:25:56 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static bool	check_valid_minimap(t_general *g, int x_start, int y_start)
{
	(void)g;

	//ft_putendl_fd("A", STDERR_FILENO);
	// if ((int)round(MINIMAP_SIZE * MINIMAP_SCALE) > (int)g->map_width * TILE_SIZE)
	// 	return (false);
	//ft_putendl_fd("B", STDERR_FILENO);
	// if ((int)round(MINIMAP_SIZE * MINIMAP_SCALE) > (int)g->map_height * TILE_SIZE)
	// 	return (false);
	//ft_putendl_fd("C", STDERR_FILENO);
	if (MINIMAP_SIZE > WINDOW_WIDTH || MINIMAP_SIZE > WINDOW_HEIGHT)
		return (false);
	//ft_putendl_fd("D", STDERR_FILENO);
	if (x_start < 0 || x_start > WINDOW_WIDTH)
		return (false);
	//ft_putendl_fd("E", STDERR_FILENO);
	if (y_start < 0 || y_start > WINDOW_HEIGHT)
		return (false);
	//ft_putendl_fd("F", STDERR_FILENO);
	return (true);
}

static bool	set_vars(t_minimap *vars, t_general *g, int x_start, int y_start)
{
	//BOOLEANOS PARA SABER SI EL PERSONAJE ESTÁ DESCENTRADO EN ALGUNA DE LAS COORDENADAS
	bool	x_pl_off;
	bool	y_pl_off;

	if(!check_valid_minimap(g, x_start, y_start))
		return (false);
	x_pl_off = false;
	y_pl_off = false;
	// printf("g->posx is %f, and the other thing is %f ", g->posx, round(MINIMAP_SCALE * MINIMAP_SIZE / 2));
	vars->x_map_start = g->posx - round(MINIMAP_SCALE * MINIMAP_SIZE / 2);
	// printf("so vars->x_map_start is %f\n", vars->x_map_start);
	vars->y_map_start = g->posy - round(MINIMAP_SCALE * MINIMAP_SIZE / 2);
	/*  
	
	AQUÍ SERÍA NECESARIO COMPROBAR QUE ESTO ESTÁ FUNCIONANDO COMO DEBE
	
	*/
	//COMPROBAMOS QUE LAS COORDENADAS NO SON DEMASIADO BAJAS (EL PERSONAJE ESTÁ JUNTO A LA PARED IZQUIERDA O SUPERIOR DEL MAPA)
	if (vars->x_map_start < 0 && ++x_pl_off)
		vars->x_map_start = 0;
	if (vars->y_map_start < 0 && ++y_pl_off)
		vars->y_map_start = 0;
	//COMPROBAMOS QUE LAS COORDENADAS NO SON DEMASIADO ALTAS
	if (vars->x_map_start + round(MINIMAP_SCALE * MINIMAP_SIZE) > (int)(g->map_width * TILE_SIZE) && ++x_pl_off)
		vars->x_map_start = (int)(g->map_width * TILE_SIZE) - round(MINIMAP_SCALE * MINIMAP_SIZE);
	if (vars->y_map_start + round(MINIMAP_SCALE * MINIMAP_SIZE) > (int)(g->map_height * TILE_SIZE) && ++y_pl_off)
		vars->y_map_start = (int)(g->map_height * TILE_SIZE) - round(MINIMAP_SCALE * MINIMAP_SIZE);
	if (x_pl_off)
		vars->x_player = x_start + (int)round((g->posx - vars->x_map_start) / MINIMAP_SCALE);
	else
		vars->x_player = x_start + MINIMAP_SIZE / 2;
	if (y_pl_off)
		vars->y_player = y_start + (int)round((g->posy - vars->y_map_start) / MINIMAP_SCALE);
	else
		vars->y_player = y_start + MINIMAP_SIZE / 2;
	return (true);
}

void	draw_minimap(t_img *img, t_general *g, int x_start, int y_start)
{
	t_minimap	vars;

	//PÍXELES DIBUJADOS EN LA IMAGEN
	int	x_drawn;
	int	y_drawn;

	//INCREMENTO PARA AHORRAR CÁLCULOS 
	int	y_increment;

	//CHAR PARA AHORRAR CÁLCULOS
	char	tile_val;

	if (!set_vars(&vars, g, x_start, y_start))
		return ;//MAPA NO VÁLIDO Y SALIMOS CON ALGÚN ERROR
	//printf("La posición del jugador es %f x y %f y, así que los píxeles de comienzo en el mapa son %f x y %f y\n", g->posx, g->posy, vars.x_map_start, vars.y_map_start);
	//(void)img;
	
	y_drawn = -1;
	while (++y_drawn < MINIMAP_SIZE)
	{
		x_drawn = -1;
		y_increment = (int)round(y_drawn * MINIMAP_SCALE);
		while (++x_drawn < MINIMAP_SIZE)
		{
			tile_val = tile_value(g, vars.x_map_start + (int)round(x_drawn * MINIMAP_SCALE), vars.y_map_start + y_increment);
			if (tile_val == -1)
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, 0x00FF0000);
			if (tile_val == '1' || tile_val == ' ')
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, WALL_COLOR);
			else
				draw_pixel(img, x_start + x_drawn, y_start + y_drawn, g->color_floor);
		}
	}
	draw_player(img, vars.x_player, vars.y_player, PLAYER_COLOR);
}