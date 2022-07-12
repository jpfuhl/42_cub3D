/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:58:24 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 17:36:32 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	set_tile_size(t_map *map)
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
	if (map->tile_size < 2)
		map->tile_size = 2;
	fprintf(stderr, "TILE_SIZE: %d\n", map->tile_size);
}
