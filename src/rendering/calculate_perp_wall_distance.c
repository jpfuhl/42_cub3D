/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_wall_distance.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 10:41:50 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	calculate_perp_wall_distance(t_player *player, t_ray *ray)
{
	float	angle;

	angle = (player->rotation * PI / 180) - atan(-ray->vector.y / ray->vector.x);
	if (angle < 0)
		angle += 2 * PI;
	else if (angle > 2 * PI)
		angle -= 2 * PI;
	
	if (ray->axis == 0)
		ray->perp_wall_distance = ray->sideDistX * cos(angle);
	else if (ray->axis == 1)
		ray->perp_wall_distance = ray->sideDistY * cos(angle);
}
