/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 21:05:51 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_player(t_data *data, t_image *image, double x, double y)
{
	int		i;
	int		j;
	double	ang_rad;

	ang_rad = data->player->rotation * 3.14159 / 180;
	i = 0;
	j = 0;
	while (i < 1)
	{
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0xFFFFFF);
		i++;
	}
	// while (i > 30)
	// {
	// 	draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
	// 		y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0xFFFFFF);
	// 	draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (-j),
	// 		y - (sin(ang_rad) * (i) + cos(ang_rad) * (-j)), 0xFFFFFF);
	// 	j++;
	// 	i--;
	// }
}
