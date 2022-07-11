/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:20:22 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/11 19:20:24 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

char	*get_data_address(t_image *image)
{
	int		*bpp;
	int		*ll;
	int		*end;
	char	*add;

	bpp = &image->bits_per_pixel;
	ll = &image->line_length;
	end = &image->endian;
	add = mlx_get_data_addr(image->pointer, bpp, ll, end);
	return (add);
}

void	create_image(t_data *data, t_image **image, int width, int height)
{
	if ((*image)->pointer)
		mlx_destroy_image(data->mlx, (*image)->pointer);
	(*image)->pointer = mlx_new_image(data->mlx, width, height);
	(*image)->address = get_data_address(*image);
	(*image)->width = width;
	(*image)->height = height;
}
