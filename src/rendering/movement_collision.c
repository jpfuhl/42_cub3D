/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:23 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 15:30:18 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static bool	search_wall_x(t_data *data, int *old_x, int old_y, int new_x)
{
	double	tile;

	tile = data->map->tile_size;
	if ((*old_x) < new_x)
			(*old_x)++;
	else
		(*old_x)--;
	if (check_if_is_wall(data->map->grid, (*old_x) / tile, old_y / tile))
		return (true);
	return (false);
}

static bool	search_wall_y(t_data *data, int old_x_copy, int *old_y, int new_y)
{
	double	tile;

	tile = data->map->tile_size;
	if ((*old_y) < (int)new_y)
		(*old_y)++;
	else
		(*old_y)--;
	if (check_if_is_wall(data->map->grid, old_x_copy / tile, (*old_y) / tile))
		return (true);
	return (false);
}

static bool	going_across(t_data *data, double new_x, double new_y)
{
	int		old_x;
	int		old_y;
	int		old_x_copy;

	old_x = (int)data->player->x;
	old_y = (int)data->player->y;
	old_x_copy = old_x;
	while (old_x != (int)new_x)
	{
		if (search_wall_x(data, &old_x, old_y, (int)new_x) == true)
			return (true);
	}
	while (old_y != (int)new_y)
	{
		if (search_wall_y(data, old_x_copy, &old_y, (int)new_y) == true)
			return (true);
	}
	return (false);
}

static bool	less_than_x_pixels(t_data *data, double new_x, double new_y, int p)
{
	double	tile;
	t_tile	**grid;

	tile = data->map->tile_size;
	grid = data->map->grid;
	if (check_if_is_wall(grid, (new_x + p) / tile, (new_y - p) / tile))
		return (true);
	if (check_if_is_wall(grid, new_x / tile, (new_y - p) / tile))
		return (true);
	if (check_if_is_wall(grid, (new_x - p) / tile, (new_y - p) / tile))
		return (true);
	if (check_if_is_wall(grid, (new_x + p) / tile, new_y / tile))
		return (true);
	if (check_if_is_wall(grid, new_x / tile, new_y / tile))
		return (true);
	if (check_if_is_wall(grid, (new_x - p) / tile, new_y / tile))
		return (true);
	if (check_if_is_wall(grid, (new_x + p) / tile, (new_y + p) / tile))
		return (true);
	if (check_if_is_wall(grid, new_x / tile, (new_y + p) / tile))
		return (true);
	if (check_if_is_wall(grid, (new_x - p) / tile, (new_y + p) / tile))
		return (true);
	return (false);
}

bool	movement_collision(t_data *data, double x, double y)
{
	double	new_x;
	double	new_y;
	int		i;
	int		j;

	new_x = data->player->x + x;
	new_y = data->player->y + y;
	i = new_x / data->map->tile_size;
	j = new_y / data->map->tile_size;
	if (check_if_is_wall(data->map->grid, i, j))
		return (true);
	else if (less_than_x_pixels(data, new_x, new_y, 2))
		return (true);
	else if (going_across(data, new_x, new_y))
		return (true);
	return (false);
}
