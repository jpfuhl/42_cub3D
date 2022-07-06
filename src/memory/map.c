/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:22:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/06 19:50:10 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/memory.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(map->elements[i].path);
		i++;
	}
	free(map->elements);
	// i = 0;
	// while (map->grid[i])
	// {
	// 	free(map->grid[i]);
	// 	i++;
	// }
	free(map->grid);
	free(map);
}

void	default_initialize_map(t_map *map)
{
	int	i;

	map->file_name = NULL;
	map->cub = NULL;
	i = 0;
	while (i < 6)
	{
		map->elements[i].set = false;
		map->elements[i].path = NULL;
		map->elements[i].texture = NULL;
		map->elements[i].r = 0;
		map->elements[i].g = 0;
		map->elements[i].b = 0;
		map->elements[i].colour = 0;
		i++;
	}
	map->width = 0;
	map->height = 0;
	map->tile_size = 0.0;
	map->grid = NULL;
}

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_with_error(MALLOC_ERROR);
	map->elements = malloc(6 * sizeof(t_element));
	if (!map->elements)
		exit_with_error(MALLOC_ERROR);
	return (map);
}
