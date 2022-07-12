/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:45:44 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 13:57:08 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	calculate_line_height(t_data *data, t_window *window, t_ray *ray)
{
	int	line_height;

	// line_height = (int)(window->height * data->tile_size / ray->perpWallDist);
	line_height = (int)(data->map->tile_size * window->height / ray->perp_wall_distance);
	line_height = abs(line_height);

	if (line_height > window->height)
	{
		line_height = window->height; // andere start/end faktor
		ray->line_height_start = (1.0 * TEXTURE_SIZE / 2.0) - ((1.0 * TEXTURE_SIZE / 2.0 ) / ((1.0 * line_height) / (1.0 * window->height)));
		ray->draw_start = 0;
		ray->draw_end = window->height;
	}
	else
	{
		ray->line_height_start = 0;
		ray->draw_start = -line_height / 2 + window->height / 2;
		ray->draw_end = line_height / 2 + window->height / 2;
	}
	ray->line_step = 1.0 * TEXTURE_SIZE / line_height;
	ray->line_height = line_height;
}
