/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:51:17 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 15:16:18 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_square(t_image *image, int tile_size, int dx, int dy, int color)
{
	int	i;
	int	j;

	j = 0 + dy * tile_size;
	while (j < tile_size + dy * tile_size)
	{
		i = 0 + dx * tile_size;
		while (i < tile_size + dx * tile_size)
		{
			draw_pixel(image, i, j, color);
			i++;
		}
		j++;
	}
}
