/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:36:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 14:33:47 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rendering.h"

void	draw_background(t_image *image, t_element *elements)
{
	int	colour;
	int	i;
	int	j;

	j = 0;
	colour = elements[CEILING].colour;
	while (j < image->height)
	{
		i = 0;
		if (j == image->height / 2)
			colour = elements[FLOOR].colour;
		while (i < image->width)
		{
			draw_pixel(image, i, j, colour);
			i++;
		}
		j++;
	}
}
