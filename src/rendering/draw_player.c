/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 19:04:23 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static void	draw_vision(t_data *data, t_player *player, double x, double y)
{
	int	i;
	int	j;
	double	ang_rad;

	ang_rad = -player->rotation * PI / 180;
	j = 0;
	while (j <= 30)
	{
		i = 0;
		while (i < 30)
		{
			draw_pixel(data->window->map, x + cos(ang_rad + j * PI / 180) * (i) - sin(ang_rad + j * PI / 180) * 0,
				y + sin(ang_rad + j * PI / 180) * (i) + cos(ang_rad + j * PI / 180) * 0, 0x00D5FF);
			draw_pixel(data->window->map, x + cos(ang_rad - j * PI / 180) * (i) - sin(ang_rad - j * PI / 180) * 0,
				y + sin(ang_rad - j * PI / 180) * (i) + cos(ang_rad - j * PI / 180) * 0, 0x00D5FF);
			i++;
		}
		j += 2;
	}
}

void	draw_player(t_data *data, t_image *image, double x, double y)
{
	int	factor;
	int	i;
	int	j;

	factor = -3;
	j = 0;
	while (j < 7)
	{
		i = 0;
		while (i < 7)
		{
			draw_pixel(image, x + factor + i, y + factor + j, 0xf1c937);
			i++;
		}
		j++;
	}
	draw_vision(data, data->player, x, y);
}
