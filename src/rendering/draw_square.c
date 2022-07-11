/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:51:17 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 20:51:35 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_square(t_image *image, int tile_size, int dx, int dy, int color)
{
	int	i;
	int	j;

	j = 1 + dy * tile_size;
	while (j < tile_size - 1 + dy * tile_size)
	{
		i = 1 + dx * tile_size;
		while (i < tile_size - 1 + dx * tile_size)
		{
			draw_pixel(image, i, j, color);
			i++;
		}
		j++;
	}
}
