/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 18:40:49 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_minimap_new(t_data *data, t_image *image)
{
	int	colour;
	int	count;
	int	j;
	int	i;


	int factor = -4;
	int pi_start = data->player->i + factor;
	int pj_start = data->player->j + factor;
	fprintf(stderr, "Player %d %d\n", data->player->i, data->player->j);
	fprintf(stderr, "MAP!	%d %d\n", data->player->i - 7, data->player->j - 7);
	colour = 0;
	i = 0;
	count = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (pi_start + i < 0 || pj_start + j < 0)
				draw_square(image, 25, i, j, 0x0a0a0a);
			else if (pi_start + i >= data->map->width || pj_start + j >= data->map->height)
				draw_square(image, 25, i, j, 0x0a0a0a);
			else
			{
				if (data->map->grid[pi_start + i][pj_start + j].id == '1' || data->map->grid[pi_start + i][pj_start + j].id == ' ')
				{
					if (data->map->grid[pi_start + i][pj_start + j].vision)
					{
						disco_wall(data, i, j);
						data->map->grid[pi_start + i][pj_start + j].vision = false;
					}
					else
						draw_square(image, 25, i, j, 0x0a0a0a);
				}
				else if (data->map->grid[pi_start + i][pj_start + j].id == '0')
					draw_square(image, 25, i, j, 0x18191a);
			}
			j++;
		}
		i++;
	}
	fprintf(stderr, "Player %f %f\n", data->player->x / 128, data->player->y / 128);
	double px = data->player->x / 128 - data->player->i;
	double py = data->player->y / 128 - data->player->j;
	draw_player(data, image, 25.0 * 5 + px, 25.0 * 5 + py);
}
