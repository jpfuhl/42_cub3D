/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:23:48 by arendon-          #+#    #+#             */
/*   Updated: 2022/07/11 21:51:13 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

int	dda_algorithm_punk(t_data *data, double player_x, double player_y, t_xy p2)
{
	double	dif_x;
	double	dif_y;
	int		steps;
	int		i;

	dif_x = p2.x - player_x;
	dif_y = p2.y - player_y;
	if (fabs(dif_x) > fabs(dif_y))
		steps = fabs(dif_x);
	else
		steps = fabs(dif_y);
	i = 1;
	while (i < steps)
	{
		if (i % 6 == 0)
			color_point(data, player_x, player_y, i);
		player_x = player_x + (dif_x / steps);
		player_y = player_y + (dif_y / steps);
		i++;
	}
	return (0);
}

void color_point(t_data *data, double x, double y, int i)
{
	if (i % 12 == 0)
		my_mlx_pixel_put(data->window->screen, x, y, 0xf1c937);
	else if (i % 18 == 0)
		my_mlx_pixel_put(data->window->screen, x, y, 0xd101c0);
	else
		my_mlx_pixel_put(data->window->screen, x, y, 0x00babc);
}