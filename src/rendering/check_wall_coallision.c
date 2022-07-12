/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_coallision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:13:03 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/11 21:21:42 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"
/*
SOUTH-YELLOW
EAST-RED------------ 
WEST - GREEN ------- 
NORTh-BLUE
*/

static void	disco_wall(t_data *data, int dx, int dy)
{
	static	int	i = 0;
	int		colour;

	colour = -1;
	// if (i % 500 == 0 && i % 300 == 0)
	// 	colour = 0x00babc;
	// else if (i % 500 == 0)
	// 	colour = 0xd101c0;
	if (i % 300 == 0 && i % 500 == 0)
		colour = 0xf1c937;
	else
		colour = -1;
	i++;
	if (i == 300000)
		i = 0;
	if (colour != -1)
		draw_square(data->window->screen, data->map->tile_size, dx, dy, colour);
}

static bool	check_west_wall(t_data *data, t_tile **grid, t_ray *ray, int i, int j)
{
	if (grid[i - 1][j].wall)
	{
		ray->colour = WEST;
		disco_wall(data, i - 1, j);
		return (true);
	}
	return (false);
}

static bool	check_east_wall(t_data *data, t_tile **grid, t_ray *ray, int i, int j)
{
	if (grid[i][j].wall)
	{
		ray->colour = EAST;
		disco_wall(data, i, j);
		return (true);
	}
	return (false);
}

static bool	check_south_wall(t_data *data, t_tile **grid, t_ray *ray, int i, int j)
{
	if (grid[i][j].wall)
	{
		ray->colour = SOUTH;
		disco_wall(data, i, j);
		return (true);
	}
	return (false);
}

static bool	check_north_wall(t_data *data, t_tile **grid, t_ray *ray, int i, int j)
{
	if (grid[i][j - 1].wall)
	{
		ray->colour = NORTH;
		disco_wall(data, i, j - 1);
		return (true);
	}
	return (false);
}

static bool	check_northwest(t_data *data, t_tile **grid, t_ray *ray, int i, int j)
{
	if (grid[i - 1][j - 1].wall)
	{
		ray->colour = NORTH;
		disco_wall(data, i - 1, j - 1);
		return (true);
	}
	return (false);
}

bool	check_wall_collision(t_data *data, t_ray *ray, t_xy vector, int x, int y)
{
	bool	wall_collision;
	int		factor;

	wall_collision = false;
	factor = (int)data->map->tile_size;
	//printf("factor %d\n", factor);
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (ray->axis == 1 && ray->vector.y > 0 && x % factor != 0)
		wall_collision = check_south_wall(data, data->map->grid, ray, x / factor, y / factor);
	else if (ray->axis == 1 && ray->vector.y <= 0 && x % factor != 0)
		wall_collision = check_north_wall(data, data->map->grid, ray, x / factor, y / factor);
	else if (ray->axis == 0 && ray->vector.x > 0 && y % factor != 0)
		wall_collision = check_east_wall(data, data->map->grid, ray, x / factor, y / factor);
	else if (ray->axis == 0 && ray->vector.x <= 0 && y % factor != 0)
		wall_collision = check_west_wall(data, data->map->grid, ray, x / factor, y / factor);
	else if (ray->vector.x <= 0 && ray->vector.y > 0 && x % factor == 0 && y % factor == 0)
	{
		wall_collision = check_south_wall(data, data->map->grid, ray, x / factor, y / factor);
		if (wall_collision == false)
			wall_collision = check_west_wall(data, data->map->grid, ray, x / factor, y / factor);
		if (ray->axis == 1)
			ray->colour = SOUTH;
	}
	else if (ray->vector.x <= 0 && ray->vector.y <= 0 && x % factor == 0 && y % factor == 0)
	{
		wall_collision = check_northwest(data, data->map->grid, ray, x / factor, y / factor);
		if (ray->axis == 0)
			ray->colour = WEST;
	}
	else if (ray->vector.x > 0 && ray->vector.y > 0 && x % factor == 0 && y % factor == 0)
	{
		wall_collision = check_south_wall(data, data->map->grid, ray, x / factor, y / factor);
		if (wall_collision == false)
			wall_collision = check_east_wall(data, data->map->grid, ray, x / factor, y / factor);
		if (ray->axis == 0)
			ray->colour = EAST;
	}
	else if (ray->vector.x > 0 && ray->vector.y <= 0 && x % (int)factor == 0 && y % (int)factor == 0)
	{
		wall_collision = check_north_wall(data, data->map->grid, ray, x / factor, y / factor);
		if (wall_collision == false)
			wall_collision = check_east_wall(data, data->map->grid, ray, x / factor, y / factor);;
		if (ray->axis == 0)
			ray->colour = EAST;
	}
	return (wall_collision);
}