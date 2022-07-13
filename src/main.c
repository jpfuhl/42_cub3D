/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:21:17 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/07/13 16:43:27 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	launch_cub3d(t_data *data, void *mlx, t_window *window)
{
	render_frame(data, data->window, data->mlx);
	keyhooks(data, window, mlx);
	mlx_loop(mlx);
}

static void	initialize_cub3d(void *mlx, t_window *window)
{
	char	*name;

	window->width = WINDOW_WIDTH;
	window->height = WINDOW_HEIGHT;
	name = "cub3D";
	window->pointer = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, name);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		exit_with_error(ARGV_ERROR);
	data = create_data();
	data->mlx = mlx_init();
	launch_parser(data, data->map, argv[1]);
	initialize_cub3d(data->mlx, data->window);
	launch_cub3d(data, data->mlx, data->window);
	free_data(data);
	return (0);
}
