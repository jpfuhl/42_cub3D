/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:41:06 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 19:42:13 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"
# include "structs.h"
# include "error.h"

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	launch_parser(t_data *data, t_map *map, char *file_name);

void	check_cub_file_extension(char *file_name);
char	**create_cub_array(t_map *map, char *file_name);
void	read_cub_file(t_map *map, char *file_name);

int		parse_elements(t_data *data, t_map *map, char **cub);
void	set_texture(t_data *data, t_map *map, int type, char *line);
t_image	*get_texture(t_data *data, char *path);
void	set_colour(t_map *map, int type, char *line);
int		convert_rgb_to_hex(t_element *element);

void	parse_map(t_data *data, t_map *map, int pos);
void	set_dimensions(t_map *map, char **cub_file, int i);
void	set_tile_size(t_map *map);
t_tile	**create_tile_grid(t_map *map);
void	set_tile_grid(t_map *map, char **cub_file, int pos);
void	check_grid_borders(t_map *map, t_tile **grid);
void	set_player_position(t_data *data, t_map *map, t_tile **grid);

bool	is_whitespace(char c);

// void	check_map_borders(t_data *data, t_tile **grid);
// char	**create_cub_file_array(t_data *data __attribute__ ((unused)));
// t_tile	**create_grid(t_data *data);
// void	free_cub_file_array(t_data *data);
// void	parse_cub_file(t_data *data);
// int	parse_elements(t_data *data, char **cub_file);
// void	parse_map(t_data *data, int pos);
// void	read_cub_file(t_data *data);
// void	set_colour(t_data *data, int type, char *colour_code);
// void	set_dimensions(t_data *data, char **cub_file, int i);
// void	set_element(t_data *data, char *line);
// void	set_map_array(t_data *data, char **cub_file, int pos);
// void	set_rgb(t_data *data, int type, char **rgb);
// void	set_texture(t_data *data, int type, char *path);

#endif