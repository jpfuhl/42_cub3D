/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:47:16 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 13:48:11 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	calculate_line_position(t_ray *ray, t_xy intersection, int tile_size)
{
	double	cut;
	double	factor;

	if (ray->axis == 0)
	{
		cut = ray->intersection.y / (1.0 * tile_size);
		factor = cut - (int)cut;
		ray->line_position = TEXTURE_SIZE * factor;
	}
	else if (ray->axis == 1)
	{
		cut = ray->intersection.x / (1.0 * tile_size);
		factor = cut - (int)cut;
		ray->line_position = TEXTURE_SIZE * factor;
	}
}
