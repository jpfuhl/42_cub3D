/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 14:40:46 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_map(t_map *map, t_image *image) //this funtion is not used
{
	int	colour;
	int	j;
	int	i;

	colour = 0;
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->grid[i][j].id == '1' || map->grid[i][j].id == ' ')
			{
				colour = 0x0A0A0A;
				draw_square(image, map->tile_size, i, j, colour);
			}
			else if (map->grid[i][j].id != '1')
			{
				colour = 0x18191A;
				draw_square(image, map->tile_size, i, j, colour);
			}
			j++;
		}
		i++;
	}
}
