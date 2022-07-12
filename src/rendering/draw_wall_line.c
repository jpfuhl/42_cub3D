/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:19:51 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/12 16:07:10 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"
#include "../../inc/raycasting.h"

static int	get_texture_pixel(void *img, int x, int y)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	char	*dst;
	int		color;

	addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	//printf("size_line: %d, bits_per_pixel: %d, len_addr: %zu\n", size_line, bits_per_pixel, ft_strlen(addr));
	dst = addr + (y * size_line + x * (bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	draw_wall_line(t_data *data, t_element *elements, t_ray *ray, double i)
{
	// it segfaults and i dont know why yet
	int		j;
	int		x;
	double	y;
	int		pixel = 0;

	j = ray->draw_start;
	x = ray->line_position;
	y = ray->line_height_start;
	while (j < ray->draw_end)
	{
		if (ray->colour == NORTH)
			pixel = get_texture_pixel(elements[NORTH].texture->pointer, (int)x, (int)y);
		else if (ray->colour == SOUTH)
			pixel = get_texture_pixel(elements[SOUTH].texture->pointer, (int)x, (int)y);
		else if (ray->colour == WEST)
			pixel = get_texture_pixel(elements[WEST].texture->pointer, (int)x, (int)y);
		else if (ray->colour == EAST)
			pixel = get_texture_pixel(elements[EAST].texture->pointer, (int)x, (int)y);
		if (pixel)
			draw_pixel(data->window->screen, i, j, pixel);
		y += ray->line_step;
		j++;
	}
}


// void	draw_wall(t_data *data, double factor, t_ray *ray)
// {
// 	//printf("DRAW_CALL WAS CALLED, dx: %f, ray->line_height : %d\n", dx, ray->line_height);
// 	int		texture_height;
// 	int		texture_width;

// 	texture_height = 128;
// 	texture_width = 128;
// 	double step = 1.0 * texture_height / ray->line_height;
// 	double factor_j;
// 	factor_j = 0;

// 	int	tile = data->map->tile_size;
// 	if (ray->line_height > data->window->height)
// 	{
// 		factor_j = (1.0 * texture_height / 2.0) - ((1.0 * texture_height / 2.0 ) / ((1.0 * ray->line_height) / (1.0 * data->window->height)));
// 		// printf("half: %f, fac : %f, factor_j: %f\n", 1.0 * texture_height / 2.0, ((1.0 * ray->line_height) / (1.0 * data->window->height)), factor_j);
// 		//factor_j = texture_height / 3;
// 		ray->line_height = data->window->height;
// 	}
// 	int drawStart = -ray->line_height / 2 + data->window->height / 2;
// 	int drawEnd = ray->line_height / 2 + data->window->height / 2;
// 	int j;

		

// 	double	factor_x;
// 	double	cut;
// 	double	round;
// 	double	factor_m;
// 	int		pixel = 0;

// 	if (ray->axis == 0)
// 	{
// 		cut = ray->intersection.y / data->map->tile_size;
// 		round = cut - (int)cut;
// 		factor_x = texture_width * round;
// 	}
// 	else if (ray->axis == 1)
// 	{
// 		cut = ray->intersection.x / data->map->tile_size;
// 		round = cut - (int)cut;
// 		factor_x = texture_width * round;
// 	}

// 	// fprintf(stderr, "%f %f %f %d %d %d\n", dx, factor_j, step, (int)(factor_j + step), (int)factor_x, texture_height);
// 	j = drawStart;
// 	int colour = NORTH;
// 	while (j < drawEnd)
// 	{
// 		if (colour == NORTH)
// 			pixel = get_texture_pixel(data->map->elements[NORTH].texture->pointer, (int)factor_x, (int)factor_j);
// 		else if (colour == SOUTH)
// 			pixel = get_texture_pixel(data->map->elements[SOUTH].texture->pointer, (int)factor_x, (int)factor_j);
// 		else if (colour == EAST)
// 			pixel = get_texture_pixel(data->map->elements[EAST].texture->pointer, (int)factor_x, (int)factor_j);
// 		else if (colour == WEST)
// 			pixel = get_texture_pixel(data->map->elements[WEST].texture->pointer, (int)factor_x, (int)factor_j);
// 		if (pixel)
// 		{
// 			draw_pixel(data->window->screen, (int)factor, j, pixel);
// 		}
// 		// else
// 		// my_mlx_pixel_put(info->img3d, dx, j, colour);
// 		factor_j += step;
// 		j++;
// 	}
// }
