/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 21:00:32 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_map(t_data *data, t_image *image)
{
	int	colour;
	int	j;
	int	i;

	colour = 0;
	i = 0;
	while (i < data->map->width)
	{
		j = 0;
		while (j < data->map->height)
		{
			if (data->map->grid[i][j].id == '1' || data->map->grid[i][j].id == ' ')
			{
				colour = 0x0A0A0A;
				draw_square(image, data->map->tile_size, i, j, colour);
			}
			else if (data->map->grid[i][j].id != '1')
			{
				colour = 0x18191A;
				draw_square(image, data->map->tile_size, i, j, colour);
			}
			j++;
		}
		i++;
	}
}
