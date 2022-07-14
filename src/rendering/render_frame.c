/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:30:13 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	render_frame(t_data *data, t_window *win, void *mlx)
{
	int	ray_i;

	create_image(data, &win->screen, win->width, win->height);
	create_image(data, &win->minimap, 225, 225);
	draw_background(win->screen, data->map->elements);
	ray_i = 0;
	while (ray_i < win->width)
	{
		raycasting(data, 1.0 * ray_i);
		ray_i++;
	}
	draw_minimap(data, data->map, data->player, win->minimap);
	mlx_put_image_to_window(mlx, win->pointer, win->screen->pointer, 0, 0);
	mlx_put_image_to_window(mlx, win->pointer, win->minimap->pointer, 8, 8);
}
