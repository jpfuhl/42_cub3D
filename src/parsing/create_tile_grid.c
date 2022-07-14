/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tile_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:42:01 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 16:54:32 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	default_initialize_tile(t_tile *tile)
{
	tile->id = ' ';
	tile->i = 0;
	tile->j = 0;
	tile->x_o = 0.0;
	tile->x = 0.0;
	tile->y_o = 0.0;
	tile->y = 0.0;
	tile->wall = false;
	tile->vision = false;
}

t_tile	**create_tile_grid(t_map *map)
{
	t_tile	**grid;
	int		i;
	int		j;

	grid = malloc((map->width + 1) * sizeof(t_tile *));
	if (!grid)
		exit_with_error(MALLOC_ERROR);
	i = 0;
	while (i < map->width)
	{
		grid[i] = malloc((map->height) * sizeof(t_tile));
		if (!grid[i])
			exit_with_error(MALLOC_ERROR);
		j = 0;
		while (j < map->height)
		{
			default_initialize_tile(&grid[i][j]);
			j++;
		}
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
