/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:36:31 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 18:37:00 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

static bool	move_outoftile_horizontal(t_data *data, t_ray *ray, t_xy *inter)
{
	if (ray->dir.x != 0)
	{
		*inter = first_int_x(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
		while (fabs(ray->sidedistx + (ray->deltax * data->map->tile_size))
			< fabs(ray->sidedisty))
		{
			*inter = intersection_x(data, ray);
			if (check_wall_collision(data, ray, ray->dir, *inter) == true)
				return (true);
		}
	}
	if (ray->dir.y != 0)
	{
		*inter = first_int_y(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
	}
	return (false);
}

static bool	move_outoftile_vertical(t_data *data, t_ray *ray, t_xy *inter)
{
	if (ray->dir.y != 0)
	{
		*inter = first_int_y(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
		while (fabs(ray->sidedisty + (ray->deltay * data->map->tile_size))
			< fabs(ray->sidedistx))
		{
			*inter = intersection_y(data, ray);
			if (check_wall_collision(data, ray, ray->dir, *inter) == true)
				return (true);
		}
	}
	if (ray->dir.x != 0)
	{
		*inter = first_int_x(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
	}
	return (false);
}

static bool	move_horizontal(t_data *data, t_ray *ray, t_xy *inter)
{
	if (ray->dir.x != 0)
	{
		*inter = intersection_x(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
	}
	return (false);
}

static bool	move_vertical(t_data *data, t_ray *ray, t_xy *inter)
{
	if (ray->dir.y != 0)
	{
		*inter = intersection_y(data, ray);
		if (check_wall_collision(data, ray, ray->dir, *inter) == true)
			return (true);
	}
	return (false);
}

void	find_collision(t_data *data, t_ray *ray, t_xy *inter)
{
	if (fabs(ray->sidedistx) < fabs(ray->sidedisty))
	{
		if (move_outoftile_horizontal(data, ray, inter) == true)
			return ;
	}
	else
	{
		if (move_outoftile_vertical(data, ray, inter) == true)
			return ;
	}
	while (1)
	{
		if ((fabs(ray->sidedistx + (ray->deltax * data->map->tile_size))
				< fabs(ray->sidedisty + (ray->deltay * data->map->tile_size))
				|| ray->dir.y == 0) && ray->dir.x != 0)
		{
			if (move_horizontal(data, ray, inter) == true)
				break ;
		}
		else
		{
			if (move_vertical(data, ray, inter) == true)
				break ;
		}
	}
}
