/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/14 13:59:46 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"
#include "../../inc/raycasting.h"

// REMOVE
// static int	get_texture_pixel(void *img, int x, int y)
// {
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// 	char	*addr;
// 	char	*dst;
// 	int		color;

// 	addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
// 	dst = addr + (y * size_line + x * (bits_per_pixel / 8));
// 	color = *(unsigned int *)dst;
// 	return (color);
// }

// USE THIS
// int	get_pixel_colour(t_image *image, int x, int y)
// {
// 	char	*add;
// 	int		ll;
// 	int		bpp;
// 	char	*dst;

// 	add = image->address;
// 	ll = image->line_length;
// 	bpp = image->bits_per_pixel;
// 	dst = add + (y * ll + x * (bpp / 8));
// 	return (*(unsigned int *)dst);
// }

void	draw_wall(t_data *data, t_element *elements, t_ray *ray, double i)
{
	int		j;
	int		x;
	double	y;
	int		pixel;

	j = ray->draw_start;
	x = ray->line_position;
	y = ray->line_height_start;
	pixel = 0;
	while (j < ray->draw_end)
	{
		if (ray->colour == NORTH)
			pixel = get_pixel_colour(elements[NORTH].texture, (int)x, (int)y);
		else if (ray->colour == SOUTH)
			pixel = get_pixel_colour(elements[SOUTH].texture, (int)x, (int)y);
		else if (ray->colour == WEST)
			pixel = get_pixel_colour(elements[WEST].texture, (int)x, (int)y);
		else if (ray->colour == EAST)
			pixel = get_pixel_colour(elements[EAST].texture, (int)x, (int)y);
		if (pixel)
			draw_pixel(data->window->screen, i, j, pixel);
		y += ray->line_step;
		j++;
	}
}
