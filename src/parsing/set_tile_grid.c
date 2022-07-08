/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:54:19 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 17:15:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	set_tile_grid(t_map *map, char **cub_file, int pos)
{
	int	j;
	int	i;
	int	len;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		len = ft_strlen(cub_file[j + pos]);
		while (i < len)
		{
			map->grid[i][j].id = cub_file[j + pos][i];
			map->grid[i][j].i = i;
			map->grid[i][j].j = j;
			map->grid[i][j].x_o = 1.0 * i * map->tile_size;
			map->grid[i][j].x = 1.0 * i * map->tile_size + map->tile_size;
			map->grid[i][j].y_o = 1.0 * j * map->tile_size;
			map->grid[i][j].y = 1.0 * j * map->tile_size + map->tile_size;
			if (map->grid[i][j].id == '1')
				map->grid[i][j].wall = true;
			i++;
		}
		j++;
	}
}
