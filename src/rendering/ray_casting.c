/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:03:22 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/12 13:53:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	raycasting(t_data *data, double factor)
{
	t_ray	*ray;
	t_xy	plane;
	double	cameraX;
	t_xy	non_vector;
	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		return (MALLOC_ERROR);
		
	ray->vector.x = cos((data->player->rotation) * PI / 180);
	ray->vector.y = -sin((data->player->rotation) * PI / 180);
	plane.x = (.66) * (-1) * ray->vector.y;
	plane.y = (.66) * ray->vector.x;
	//cameraX
	//cameraX = 2 * factor / data->window->screen->width - 1; //if we want a minimap the 3d picture width should be smaller than the window
	cameraX = factor / (double)(data->window->width / 2) - 1; // the /2 is bc i took the size of the map
	non_vector.x = ray->vector.x + plane.x * cameraX;
	non_vector.y = ray->vector.y + plane.y * cameraX;
	//cambiar esto a rayDir 
	ray->vector.x = (non_vector.x) / (sqrtf(powf(non_vector.x, 2) + powf(non_vector.y, 2)));
	ray->vector.y = (non_vector.y) / (sqrtf(powf(non_vector.x, 2) + powf(non_vector.y, 2)));
	ray->c_mapx = (int)data->player->x / (int)data->map->tile_size;
	ray->c_mapy = (int)data->player->y / (int)data->map->tile_size;

	/*printf("\n***********************SOME DATA*************************\n");
	printf("tile_size: %d\n", (int)data->map->tile_size);
	printf("(int)data->player->x: %d, (int)data->player->y: %d\n", (int)data->player->x, (int)data->player->y);
	printf("rotation: %d\n", data->player->rotation);*/
	//printf("vector Raydir >>> ray->vector.x : %f, ray->vector.y: %f \n", ray->vector.x, ray->vector.y);

	deltaDist(ray);
	sideDist(data, ray);

	/*printf("(int)data->player->x : %d, (int)data->player->y : %d\n", (int)data->player->x, (int)data->player->y);
	printf("ray->deltaDistX: %f, ray->deltaDistY : %f\n", ray->deltaDistX, ray->deltaDistY);
	printf("ray->sideDistX: %f, ray->sideDistY : %f\n", ray->sideDistX, ray->sideDistY);
	printf("ray->stepX: %d, ray->stepY: %d\n", ray->stepX, ray->stepY);*/
	
	t_xy	inter;
	double	distance;

	inter = find_coalition(data, ray);
	distance = sqrt(pow(inter.x - data->player->x, 2) + pow(inter.y - data->player->y, 2));
	//printf("%f Find coalition point in x: %f, y: %f, distance: %f", factor, inter.x, inter.y, distance);
	dda_algorithm_punk(data, data->player->x, data->player->y, inter);

	/* NEW */
	ray->intersection = inter;
	calculate_perp_wall_distance(data->player, ray);
	calculate_line_position(ray, inter, data->map->tile_size); // x
	calculate_line_height(data, data->window, ray); // y
	
	draw_wall_line(data, data->map->elements, ray, factor);
	// draw_wall(data, factor, ray);
	return (0);
}

/*int	some_maths(t_data *data, double factor)
{

	double	perpWallDist;
	if (ray->axis == 0)
	{
		perpWallDist = ray->sideDistX;
	}
	else if (ray->axis == 1)
	{
		perpWallDist = ray->sideDistY;
	}
	float ca = (data->player->rotation * PI / 180) - atan(-ray->vector.y / ray->vector.x);
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	perpWallDist *= cos(ca);
	int	lineHeight = (int)(W_HEIGHT * (int)(int)data->map->tile_size * 2 / perpWallDist);
	//fprintf(stderr, "HEIGHT: %d\n", lineHeight);
	int colour;
	if (ray->colour == NORTH_TEXTURE)
	{
		colour = 0x0047AB;
		// if (ray->axis == 1)
		// 	colour /= 2;
	}
	else if (ray->colour == SOUTH_TEXTURE)
	{
		colour = 0xFAFA33;
		// if (ray->axis == 1)
		// 	colour /= 2;
	}
	else if (ray->colour == WEST_TEXTURE)
	{
		colour = 0x228B22;
		// if (ray->axis == 1)
		// 	colour /= 2;
	}
	else if (ray->colour == EAST_TEXTURE)
	{
		colour = 0xD22B2B;
		// if (ray->axis == 1)
		// 	colour /= 2;
	}
	else if (ray->colour == DEFAULT)
	{
		colour = 0xFFFFFF;
		// if (ray->axis == 1)
		// 	colour /= 2;
	}
	draw_wall(info->data, info, factor, abs(lineHeight), colour, inter, ray->axis);
	return (0);
}
*/
t_xy	find_coalition(t_data *data, t_ray *ray)
{
	t_xy	inter;

	if (fabs(ray->sideDistX) < fabs(ray->sideDistY))
	{
		if (ray->vector.x != 0)
		{
			inter = first_int_X(data, ray);
			my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
			if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
				return (inter);
			while (fabs(ray->sideDistX + (ray->deltaDistX * (int)data->map->tile_size)) < fabs(ray->sideDistY))
			{
				inter = intersection_X(data, ray);
				my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
					return (inter);
			}
		}
		if (ray->vector.y != 0)
		{
			inter = first_int_Y(data, ray);
			my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
			if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
				return (inter);
		}

	}
	else
	{
		if (ray->vector.y != 0)
		{
			inter = first_int_Y(data, ray);
			my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
			if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
				return (inter);
			while (fabs(ray->sideDistY + (ray->deltaDistY * (int)data->map->tile_size)) < fabs(ray->sideDistX))
			{
				inter = intersection_Y(data, ray);
				my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
					return (inter);
			}
		}
		if (ray->vector.x != 0)
		{
			inter = first_int_X(data, ray);
			my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
			if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
				return (inter);
		}

	}
	while (1)
	{
		if ((fabs(ray->sideDistX + (ray->deltaDistX * (int)data->map->tile_size))
			< fabs(ray->sideDistY + (ray->deltaDistY * (int)data->map->tile_size))
			|| ray->vector.y == 0) && ray->vector.x != 0)
		{
			if (ray->vector.x != 0)
			{
				inter = intersection_X(data, ray);
				my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x0000FF00);
				if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
					break;
			}
		}
		else
		{
			if (ray->vector.y != 0)
			{
				inter = intersection_Y(data, ray);
				my_mlx_pixel_put(data->window->screen, inter.x, inter.y, 0x00FF00FF);
				if (check_wall_collision(data, ray, ray->vector, inter.x, inter.y) == true)
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
	//a = data->map->grid[ray->c_mapx][ray->c_mapy].x_o - (int)data->player->x;
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