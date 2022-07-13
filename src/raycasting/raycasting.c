/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:03:22 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 11:22:29 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/raycasting.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	raycasting(t_data *data, double factor)
{
	t_ray	*ray;
	t_xy	plane;
	double	camerax;
	t_xy	non_vector;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		exit_with_error(MALLOC_ERROR);
	ray->vector.x = cos((data->player->rotation) * PI / 180);
	ray->vector.y = -sin((data->player->rotation) * PI / 180);
	plane.x = (.66) * (-1) * ray->vector.y;
	plane.y = (.66) * ray->vector.x;
	camerax = factor / (double)(data->window->width / 2) - 1; // the /2 is bc i took the size of the map
	non_vector.x = ray->vector.x + plane.x * camerax;
	non_vector.y = ray->vector.y + plane.y * camerax;
	//cambiar esto a rayDir 
	ray->vector.x = (non_vector.x) / (sqrtf(powf(non_vector.x, 2) + powf(non_vector.y, 2)));
	ray->vector.y = (non_vector.y) / (sqrtf(powf(non_vector.x, 2) + powf(non_vector.y, 2)));
	ray->c_mapx = (int)data->player->x / (int)data->map->tile_size;
	ray->c_mapy = (int)data->player->y / (int)data->map->tile_size;
	deltaDist(ray);
	sideDist(data, ray);

	t_xy	inter;
	double	distance;

	inter = find_collision(data, ray);
	distance = sqrt(pow(inter.x - data->player->x, 2) + pow(inter.y - data->player->y, 2));
	//printf("%f Find coalition point in x: %f, y: %f, distance: %f", factor, inter.x, inter.y, distance);
	// if (data->map->tile_size > 4)
	// 	dda_algorithm_punk(data, data->player->x, data->player->y, inter);

	/* NEW */
	ray->intersection = inter;
	calculate_perp_wall_distance(data->player, ray);
	calculate_line_position(ray, inter, data->map->tile_size); // x
	calculate_line_height(data, data->window, ray); // y
	
	draw_wall(data, data->map->elements, ray, factor);
}

t_xy	find_collision(t_data *data, t_ray *ray)
{
	t_xy	inter;

	if (fabs(ray->sideDistX) < fabs(ray->sideDistY))
	{
		if (ray->vector.x != 0)
		{
			inter = first_int_X(data, ray);
			// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
			if (check_wall_collision(data, ray, ray->vector, inter) == true)
				return (inter);
			while (fabs(ray->sideDistX + (ray->deltaDistX * data->map->tile_size)) < fabs(ray->sideDistY))
			{
				inter = intersection_X(data, ray);
				// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter) == true)
					return (inter);
			}
		}
		if (ray->vector.y != 0)
		{
			inter = first_int_Y(data, ray);
			// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
			if (check_wall_collision(data, ray, ray->vector, inter) == true)
				return (inter);
		}

	}
	else
	{
		if (ray->vector.y != 0)
		{
			inter = first_int_Y(data, ray);
			// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
			if (check_wall_collision(data, ray, ray->vector, inter) == true)
				return (inter);
			while (fabs(ray->sideDistY + (ray->deltaDistY * data->map->tile_size)) < fabs(ray->sideDistX))
			{
				inter = intersection_Y(data, ray);
				// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter) == true)
					return (inter);
			}
		}
		if (ray->vector.x != 0)
		{
			inter = first_int_X(data, ray);
			// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
			if (check_wall_collision(data, ray, ray->vector, inter) == true)
				return (inter);
		}

	}
	while (1)
	{
		if ((fabs(ray->sideDistX + (ray->deltaDistX * data->map->tile_size))
			< fabs(ray->sideDistY + (ray->deltaDistY * data->map->tile_size))
			|| ray->vector.y == 0) && ray->vector.x != 0)
		{
			if (ray->vector.x != 0)
			{
				inter = intersection_X(data, ray);
				// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter) == true)
					break;
			}
		}
		else
		{
			if (ray->vector.y != 0)
			{
				inter = intersection_Y(data, ray);
				// my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
				if (check_wall_collision(data, ray, ray->vector, inter) == true)
					break;
			}
		}
	}
	return (inter);
}

void	deltaDist(t_ray *ray)
{
	if (ray->vector.x == 0)
			ray->deltaDistX = 1;
	else
		ray->deltaDistX = fabs(1 / ray->vector.x);
	if (ray->vector.y == 0)
			ray->deltaDistY = 1;
	else
		ray->deltaDistY = fabs(1 / ray->vector.y);
}

void	sideDist(t_data *data, t_ray *ray)
{
	if (ray->vector.x < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = ((int)data->player->x - ray->c_mapx * (int)data->map->tile_size) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = ((ray->c_mapx + 1) * (int)data->map->tile_size - (int)data->player->x) * ray->deltaDistX;
	}
	if (ray->vector.y < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = ((int)data->player->y - ray->c_mapy * (int)data->map->tile_size) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = ((ray->c_mapy + 1) * (int)data->map->tile_size - (int)data->player->y) * ray->deltaDistY;
	}
}

t_xy	first_int_X(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	if (ray->vector.x > 0)
		ray->c_mapx++;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].x_o - (int)data->player->x;
	b = (int)sqrt(fabs(pow(ray->sideDistX, 2) - powf(a, 2)));
	inter.x = ray->c_mapx * (int)data->map->tile_size;
	inter.y = (int)data->player->y + b * ray->stepY;
	ray->axis = 0;
	return (inter);
}

t_xy	first_int_Y(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	if (ray->vector.y > 0)
		ray->c_mapy++;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].y_o - (int)data->player->y;
	b = (int)sqrt(fabs(pow(ray->sideDistY, 2) - powf(a, 2)));
	inter.x = (int)data->player->x + b * ray->stepX;
	inter.y = ray->c_mapy * (int)data->map->tile_size;
	ray->axis = 1;
	return (inter);
}

t_xy	intersection_X(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	ray->c_mapx += ray->stepX;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].x_o - (int)data->player->x;
	ray->sideDistX += (ray->deltaDistX * (int)data->map->tile_size);
	b = (int)sqrt(fabs(pow(ray->sideDistX, 2) - pow(a, 2)));
	inter.x = ray->c_mapx * (int)data->map->tile_size;
	inter.y = (int)data->player->y + b * ray->stepY;
	ray->axis = 0;
	return (inter);
}

t_xy	intersection_Y(t_data *data, t_ray *ray)
{
	int		a;
	int		b;
	t_xy	inter;

	ray->c_mapy += ray->stepY;
	a = data->map->grid[ray->c_mapx][ray->c_mapy].y_o - (int)data->player->y;
	ray->sideDistY += (ray->deltaDistY * (int)data->map->tile_size);
	b = (int)sqrt(fabs(pow(ray->sideDistY, 2) - pow(a, 2)));
	inter.x = (int)data->player->x + b * ray->stepX;
	inter.y = ray->c_mapy * (int)data->map->tile_size;
	ray->axis = 1;
	return (inter);
}
