/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:07 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 19:20:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_pixel(t_image *image, int x, int y, int colour)
{
	char	*add;
	int		ll;
	int		bpp;
	char	*dst;

	add = image->address;
	ll = image->line_length;
	bpp = image->bits_per_pixel;
	dst = add + (y * ll + x * (bpp / 8));
	*(unsigned int *)dst = colour;
}
