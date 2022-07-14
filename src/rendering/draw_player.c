/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 17:32:31 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

static void	draw_vision(t_data *data, t_player *player, double x, double y)
{
	int		i;
	int		j;
	double	ang_rad;
	t_image	*img;

	ang_rad = -player->rotation * PI / 180;
	img = data->window->minimap;
	j = 0;
	while (j <= 41)
	{
		i = 0;
		while (i < 20)
		{
			draw_pixel(img, x + cos(ang_rad + j * PI / 180) * (i)
				- sin(ang_rad + j * PI / 180) * 0,
				y + sin(ang_rad + j * PI / 180) * (i)
				+ cos(ang_rad + j * PI / 180) * 0, 0x2b2d2e);
			draw_pixel(img, x + cos(ang_rad - j * PI / 180) * (i)
				- sin(ang_rad - j * PI / 180) * 0,
				y + sin(ang_rad - j * PI / 180) * (i)
				+ cos(ang_rad - j * PI / 180) * 0, 0x2b2d2e);
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

	factor = -2;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			draw_pixel(image, x + factor + i, y + factor + j, 0xf1c937);
			i++;
		}
		j++;
	}
	draw_vision(data, data->player, x, y);
}
