/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 18:24:43 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	render_frame(t_data *data, t_window *window, void *mlx)
{
	double	map_width;
	double	map_height;

	map_width = data->map->width * data->map->tile_size;
	map_height = data->map->height * data->map->tile_size;
	create_image(data, &window->screen, data->window->width, data->window->height);
	if (data->map->tile_size > 4)
	{
		create_image(data, &window->map, map_width, map_height);
		draw_map(data, window->map);
		draw_player(data, window->map, data->player->x, data->player->y);
		create_image(data, &window->minimap, map_width / 6, map_height / 6);
	}
	draw_background(window->screen, data->map->elements);
	int	factor;

	factor = 0;
	while (factor < data->window->width)
	{
		raycasting(data, 1.0 * factor);
		factor++;
	}
	mlx_put_image_to_window(mlx, window->pointer, window->screen->pointer, 0, 0);
	
	if (data->map->tile_size > 4)
	{
		// mlx_put_image_to_window(mlx, window->pointer, window->map->pointer, 0, 0);
		resize_image(data->window->minimap, data->window->map);
		mlx_put_image_to_window(mlx, window->pointer, window->minimap->pointer, 8, 8);
	}
}
