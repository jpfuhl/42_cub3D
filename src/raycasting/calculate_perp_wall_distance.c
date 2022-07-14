/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_wall_distance.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 12:09:47 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	calculate_perp_wall_distance(t_player *player, t_ray *ray)
{
	double	angle;

	angle = (player->rotation * PI / 180.0) - atan(-ray->dir.y / ray->dir.x);
	if (angle < 0)
		angle += 2.0 * PI;
	else if (angle > 2 * PI)
		angle -= 2.0 * PI;
	if (ray->axis == 0)
		ray->perp_wall_distance = ray->sidedistx * cos(angle);
	else if (ray->axis == 1)
		ray->perp_wall_distance = ray->sidedisty * cos(angle);
}
