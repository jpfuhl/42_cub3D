/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:13:03 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 11:25:35 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

bool	check_wall_collision(t_data *data, t_ray *ray, t_xy vector, t_xy inter)
{
	bool	collision;
	int		fac;

	collision = false;
	fac = (int)data->map->tile_size;
	if ((int)inter.x < 0)
		inter.x *= -1;
	if ((int)inter.y < 0)
		inter.y *= -1;
	if (ray->axis == 1 && ray->dir.y > 0 && (int)inter.x % fac != 0)
		collision = south_wall(data, ray, inter.x / fac, inter.y / fac);
	else if (ray->axis == 1 && ray->dir.y <= 0 && (int)inter.x % fac != 0)
		collision = north_wall(data, ray, inter.x / fac, inter.y / fac);
	else if (ray->axis == 0 && ray->dir.x > 0 && (int)inter.y % fac != 0)
		collision = east_wall(data, ray, inter.x / fac, inter.y / fac);
	else if (ray->axis == 0 && ray->dir.x <= 0 && (int)inter.y % fac != 0)
		collision = west_wall(data, ray, inter.x / fac, inter.y / fac);
	else
		collision = check_borders(data, ray, vector, inter);
	return (collision);
}

bool	check_borders(t_data *data, t_ray *ray, t_xy vector, t_xy inter)
{
	bool	collision;

	if (ray->dir.x <= 0)
		collision = left_border(data, ray, vector, inter);
	else
		collision = right_border(data, ray, vector, inter);
	return (collision);
}	

bool	left_border(t_data *data, t_ray *ray, t_xy vector, t_xy inter)
{
	bool	collision;
	int		fac;

	collision = false;
	fac = (int)data->map->tile_size;
	if (ray->dir.y > 0 && (int)inter.x % fac == 0 && (int)inter.y % fac == 0)
	{
		collision = south_wall(data, ray, inter.x / fac, inter.y / fac);
		if (collision == false)
			collision = west_wall(data, ray, inter.x / fac, inter.y / fac);
		if (ray->axis == 1)
			ray->colour = SOUTH;
	}
	else if (ray->dir.y <= 0 && (int)inter.x % fac == 0
		&& (int)inter.y % fac == 0)
	{
		collision = northwest(data, ray, inter.x / fac, inter.y / fac);
		if (ray->axis == 0)
			ray->colour = WEST;
	}
	return (collision);
}

bool	right_border(t_data *data, t_ray *ray, t_xy vector, t_xy inter)
{
	bool	collision;
	int		fac;

	collision = false;
	fac = (int)data->map->tile_size;
	if (ray->dir.y > 0 && (int)inter.x % fac == 0 && (int)inter.y % fac == 0)
	{
		collision = south_wall(data, ray, inter.x / fac, inter.y / fac);
		if (collision == false)
			collision = east_wall(data, ray, inter.x / fac, inter.y / fac);
		if (ray->axis == 0)
			ray->colour = EAST;
	}
	else if (ray->dir.y <= 0 && (int)inter.x % (int)fac == 0
		&& (int)inter.y % (int)fac == 0)
	{
		collision = north_wall(data, ray, inter.x / fac, inter.y / fac);
		if (collision == false)
			collision = east_wall(data, ray, inter.x / fac, inter.y / fac);
		if (ray->axis == 0)
			ray->colour = EAST;
	}
	return (collision);
}
