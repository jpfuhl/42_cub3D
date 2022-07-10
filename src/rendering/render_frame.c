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



void	render_frame(t_data *data, t_window *window, void *mlx, t_image *screen)
{
	create_image(data, &windowscreen, WINDOW_WIDTH, WINDOW_HEIGHT);
	create_image(data, &window->map,)
	draw_minimap(data, screen);
	draw_player(data, screen, data->player->x, data->player->y);
	mlx_put_image_to_window(mlx, data->window->pointer, screen->pointer, 0, 0);
}
