/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:58:24 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 17:47:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	set_tile_size(t_data *data, t_map *map)
{
	int	factor;

	factor = 0;
	if (map->width > map->height)
		factor = map->height;
	else if (map->width < map->height)
		factor = map->width;
	else if (map->width == map->height)
		factor = map->width;
	map->tile_size = WINDOW_WIDTH / factor;
	data->buttons->minimap = false;
	map->tile_size = 128;
	// if (map->tile_size < 4)
	// {
	// 	map->tile_size = 128;
	// 	data->buttons->minimap = false;
	// }
	fprintf(stderr, "TILE_SIZE: %d\n", map->tile_size);
}
