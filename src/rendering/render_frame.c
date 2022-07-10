/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/08 19:18:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_player(t_data *data, t_image *image, double x, double y)
{
	int	i;
	int	j;
	double	ang_rad;

	ang_rad = data->player->rotation * 3.14159 / 180;
	i = 0;
	j = 0;
	while (i < 40)
	{
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0x00FF0000);
		i++;
	}
	while (i > 30)
	{
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (j)), 0x00FF0000);
		draw_pixel(image, x + cos(ang_rad) * (i) - sin(ang_rad) * (-j),
			y - (sin(ang_rad) * (i) + cos(ang_rad) * (-j)), 0x00FF0000);
		j++;
		i--;
	}
}

static char	*get_data_address(t_image *image)
{
	int		*bits_p_pixel;
	int		*line_length;
	int		*endian;
	char	*address;

	bits_p_pixel = &image->bits_per_pixel;
	line_length = &image->line_length;
	endian = &image->endian;
	address = mlx_get_data_addr(image->pointer, bits_p_pixel, line_length, endian);
	return (address);
}

void	render_frame(t_data *data, void *mlx, t_image *screen)
{
	if (screen->pointer)
		mlx_destroy_image(mlx, screen->pointer);
	screen->pointer = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	screen->address = get_data_address(screen);
	draw_minimap(data, screen);
	draw_player(data, screen, data->player->x, data->player->y);
	mlx_put_image_to_window(mlx, data->window->pointer, screen->pointer, 0, 0);
}
