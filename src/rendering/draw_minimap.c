/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 13:53:08 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static int	pick_colour(void)
{
	static int	i = 0;
	int			colour;

	if (i < 1000)
		colour = 0xf1c937;
	else if (1000 <= i && i < 2000)
		colour = 0x00babc;
	else if (2000 <= i && i < 3000)
		colour = 0xf1c937;
	else if (3000 <= i && i < 4000)
		colour = 0xd101c0;
	i++;
	if (i == 4000)
		i = 0;
	return (colour);
}

void	draw_minimap(t_data *data, t_map *map, t_player *player, t_image *image)
{
	int		minimap_size;
	int		factor;
	double	i_start;
	double	j_start;
	double	step_size;
	


	minimap_size = 225;
	factor = 9;
	i_start = player->x / 128 - factor / 2 - 1;
	j_start = player->y / 128 - factor / 2 - 1;
	step_size = 1.0 * factor / minimap_size;
	

	// fprintf(stderr, "MAP	%d\n", minimap_size);
	// fprintf(stderr, "FACTOR	%d\n", factor);
	// fprintf(stderr, "START	%f %f\n", i_start, j_start);
	// fprintf(stderr, "PLAYER	%f %f\n", data->player->x / 128, data->player->y / 128);
	// fprintf(stderr, "END	%f %f\n", i_start + factor, j_start + factor);
	// fprintf(stderr, "STEP	%f\n", step_size);

	int	i;
	int	j;
	int colour;
	i = 0;
	while (i < minimap_size)
	{
		j = 0;
		j_start = data->player->y / 128 - factor / 2 - 1;
		while (j < minimap_size)
		{
			if (i_start < 0 || j_start < 0)
				draw_pixel(image, i, j, 0x0a0a0a);
			else if (i_start >= 1.0 * data->map->width || j_start >= 1.0 * data->map->height)
			{
				draw_pixel(image, i, j, 0x0a0a0a);
			}
			else
			{
				if (data->map->grid[(int)i_start][(int)j_start].id == '1' || data->map->grid[(int)i_start][(int)j_start].id == ' ')
				{
					if (data->map->grid[(int)i_start][(int)j_start].vision)
					{
						colour = pick_colour();
						draw_pixel(image, i, j, colour);
					}
				}
				else
					draw_pixel(image, i, j, 0x18191a);
			}
			j_start += step_size;
			j++;
		}
		i_start += step_size;
		i++;
	}
	draw_player(data, image, 125.0, 125.0);

	// RESET VISION;
	for (int i = 0; i < data->map->width; i++)
	{
		for (int j = 0; j < data->map->height; j++)
			data->map->grid[i][j].vision = false;
	}
}
