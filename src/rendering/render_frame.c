/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 17:33:03 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	render_frame(t_data *data, t_window *window, void *mlx)
{
	double	map_width;
	double	map_height;

	static int count = 0;
	fprintf(stderr, "%d\n", count);
	count++;
	map_width = data->map->width * data->map->tile_size;
	map_height = data->map->height * data->map->tile_size;
	create_image(data, &window->screen, data->window->width, data->window->height);
	create_image(data, &window->map, 225, 225);
	draw_minimap_new(data, window->map);
	if (data->buttons->minimap)
	{
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
	mlx_put_image_to_window(mlx, window->pointer, window->map->pointer, 8, 8);
	if (data->buttons->minimap)
	{
		resize_image(data->window->minimap, data->window->map);
		mlx_put_image_to_window(mlx, window->pointer, window->minimap->pointer, 8, 8);
	}
}
