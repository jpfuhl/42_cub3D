/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 20:43:01 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_minimap_new(t_data *data, t_image *image)
{
	int		minimap_size;
	int		factor;
	double	i_start;
	double	j_start;
	double	step_size;
	


	minimap_size = 225;
	factor = 9;
	i_start = data->player->x / 128 - factor / 2 - 1;
	j_start = data->player->y / 128 - factor / 2 - 1;
	step_size = 1.0 * factor / minimap_size;
	

	// fprintf(stderr, "MAP	%d\n", minimap_size);
	// fprintf(stderr, "FACTOR	%d\n", factor);
	// fprintf(stderr, "START	%f %f\n", i_start, j_start);
	// fprintf(stderr, "PLAYER	%f %f\n", data->player->x / 128, data->player->y / 128);
	// fprintf(stderr, "END	%f %f\n", i_start + factor, j_start + factor);
	// fprintf(stderr, "STEP	%f\n", step_size);

	int	i;
	int	j;

	i = 0;
	while (i < minimap_size)
	{
		j = 0;
		j_start = data->player->y / 128 - factor / 2 - 1;
		while (j < minimap_size)
		{
			if (i_start < 0 || j_start < 0)
				draw_pixel(image, i, j, 0xff0000);
			else if (i_start >= 1.0 * data->map->width || j_start >= 1.0 * data->map->height)
			{
				draw_pixel(image, i, j, 0xff0000);
			}
			else
			{
				if (data->map->grid[(int)i_start][(int)j_start].id == '1' || data->map->grid[(int)i_start][(int)j_start].id == ' ')
				{
					if (data->map->grid[(int)i_start][(int)j_start].vision)
					{
						// disco_wall(data, i, j);
						draw_pixel(image, i, j, 0xd101c0);
					}
					else
						draw_pixel(image, i, j, 0xffffff);
				}
				else if (data->map->grid[(int)i_start][(int)j_start].id == '0')
					draw_pixel(image, i, j, 0x18191a);
			}
			j_start += step_size;
			j++;
		}
		i_start += step_size;
		i++;
	}
	// draw_player(data, image, 25.0 * 5 + px, 25.0 * 5 + py);

	// RESET VISION;
	for (int i = 0; i < data->map->width; i++)
	{
		for (int j = 0; j < data->map->height; j++)
			data->map->grid[i][j].vision = false;
	}
}
