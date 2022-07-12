/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:53:15 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 11:14:03 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rendering.h"

int	get_pixel_colour(t_image *image, int x, int y)
{
	char	*add;
	int		ll;
	int		bpp;
	char	*dst;

	add = image->address;
	ll = image->line_length;
	bpp = image->bits_per_pixel;
	dst = add + (y * ll + x * (bpp / 8));
	return (*(unsigned int *)dst);
}

int	get_pixel_from_source(t_image *dst, t_image *src, int x, int y)
{
	int		colour;
	double	scale_x;
	double	scale_y;

	scale_x = x * (1.0 * src->width / dst->width);
	scale_y = y * (1.0 * src->height / dst->height);
	colour = get_pixel_colour(src, (int)scale_x, (int)scale_y);
	return (colour);
}

void	resize_image(t_image *destination, t_image *source)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < destination->height)
	{
		x = 0;
		while (x < destination->width)
		{
			colour = get_pixel_from_source(destination, source, x, y);
			if (colour)
				draw_pixel(destination, x, y, colour);
			x++;
		}
		y++;
	}
}
