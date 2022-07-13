/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:35:36 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 16:46:14 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static int	skip_empty_lines(char **cub_file, int pos)
{
	int	len;

	while (cub_file[pos])
	{
		len = ft_strlen(cub_file[pos]);
		if (len > 0)
			break ;
		pos++;
	}
	return (pos);
}

void	parse_map(t_data *data, t_map *map, int pos)
{
	int	map_start;

	map_start = skip_empty_lines(map->cub, pos);
	if (!map->cub[map_start])
		exit_with_error(MAP_EMPTY);
	set_dimensions(map, map->cub, map_start);
	set_tile_size(data, map);
	map->grid = create_tile_grid(map);
	set_tile_grid(map, map->cub, map_start);
	check_grid_borders(map, map->grid);
	set_player_position(data, map, map->grid);
}
