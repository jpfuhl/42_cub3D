/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:23:17 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 13:00:08 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

t_xy	first_int_x(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	if (ray->dir.x > 0)
		ray->c_mapx++;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].x_o - (int)data->player->x;
	b = (int)sqrt(fabs(pow(ray->sidedistx, 2) - powf(a, 2)));
	inter.x = ray->c_mapx * (int)data->map->tile_size;
	inter.y = (int)data->player->y + b * ray->stepy;
	ray->axis = 0;
	return (inter);
}

t_xy	first_int_y(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	if (ray->dir.y > 0)
		ray->c_mapy++;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].y_o - (int)data->player->y;
	b = (int)sqrt(fabs(pow(ray->sidedisty, 2) - powf(a, 2)));
	inter.x = (int)data->player->x + b * ray->stepx;
	inter.y = ray->c_mapy * (int)data->map->tile_size;
	ray->axis = 1;
	return (inter);
}

t_xy	intersection_x(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	ray->c_mapx += ray->stepx;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].x_o - (int)data->player->x;
	ray->sidedistx += (ray->deltax * (int)data->map->tile_size);
	b = (int)sqrt(fabs(pow(ray->sidedistx, 2) - pow(a, 2)));
	inter.x = ray->c_mapx * (int)data->map->tile_size;
	inter.y = (int)data->player->y + b * ray->stepy;
	ray->axis = 0;
	return (inter);
}

t_xy	intersection_y(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	ray->c_mapy += ray->stepy;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].y_o - (int)data->player->y;
	ray->sidedisty += (ray->deltay * (int)data->map->tile_size);
	b = (int)sqrt(fabs(pow(ray->sidedisty, 2) - pow(a, 2)));
	inter.x = (int)data->player->x + b * ray->stepx;
	inter.y = ray->c_mapy * (int)data->map->tile_size;
	ray->axis = 1;
	return (inter);
}
