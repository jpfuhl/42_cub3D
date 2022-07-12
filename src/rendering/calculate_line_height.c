/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:45:44 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 16:09:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	calculate_line_height(t_data *data, t_window *window, t_ray *ray)
{
	int	line_height;

	// line_height = (int)(window->height * data->tile_size / ray->perpWallDist);
	line_height = (int)(window->height * data->map->tile_size / ray->perp_wall_distance);
	line_height = abs(line_height);
	ray->line_step = 1.0 * TEXTURE_SIZE / line_height;
	ray->line_height_start = 0;

	if (line_height > window->height)
	{
		ray->line_height_start = (1.0 * TEXTURE_SIZE / 2.0) - ((1.0 * TEXTURE_SIZE / 2.0 ) / ((1.0 * line_height) / (1.0 * window->height)));
		line_height = window->height; // andere start/end faktor
	}
	ray->draw_start = -line_height / 2 + window->height / 2;
	ray->draw_end = line_height / 2 + window->height / 2;
	ray->line_height = line_height;
}
