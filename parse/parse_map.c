/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:17:54 by emgarcia          #+#    #+#             */
/*   Updated: 2023/01/18 18:37:24 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

bool	is_map(char *line)
{
	size_t	i;

	if (!line || line[0] == '\n')
		return (false);
	i = -1;
	while (line[++i])
		if (!valid_map_char(line[i]) && line[i] != ' ' && line[i] != '\n')
			return (false);
	return (true);
}

void	count_map(t_general *g)
{
	size_t	longest;
	size_t	i;

	longest = 0;
	i = -1;
	while (g->file_char[++i])
	{
		if (is_map(g->file_char[i])) // TODO: ESTO SOLO IGNORA UNA FILA CON UN CARÁCTER RARO, ES NORMAL?
		{
			g->map_height++;
			if (ft_strlen(g->file_char[i]) - 1 > longest)
				longest = ft_strlen(g->file_char[i]) - 1;
		}
	}
	g->map_width = longest;
}

char	*fill_line(t_general *g, char *line)
{
	char	*mapline;
	size_t	i;

	mapline = ft_calloc(sizeof(char), g->map_width + 1);
	if (!mapline)
		return (NULL);
	i = -1;
	while (++i < g->map_width)
	{
		if (i < ft_strlen(line) && line[i] != '\n')
			mapline[i] = line[i];
		else
			mapline[i] = '2';
	}
	return (mapline);
}

void	fill_map(t_general *g)
{
	size_t	i;
	size_t	j;

	g->map = ft_calloc(sizeof(char *), g->map_height + 1);
	if (!g->map)
		return ;
	i = -1;
	j = 0;
	while (g->file_char[++i])
		if (is_map(g->file_char[i]))
			g->map[j++] = fill_line(g, g->file_char[i]);
}

size_t	leng_heigth_file(char *file_name)
{
	size_t	lenght_size;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (0);
	lenght_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		lenght_size++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lenght_size);
}

char	**file_to_map(char *file_name)
{
	char	**map;
	char	*line;
	int		fd;
	size_t	i;

	map = ft_calloc(sizeof(char *), leng_heigth_file(file_name) + 1);
	fd = open(file_name, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i++] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	parse_map(t_general *g, char *file_name)
{
	g->file_char = file_to_map(file_name);
	count_map(g);
	fill_map(g);
	if (validate_map(g))
		printf("Mapa Valido\n");
	else
		printf("Mapa Invalido\n");
	fill_data(g);
	get_caracter_pos(g);
}

// void	get_image(t_general *g, t_img *img, char *file_name)
// {
// 	img->img = mlx_xpm_file_to_image(g->mlx, file_name, &img->img_width, &img->img_height);
// 	if (!img->img)
// 		return ;
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
// }

// bool	get_texture(t_general *g, char *line, char *identifier, int text_index)
// {
// 	char	*end;
// 	char	*file_name;

// 	if (ft_strncmp(line, identifier, 2))
// 		return false;
// 	line += 2;
// 	while (is_empty_space(*line))
// 		line++;
// 	end = line;
// 	while (!is_empty_space(*end) && *end != '\n')
// 		end++;
// 	file_name = ft_substr(line, 0, end - line);
// 	get_image(g, &g->wall_img[text_index], file_name);
// 	free(file_name);
// 	if (!g->wall_img[text_index].img)
// 		return (false);
// 	return (true);
// }

// char	*free_n_replace(char *to_free, char *new_value)
// {
// 	free(to_free);
// 	return (new_value);
// }

// bool	check_textures(t_general *g, int fd)
// {
// 	char	*line;
// 	char	*textures[4];
// 	int		index;

// 	textures[0] = "NO";
// 	textures[1] = "SO";
// 	textures[2] = "WE";
// 	textures[3] = "EA";
// 	line = get_next_line(fd);
// 	while (line && is_empty_line(line))
// 		line = free_n_replace(line, get_next_line(fd));
// 	index = 0;
// 	while (index++ < 4)
// 	{
// 		if (!line || get_texture(g, line, textures[index], index) || index == 3)
// 			break ;
// 		line = free_n_replace(line, get_next_line(fd));
// 		while (line && is_empty_line(line))
// 			line = free_n_replace(line, get_next_line(fd));
// 	}
// 	free(line);
// 	return (g->wall_img[0].img && g->wall_img[1].img && g->wall_img[2].img && g->wall_img[3].img);
// }

// bool	check_floor_n_ceiling(g, fd)
// {
// 	char	*line;
	
// 	line = get_next_line(fd);
// 	while (line && is_empty_line(line))
// 		line = free_n_replace(line, get_next_line(fd));
	
// }

// bool	is_valid_map(t_general *g, char *file_name, int *map_height, int *map_width)
// {
// 	int		fd;

// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 		return (false);
// 	if (check_textures(g, fd))
// 		return (true);
// }

// void	parse_map(t_general *g, char *file_name)
// {
// 	int	map_width;
// 	int	map_height;

// 	map_height = 0;
// 	map_width = 0;
// 	if (is_valid_map(g, file_name, &map_height, &map_width));
// }
