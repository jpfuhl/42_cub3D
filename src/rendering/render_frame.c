/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 13:49:25 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	render_frame(t_data *data, t_window *window, void *mlx)
{
	int	ray_i;

	create_image(data, &window->screen, data->window->width, data->window->height);
	create_image(data, &window->map, 225, 225);
	draw_background(window->screen, data->map->elements);
	ray_i = 0;
	while (ray_i < data->window->width)
	{
		raycasting(data, 1.0 * ray_i);
		ray_i++;
	}
	draw_minimap(data, data->map, data->player, window->map);
	mlx_put_image_to_window(mlx, window->pointer, window->screen->pointer, 0, 0);
	mlx_put_image_to_window(mlx, window->pointer, window->map->pointer, 8, 8);
}
