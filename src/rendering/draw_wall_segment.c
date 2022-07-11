/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 19:25:56 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"
#include "../../inc/raycasting.h"

void	draw_wall_segment(t_data *data, t_map *map, t_ray *ray, float i)
{
	// it segfaults and i dont know why yet
	int		j;
	float	x;
	float	y;
	int		pixel;

	j = ray->drawStart;
	x = ray->x_segment;
	y = 0.0;
	while (j < ray->drawEnd)
	{
		if (ray->wall == NORTH)
			pixel = get_pixel_colour(map->elements[NORTH].texture, (int)x, (int)y);
		else if (ray->wall == SOUTH)
			pixel = get_pixel_colour(map->elements[SOUTH].texture, (int)x, (int)y);
		else if (ray->wall == WEST)
			pixel = get_pixel_colour(map->elements[WEST].texture, (int)x, (int)y);
		else if (ray->wall == EAST)
			pixel = get_pixel_colour(map->elements[EAST].texture, (int)x, (int)y);
		draw_pixel(data->window->screen, i, j, pixel);
		y += ray->line_step;
		j++;
	}
}
