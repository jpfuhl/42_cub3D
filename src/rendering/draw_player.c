/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 18:25:15 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

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
}
