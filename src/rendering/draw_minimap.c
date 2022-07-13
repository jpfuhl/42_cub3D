/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 17:38:04 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_minimap_new(t_data *data, t_image *image)
{
	int	colour;
	int	count;
	int	j;
	int	i;

	fprintf(stderr, "Player %d %d\n", data->player->i, data->player->j);
	fprintf(stderr, "MAP!	%d %d\n", data->player->i - 7, data->player->j - 7);
	colour = 0;
	i = 0;
	count = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			if (count % 2)
			{
				colour = 0x000000;
				draw_square(image, 15, i, j, colour);
			}
			else
			{
				colour = 0xf1c937;
				draw_square(image, 15, i, j, colour);
			}
			count++;
			j++;
		}
		i++;
	}
}
