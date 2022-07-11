/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:36:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 17:47:03 by jpfuhl           ###   ########.fr       */
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
