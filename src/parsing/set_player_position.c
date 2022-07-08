/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:02:02 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 17:07:40 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static void	set_parameters(t_data *data, int i, int j, int rotation)
{
	double	tile_size;

	tile_size = data->map->tile_size;
	data->player->i = i;
	data->player->j = j;
	data->player->x = 1.0 * i * tile_size + (0.5 * tile_size);
	data->player->y = 1.0 * j * tile_size + (0.5 * tile_size);
	data->player->rotation = rotation;
}

void	set_player_position(t_data *data, t_map *map, t_tile **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (grid[i][j].id == 'N')
				set_parameters(data, i, j, 270);
			else if (grid[i][j].id == 'E')
				set_parameters(data, i, j, 0);
			else if (grid[i][j].id == 'S')
				set_parameters(data, i, j, 90);
			else if (grid[i][j].id == 'W')
				set_parameters(data, i, j, 180);
			j++;
		}
		i++;
	}
}
