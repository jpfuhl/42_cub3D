/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:54:55 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/13 10:57:34 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

bool	west_wall(t_data *data, t_ray *ray, int i, int j)
{
	t_tile	**grid;

	grid = data->map->grid;
	if (grid[i - 1][j].wall)
	{
		ray->colour = WEST;
		grid[i - 1][j].vision = true;
		// disco_wall(data, i - 1, j);
		return (true);
	}
	return (false);
}

bool	east_wall(t_data *data, t_ray *ray, int i, int j)
{
	t_tile	**grid;

	grid = data->map->grid;
	if (grid[i][j].wall)
	{
		ray->colour = EAST;
		grid[i][j].vision = true;
		// disco_wall(data, i, j);
		return (true);
	}
	return (false);
}

bool	south_wall(t_data *data, t_ray *ray, int i, int j)
{
	t_tile	**grid;

	grid = data->map->grid;
	if (grid[i][j].wall)
	{
		ray->colour = SOUTH;
		grid[i][j].vision = true;
		// disco_wall(data, i, j);
		return (true);
	}
	return (false);
}

bool	north_wall(t_data *data, t_ray *ray, int i, int j)
{
	t_tile	**grid;

	grid = data->map->grid;
	if (grid[i][j - 1].wall)
	{
		ray->colour = NORTH;
		grid[i][j - 1].vision = true;
		// disco_wall(data, i, j - 1);
		return (true);
	}
	return (false);
}

bool	northwest(t_data *data, t_ray *ray, int i, int j)
{
	t_tile	**grid;

	grid = data->map->grid;
	if (grid[i - 1][j - 1].wall)
	{
		ray->colour = NORTH;
		grid[i - 1][j - 1].vision = true;
		// disco_wall(data, i - 1, j - 1);
		return (true);
	}
	return (false);
}