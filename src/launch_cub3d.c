/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:08:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/06 18:23:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	clean_destroy(t_data *data)
{
	free_data(data);
	exit (0);
	return (0);
}

static void	initialize_engine(t_data *data)
{
	int		width;
	int		height;
	char	*name;

	data->mlx = mlx_init();
	data->window->width = W_WIDTH;
	data->window->height = W_HEIGHT;
	width = data->window->width;
	height = data->window->height;
	name = "CUB3D ʕ·͡ᴥ·ʔ";
	data->window->ptr = mlx_new_window(data->mlx, width, height, name);
}

int	launch_cub3d(t_data *data)
{
	initialize_engine(data);
	render_frame(data, data->window->img3d);
	mlx_key_hook(data->window->ptr, movement, data);
	mlx_hook(data->window->ptr, 17, 0, clean_destroy, data);
	mlx_loop(data->mlx);
	return (0);
}
