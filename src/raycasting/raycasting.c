/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:03:22 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 13:57:14 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	raycasting(t_data *data, double factor)
{
	t_ray	*ray;
	t_xy	inter;
	double	distance;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		exit_with_error(MALLOC_ERROR);
	calculate_plane_vector(data, ray, factor);
	deltadist(ray);
	sidedist(data, ray);
	inter = find_collision(data, ray);
	distance = sqrt(pow(inter.x - data->player->x, 2) + pow(inter.y - data->player->y, 2));
	// if (data->map->tile_size > 4)
	// 	dda_algorithm_punk(data, data->player->x, data->player->y, inter);
	ray->intersection = inter;
	calculate_perp_wall_distance(data->player, ray);
	calculate_line_position(ray, inter, data->map->tile_size);
	calculate_line_height(data, data->window, ray);
	draw_wall(data, data->map->elements, ray, factor);
}

void	calculate_plane_vector(t_data *data, t_ray *ray, double factor)
{
	t_xy	plane;
	double	camerax;

	ray->vector.x = cos((data->player->rotation) * PI / 180);
	ray->vector.y = -sin((data->player->rotation) * PI / 180);
	plane.x = (.66) * (-1) * ray->vector.y;
	plane.y = (.66) * ray->vector.x;
	camerax = factor / (double)(data->window->width / 2) - 1;
	ray->vector.x = ray->vector.x + plane.x * camerax;
	ray->vector.y = ray->vector.y + plane.y * camerax;
	ray->dir.x = (ray->vector.x) / (sqrtf(powf(ray->vector.x, 2)
				+ powf(ray->vector.y, 2)));
	ray->dir.y = (ray->vector.y) / (sqrtf(powf(ray->vector.x, 2)
				+ powf(ray->vector.y, 2)));
	ray->c_mapx = (int)data->player->x / (int)data->map->tile_size;
	ray->c_mapy = (int)data->player->y / (int)data->map->tile_size;
}

t_xy	find_collision(t_data *data, t_ray *ray)
{
	t_xy	inter;

	if (fabs(ray->sidedistx) < fabs(ray->sidedisty))
	{
		if (ray->dir.x != 0)
		{
			inter = first_int_x(data, ray);
			if (check_wall_collision(data, ray, ray->dir, inter) == true)
				return (inter);
			while (fabs(ray->sidedistx + (ray->deltax * data->map->tile_size)) < fabs(ray->sidedisty))
			{
				inter = intersection_x(data, ray);
				if (check_wall_collision(data, ray, ray->dir, inter) == true)
					return (inter);
			}
		}
		if (ray->dir.y != 0)
		{
			inter = first_int_y(data, ray);
			if (check_wall_collision(data, ray, ray->dir, inter) == true)
				return (inter);
		}

	}
	else
	{
		if (ray->dir.y != 0)
		{
			inter = first_int_y(data, ray);
			if (check_wall_collision(data, ray, ray->dir, inter) == true)
				return (inter);
			while (fabs(ray->sidedisty + (ray->deltay * data->map->tile_size)) < fabs(ray->sidedistx))
			{
				inter = intersection_y(data, ray);
				if (check_wall_collision(data, ray, ray->dir, inter) == true)
					return (inter);
			}
		}
		if (ray->dir.x != 0)
		{
			inter = first_int_x(data, ray);
			if (check_wall_collision(data, ray, ray->dir, inter) == true)
				return (inter);
		}

	}
	while (1)
	{
		if ((fabs(ray->sidedistx + (ray->deltax * data->map->tile_size))
				< fabs(ray->sidedisty + (ray->deltay * data->map->tile_size))
				|| ray->dir.y == 0) && ray->dir.x != 0)
		{
			if (ray->dir.x != 0)
			{
				inter = intersection_x(data, ray);
				if (check_wall_collision(data, ray, ray->dir, inter) == true)
					break ;
			}
		}
		else
		{
			if (ray->dir.y != 0)
			{
				inter = intersection_y(data, ray);
				if (check_wall_collision(data, ray, ray->dir, inter) == true)
					break ;
			}
		}
	}
	return (inter);
}

void	deltadist(t_ray *ray)
{
	if (ray->dir.x == 0)
			ray->deltax = 1;
	else
		ray->deltax = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
			ray->deltay = 1;
	else
		ray->deltay = fabs(1 / ray->dir.y);
}

void	sidedist(t_data *data, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = ((int)data->player->x - ray->c_mapx
				* (int)data->map->tile_size) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((ray->c_mapx + 1) * (int)data->map->tile_size
				- (int)data->player->x) * ray->deltax;
	}
	if (ray->dir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = ((int)data->player->y - ray->c_mapy
				* (int)data->map->tile_size) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((ray->c_mapy + 1) * (int)data->map->tile_size
				- (int)data->player->y) * ray->deltay;
	}
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
