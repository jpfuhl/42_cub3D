/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:44:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 13:49:37 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "structs.h"
# include "../libmlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "raycasting.h"

void	render_frame(t_data *data, t_window *window, void *mlx);

/*	DRAWING PARTS OF IMAGE */
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_background(t_image *image, t_element *elements);
void	draw_player(t_data *data, t_image *image, double x, double y);
void	draw_square(t_image *image, int tile_size, int dx, int dy, int color);
void	draw_map(t_data *data, t_image *image);
void	draw_wall(t_data *data, t_element *elements, t_ray *ray, double i);
void	draw_minimap(t_data *data, t_map *map, t_player *player, t_image *image);

void	create_image(t_data *data, t_image **image, int width, int height);
char	*get_data_address(t_image *image);
void	resize_image(t_image *destination, t_image *source);
int		get_pixel_from_source(t_image *dst, t_image *src, int x, int y);
int		get_pixel_colour(t_image *image, int x, int y);

/*	MOVEMENT */
void	keyhooks(t_data *data, t_window *window, void *mlx);
int		movement(t_data *data);
bool	movement_collision(t_data *data, double x, double y);

#endif